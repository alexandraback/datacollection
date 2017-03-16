/*************************************************************************
    > File Name: jam02.cpp
    > Author: Guo Hengkai
    > Created Time: 2015/4/11 12:06:01
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

const string PROG = "B-small-attempt2";
FILE *fin, *fout;

int T;
int D;
int P[3000];
int ans;

void Qsort(int left, int right)
{
    int x = P[(left + right) >> 1];
    int i = left, j = right;
    int temp;

    do
    {
        while (P[i] > x) ++i;
        while (x > P[j]) --j;
        if (i <= j)
        {
            temp = P[i]; P[i] = P[j]; P[j] = temp;
            ++i; --j;
        }
    } while (i <= j);

    if (left < j) Qsort(left, j);
    if (i < right) Qsort(i, right);
}

int main()
{
    fin = fopen((PROG + ".in").c_str(), "r");
    fout = fopen((PROG + ".out").c_str(), "w");

    fscanf(fin, "%d", &T);
    for (int t = 1; t <= T; ++t)
    {
        fscanf(fin, "%d", &D);
        int i;
        for (i = 0; i < D; ++i)
        {
            fscanf(fin, "%d", P + i);
        }

        Qsort(0, D - 1);
        int max_p = P[0];
        ans = max_p;
        while (max_p > 1)
        {
            --max_p;
            int time = 0;
            for (i = 0; i < D; ++i)
            {
                if (P[i] <= max_p) break;
                time += (P[i] - 1) / max_p;
            }
            ans = min(ans, max_p + time);
        }
        fprintf(fout, "Case #%d: %d\n", t, ans);
    }

    return 0;
}
