#include <bits/stdc++.h>
using namespace std;
char ans[10][10];
vector<pair<int, int>> indices;
bool findMatch(char board[][10], string word, int x, int y, int nrow, int ncol, int level)
{
    int l = word.length();
    if (level == l)
    {
        return true;
    }
    if (x < 0 || y < 0 || x >= nrow || y >= ncol)
    {
        return false;
    }
    if (word[level] == board[x][y])
    {
        char temp = word[level];
        board[x][y] = '#';
        indices.push_back(make_pair(x, y));
        bool res = findMatch(board, word, x - 1, y, nrow, ncol, level + 1) || findMatch(board, word, x + 1, y, nrow, ncol, level + 1) || findMatch(board, word, x, y - 1, nrow, ncol, level + 1) || findMatch(board, word, x, y + 1, nrow, ncol, level + 1) || findMatch(board, word, x+1, y + 1, nrow, ncol, level + 1) || findMatch(board, word, x-1, y-1, nrow, ncol, level + 1) || findMatch(board, word, x+1, y-1, nrow, ncol, level + 1) || findMatch(board, word, x-1, y + 1, nrow, ncol, level + 1);

        if (res == false)
            indices.pop_back();

        board[x][y] = temp;

        return res;
    }

    return false;
}
void checkMatch(char board[][10], vector<string> words, int nrow, int ncol)
{

    for (int k = 0; k < words.size(); k++)
    {
        int flag = 0;
        for (int i = 0; i < nrow; i++)
        {
            for (int j = 0; j < ncol; j++)
            {
                if (board[i][j] == words[k][0])
                {
                    if (findMatch(board, words[k], i, j, nrow, ncol, 0))
                    {
                        flag = 1;
                        break;
                    }
                }
            }
            if (flag == 1)
                break;
        }
        for (int m = 0; m < indices.size(); m++)
        {
            int x = indices[m].first;
            int y = indices[m].second;
            ans[x][y] = words[k][m];
        }
        indices.clear();
    }
}
void design()
{
    cout << "\n\t\t*WELCOME TO WORD SEARCH GAME.*\n\nImplemented using BACKTRACKING\n\nLanguage Used: C++\n\n\t\tMADE BY: \n\nAditya Yadav 20103063\nAyush Mittal 20103073\nIshan Chaudhary 20103059\nSiddharth Visen 20103080\n\n\n";
}
int main()
{
    design();
    char board[10][10] = {
        {'O', 'M', 'E', 'T', 'Q', 'L', 'R', 'T', 'Z', 'W'},
        {'F', 'I', 'G', 'H', 'T', 'E', 'R', 'H', 'J', 'A'},
        {'Z', 'S', 'H', 'S', 'N', 'J', 'O', 'V', 'D', 'Q'},
        {'I', 'L', 'H', 'N', 'Z', 'U', 'N', 'P', 'S', 'M'},
        {'R', 'U', 'N', 'P', 'G', 'Q', 'A', 'K', 'C', 'O'},
        {'A', 'R', 'E', 'V', 'A', 'S', 'C', 'X', 'L', 'D'},
        {'C', 'S', 'F', 'F', 'S', 'N', 'L', 'W', 'V', 'U'},
        {'E', 'E', 'M', 'R', 'P', 'A', 'O', 'X', 'L', 'L'},
        {'S', 'U', 'P', 'A', 'Q', 'R', 'V', 'A', 'A', 'E'},
        {'Q', 'C', 'T', 'C', 'L', 'A', 'S', 'S', 'E', 'S'}
        };

    char board2[10][10] = {
        {'R', 'Y', 'R', 'A', 'H', 'D', 'U', 'A', 'H', 'C'},
        {'H', 'Q', 'Z', 'O', 'C', 'H', 'O', 'V', 'F', 'A'},
        {'T', 'Z', 'A', 'Q', 'N', 'T', 'Q', 'L', 'E', 'Y'},
        {'R', 'F', 'D', 'O', 'A', 'K', 'E', 'J', 'M', 'U'},
        {'A', 'Y', 'I', 'A', 'H', 'A', 'K', 'Y', 'R', 'S'},
        {'H', 'H', 'T', 'A', 'S', 'H', 'A', 'Z', 'N', 'H'},
        {'D', 'S', 'Y', 'T', 'I', 'D', 'X', 'L', 'U', 'A'},
        {'D', 'A', 'A', 'G', 'A', 'H', 'J', 'Y', 'Z', 'B'},
        {'I', 'E', 'J', 'V', 'R', 'I', 'O', 'D', 'V', 'Q'},
        {'S', 'B', 'K', 'E', 'T', 'O', 'A', 'Z', 'V', 'K'}
        };
    char board3[10][10] = {
        {'J', 'R', 'E', 'M', 'P', 'T', 'D', 'M', 'D', 'J'},
        {'T', 'U', 'D', 'N', 'J', 'Z', 'H', 'A', 'N', 'R'},
        {'T', 'K', 'O', 'E', 'L', 'E', 'P', 'D', 'E', 'N'},
        {'B', 'E', 'T', 'J', 'K', 'G', 'I', 'F', 'G', 'S'},
        {'N', 'P', 'M', 'U', 'I', 'L', 'E', 'H', 'Y', 'R'},
        {'N', 'M', 'N', 'O', 'G', 'O', 'A', 'Y', 'X', 'S'},
        {'S', 'U', 'L', 'P', 'H', 'U', 'R', 'S', 'O', 'S'},
        {'D', 'W', 'A', 'S', 'R', 'J', 'W', 'K', 'O', 'L'},
        {'Y', 'F', 'A', 'P', 'I', 'B', 'W', 'F', 'X', 'L'},
        {'B', 'J', 'R', 'B', 'T', 'X', 'D', 'H', 'U', 'M'}
        };

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            ans[i][j] = '*';

    cout << "MATRIX 1: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\n";
        for (int j = 0; j < 10; j++)
            cout << board[i][j] << "      ";
    }

    cout << "\nMATRIX 2: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\n";
        for (int j = 0; j < 10; j++)
            cout << board2[i][j] << "      ";
    }

    cout << "\nMATRIX 3: \n";
    for (int i = 0; i < 10; i++)
    {
        cout << "\n";
        for (int j = 0; j < 10; j++)
            cout << board3[i][j] << "      ";
    }
    vector<string> words;
        words.push_back("CLASSES");
        words.push_back("MODULE");
        words.push_back("RUN");
        words.push_back("RACE");
        words.push_back("FIGHTER");
        words.push_back("VOLCANO");

    vector<string> words2;
        words2.push_back("ISHAN");
        words2.push_back("ADITYA");
        words2.push_back("AYUSH");
        words2.push_back("SIDDHARTH");
        words2.push_back("CHAUDHARY");
        words2.push_back("YADAV");

    vector<string> words3;
        words3.push_back("OXYGEN");
        words3.push_back("SULPHUR");
        words3.push_back("NEON");

        words3.push_back("HELIUM");
    int ch;
    cout<< "\nChoose your Matrix (Enter 1,2 or 3): ";
    cin>>ch;

    switch(ch)
    {
    case 1:


        cout << "\n\n\nList of Words\n\n";
        for (int i = 0; i < 6; i++)
            cout << words[i] << "\n";
        checkMatch(board, words, 10, 10);

        break;

    case 2:


        cout << "\n\n\nList of Words\n\n";
        for (int i = 0; i < 6; i++)
            cout << words2[i] << "\n";
        checkMatch(board2, words2, 10, 10);

        break;

    case 3:


        cout << "\n\n\nList of Words\n\n";
        for (int i = 0; i < 4; i++)
            cout << words3[i] << "\n";
        checkMatch(board3, words3, 10, 10);

        break;
    }

    cout << "\nFinal MATRIX\n\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << ans[i][j] << "      ";
        }
        cout << endl;
    }
    return 0;
}