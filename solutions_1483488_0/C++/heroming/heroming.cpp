/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2012/4/14 18:40:56
 */
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

#define SZ(v) ((int)(v).size())
const int MAXN = 2000000, MAXE = 7;

int A[MAXE];
int t, a, b, ans;
bool flag[MAXN];

int get_number()
{
        int x = 0;
        for (int i = 0, k = 1; i < MAXE; ++ i, k *= 10)
                x += A[i] * k;
        return x;
}

void cycle(int x)
{
        int y = 1, n;
        flag[x] = 1;
        memset(A, 0, sizeof(A));
        for (int i = 0; i < MAXE; ++ i)
        {
                A[i] = x % 10;
                x /= 10;
                if (x == 0)
                {
                        n = i + 1;
                        break;
                }
        }
        for (int i = 0; i < n; ++ i)
        {
                int k = A[0];
                for (int j = 0; j < n - 1; ++ j)
                        A[j] = A[j + 1];
                A[n - 1] = k;
                k = get_number();
                if (k >= a && k <= b && ! flag[k])
                {
                        flag[k] = 1;
                        ++ y;
                }
        }
        ans += y * (y - 1) / 2;
}

int main()
{
        cin >> t;
        for (int k = 1; k <= t; ++ k)
        {
                cin >> a >> b;
                ans = 0;
                memset(flag, 0, sizeof(flag));
                for (int i = a; i <= b; ++ i)
                        if (! flag[i])
                                cycle(i);
                printf("Case #%d: %d", k, ans);
                if (k != t)
                        printf("\n");
        }
        return 0;
}
