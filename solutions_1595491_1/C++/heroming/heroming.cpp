/*
 * Author:heroming
 * File:heroming.cpp
 * Time:2012/4/14 13:29:16
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
const int MAXN = 102;

int t, n, s, p, score;
int x, y, ans;

int main()
{
        cin >> t;
        for (int k = 1; k <= t; ++ k)
        {
                cin >> n >> s >> p;
                ans = 0;
                if (p >= 2)
                {
                        x = 3 * p - 4;
                        y = 3 * p - 2;
                        for (int i = 0; i < n; ++ i)
                        {
                                cin >> score;
                                if (score >= y)
                                        ++ ans;
                                else if (score >= x && s)
                                {
                                        ++ ans;
                                        -- s;
                                }
                        }
                }
                else
                {
                        for (int i = 0; i < n; ++ i)
                        {
                                cin >> score;
                                if (score >= p)
                                        ++ ans;
                        }
                }
                printf("Case #%d: %d", k, ans);
                if (k < t)
                        printf("\n");
        }
        return 0;
}
