#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair


const int N = 4;

void solve(int test)
{
    string s[N];
    for (int i = 0; i < N; ++i)
        cin >> s[i];

    bool winX = false;
    bool winO = false;
    int filled = 0;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (s[i][j] != '.')
                filled++;

    //horizontal
    for (int i = 0; i < N; ++i)
    {
        string t = s[i];
        for (int j = 0; j < N; ++j)
            if (t[j] == 'T')
                t[j] = 'X';
        if (t == "XXXX")
            winX = true;
    }
    for (int i = 0; i < N; ++i)
    {
        string t = s[i];
        for (int j = 0; j < N; ++j)
            if (t[j] == 'T')
                t[j] = 'O';
        if (t == "OOOO")
            winO = true;
    }

    //vertical
    for (int i = 0; i < N; ++i)
    {
        string t = "";
        t += s[0][i];
        t += s[1][i];
        t += s[2][i];
        t += s[3][i];
        for (int j = 0; j < N; ++j)
            if (t[j] == 'T')
                t[j] = 'X';
        if (t == "XXXX")
            winX = true;
    }
    for (int i = 0; i < N; ++i)
    {
        string t = "";
        t += s[0][i];
        t += s[1][i];
        t += s[2][i];
        t += s[3][i];
        for (int j = 0; j < N; ++j)
            if (t[j] == 'T')
                t[j] = 'O';
        if (t == "OOOO")
            winO = true;
    }

    //main diagonal
    string t = "";
    t += s[0][0];
    t += s[1][1];
    t += s[2][2];
    t += s[3][3];
    for (int j = 0; j < N; ++j)
        if (t[j] == 'T')
            t[j] = 'X';
    if (t == "XXXX")
        winX = true;
    t = "";
    t += s[0][0];
    t += s[1][1];
    t += s[2][2];
    t += s[3][3];
    for (int j = 0; j < N; ++j)
        if (t[j] == 'T')
            t[j] = 'O';
    if (t == "OOOO")
        winO = true;

    //one more diagonal
    t = "";
    t += s[0][3];
    t += s[1][2];
    t += s[2][1];
    t += s[3][0];
    for (int j = 0; j < N; ++j)
        if (t[j] == 'T')
            t[j] = 'X';
    if (t == "XXXX")
        winX = true;
    t = "";
    t += s[0][3];
    t += s[1][2];
    t += s[2][1];
    t += s[3][0];
    for (int j = 0; j < N; ++j)
        if (t[j] == 'T')
            t[j] = 'O';
    if (t == "OOOO")
        winO = true;

    cout << "Case #" << test << ": ";
    if (winX)
    {
        cout << "X won" << endl;
    }
    if (winO)
    {
        cout << "O won" << endl;
    }
    if (!winX && !winO)
    {
        cout << (filled == 16 ? "Draw" : "Game has not completed") << endl;
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int test;
    cin >> test;
    for (int i = 1; i <= test; ++i)
        solve(i);

    return 0;
}
