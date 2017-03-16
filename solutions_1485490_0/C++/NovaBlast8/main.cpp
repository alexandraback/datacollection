#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int a[200], b[200], at[200], bt[200], att[200], btt[200], numa[200];

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int q;
    cin >> q;
    for (int tt = 1; tt <= q; tt++)
    {
        int n, m;
        int anss = 0;
        memset(numa, 0, sizeof(numa));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i] >> at[i];
        for (int i = 1; i <= m; i++)
            cin >> b[i] >> bt[i];
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= m; j++)
                if (at[i] == bt[j]) numa[i]++;
        for (int i1 = 0; i1 <= numa[1]; i1++)
            for (int i2 = 0; i2 <= numa[2]; i2++)
                for (int i3 = 0; i3 <= numa[3]; i3++)
                {
                    att[1] = a[1];
                    att[2] = a[2];
                    att[3] = a[3];
                    for (int i = 1; i <= m; i++)
                        btt[i] = b[i];
                    int q1 = 0, q2 = 0, q3 = 0;
                    int i = 1;
                    int ans = 0;
                    while (i <= m)
                    {
                        if (q1 == i1 && q2 == i2 && q3 == i3) break;
                        int m = 1000000000;
                        if (q1 == i1 && q2 == i2)
                        {
                            if (bt[i] == at[3])
                            {
                                m = min(att[3], btt[i]);
                                att[3] -= m;
                                btt[i] -= m;
                                if (m != 0) q3++;
                                if (att[3] == 0) q3 = i3;
                                ans += m;
                            }
                        }
                            else
                        if (q1 == i1)
                        {
                            if (bt[i] == at[2])
                            {
                                m = min(att[2], btt[i]);
                                att[2] -= m;
                                btt[i] -= m;
                                if (m != 0) q2++;
                                if (att[2] == 0) q2 = i2;
                                ans += m;
                            }
                        }
                            else
                        {
                            if (bt[i] == at[1])
                            {
                                m = min(att[1], btt[i]);
                                att[1] -= m;
                                btt[i] -= m;
                                if (m != 0) q1++;
                                if (att[1] == 0) q1 = i1;
                                ans += m;
                            }
                        }
                        if (q1 == i1 && q2 == i2 && q3 == i3) break;
                        m = 1000000000;
                        if (q1 == i1 && q2 == i2)
                        {
                            if (bt[i] == at[3])
                            {
                                m = min(att[3], btt[i]);
                                att[3] -= m;
                                btt[i] -= m;
                                if (m != 0) q3++;
                                if (att[3] == 0) q3 = i3;
                                ans += m;
                            }
                        }
                            else
                        if (q1 == i1)
                        {
                            if (bt[i] == at[2])
                            {
                                m = min(att[2], btt[i]);
                                att[2] -= m;
                                btt[i] -= m;
                                if (m != 0) q2++;
                                if (att[2] == 0) q2 = i2;
                                ans += m;
                            }
                        }
                            else
                        {
                            if (bt[i] == at[1])
                            {
                                m = min(att[1], btt[i]);
                                att[1] -= m;
                                btt[i] -= m;
                                if (m != 0) q1++;
                                if (att[1] == 0) q1 = i1;
                                ans += m;
                            }
                        }
                        if (q1 == i1 && q2 == i2 && q3 == i3) break;
                        m = 1000000000;
                        if (q1 == i1 && q2 == i2)
                        {
                            if (bt[i] == at[3])
                            {
                                m = min(att[3], btt[i]);
                                att[3] -= m;
                                btt[i] -= m;
                                if (m != 0) q3++;
                                if (att[3] == 0) q3 = i3;
                                ans += m;
                            }
                        }
                            else
                        if (q1 == i1)
                        {
                            if (bt[i] == at[2])
                            {
                                m = min(att[2], btt[i]);
                                att[2] -= m;
                                btt[i] -= m;
                                if (m != 0) q2++;
                                if (att[2] == 0) q2 = i2;
                                ans += m;
                            }
                        }
                            else
                        {
                            if (bt[i] == at[1])
                            {
                                m = min(att[1], btt[i]);
                                att[1] -= m;
                                btt[i] -= m;
                                if (m != 0) q1++;
                                if (att[1] == 0) q1 = i1;
                                ans += m;
                            }
                        }
                        i++;
                    }
                    anss = max(ans, anss);
                }
        printf("Case #%d: %d\n", tt, anss);
    }
    return 0;
}
