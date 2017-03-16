/*************************************************************************
    > File Name: jam03.cpp
    > Author: Guo Hengkai
    > Created Time: 2015/4/11 15:00:50
 ************************************************************************/

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const string PROG = "C-large";
FILE *fin, *fout;

const int R[5][5] = {
    { 0, 0, 0, 0, 0 },
    { 0, 1, 2, 3, 4 },
    { 0, 2, -1, 4, -3 },
    { 0, 3, -4, -1, 2 },
    { 0, 4, 3, -2, -1 }
};

int T;
int L;
long long X;
int S[10001];
int pos_str;
int pos_substr;
bool ans;

int sign(int x)
{
    if (x == 0)
        return 0;
    else if (x > 0)
        return 1;
    else
        return -1;
}

int merge(int lhs, int rhs)
{
    // The rhs is always positive
    return sign(lhs) * R[abs(lhs)][rhs];
}

bool walk(int target, int begin_str, int begin_substr)
{
    if (begin_str >= X)
        return (target == 1);
    int current = S[begin_substr];
    while ((current != target) || (target == 1))
    {
        ++pos_substr;
        if (pos_substr == L)
        {
            ++pos_str;
            pos_substr = 0;
            if ((pos_str == X) || (target == 1 && (X - pos_str) % 4 == 0))
            // if (pos_str == X)
            {
                return (target == 1 && current == 1);
            }
        }
        if (pos_substr == begin_substr && pos_str == begin_str + 4)
            return false;
        current = merge(current, S[pos_substr]);
    }


    ++pos_substr;
    if (pos_substr == L)
    {
        ++pos_str;
        pos_substr = 0;
    }
    return (target == current);
}

void solve()
{
    pos_str = pos_substr = 0;
    ans = walk(2, pos_str, pos_substr);  // Find i
    if (!ans)
    {
        return;
    }
    ans = walk(3, pos_str, pos_substr);  // Find j
    if (!ans)
    {
        return;
    }
    ans = walk(4, pos_str, pos_substr);  // Find k
    if (!ans)
    {
        return;
    }
    ans = walk(1, pos_str, pos_substr);  // Check the rest equal to one
}

int main()
{
    fin = fopen((PROG + ".in").c_str(), "r");
    fout = fopen((PROG + ".out").c_str(), "w");

    fscanf(fin, "%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        fscanf(fin, "%d %lld", &L, &X);
        fgetc(fin);

        int i;
        char ch;
        for (i = 0; i < L; ++i)
        {
            fscanf(fin, "%c", &ch);
            if (ch == '1')
                S[i] = 1;
            else
                S[i] = ch - 'g';
        }

        solve();

        fprintf(fout, "Case #%d: ", t);
        if (ans)
            fprintf(fout, "YES\n");
        else
            fprintf(fout, "NO\n");
    }

    return 0;
}
