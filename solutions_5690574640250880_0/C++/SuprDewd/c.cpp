#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
const int INF = 2147483647;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
template <class T> int size(T &x) { return x.size(); }

// assert or gtfo

inline int snoob(int x) {
    int y = x & -x, z = x + y;
    return z | ((x ^ z) >> 2) / y;
}

#define DEBUG 0
#define CHECK 1
#define MAXN 7
int cnt[MAXN * MAXN];
bool vis[MAXN * MAXN];
int q[MAXN * MAXN];

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d:\n", t+1);

        int r, c, m;
        scanf("%d %d %d\n", &r, &c, &m);

#if CHECK
        if (r > MAXN || c > MAXN)
            continue;
#endif

        bool poss = false;
        for (int b = (1 << m) - 1; b < (1 << (r * c)); b = snoob(b))
        {
#if DEBUG
            printf("==================\n");

            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (false)
                    {
                        printf("c");
                    }
                    else if (b & (1 << (i * c + j)))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf(".");
                    }
                }

                printf("\n");
            }

            printf("\n");
#endif

            memset(cnt, 0, (r * c) << 2);
            memset(vis, 0, r * c);

            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                    if (b & (1 << (i * c + j)))
                        for (int di = -1; di <= 1; di++)
                            for (int dj = -1; dj <= 1; dj++)
                            {
                                int ci = i + di,
                                    cj = j + dj;

                                if (ci >= 0 && cj >= 0 && ci < r && cj < c)
                                    cnt[ci * c + cj]++;
                            }

#if DEBUG
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (b & (1 << (i * c + j)))
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("%d", cnt[i * c + j]);
                    }
                }

                printf("\n");
            }

            printf("\n");
#endif

            bool foundzero = false;

            int zx = -1,
                zy = -1;

            for (int i = 0; !foundzero && i < r; i++)
            {
                for (int j = 0; !foundzero && j < c; j++)
                {
                    if (cnt[i * c + j] == 0 && (~b & (1 << (i * c + j))))
                    {
                        zx = i;
                        zy = j;

                        foundzero = true;
                        int left = 0,
                            right = 0;

                        q[right++] = i * c + j;
                        vis[i * c + j] = true;

#if DEBUG
                        printf("starting at %d %d\n", i, j);
#endif

                        while (left < right)
                        {
                            int x = q[left] / c,
                                y = q[left] % c;

#if DEBUG
                        printf("visiting %d %d\n", x, y);
#endif

                            left++;
                            for (int dx = -1; dx <= 1; dx++)
                            {
                                for (int dy = -1; dy <= 1; dy++)
                                {
                                    int cx = x + dx,
                                        cy = y + dy;

#if DEBUG
                        printf("maybe %d %d\n", cx, cy);
                        printf("cx >= 0, %d %d, %d\n", cx, 0, cx >= 0);
                        printf("cx < r, %d %d, %d\n", cx, r, cx < r);
                        printf("cy >= 0, %d %d, %d\n", cy, 0, cy >= 0);
                        printf("cy < c, %d %d, %d\n", cy, c, cy < c);
#endif

                                    if (cx >= 0 && cx < r && cy >= 0 && cy < c && !vis[cx * c + cy])
                                    {
#if DEBUG
                                        printf("next %d %d %d\n", cx, cy);
#endif

                                        vis[cx * c + cy] = true;
                                        if (cnt[cx * c + cy] == 0)
                                        {
                                            q[right++] = cx * c + cy;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }

            int remcnt = 0;
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                {
                    if (!vis[i * c + j] && (~b & (1 << (i * c + j))))
                    {
                        remcnt++;
                        if (!foundzero)
                            zx = i, zy = j;
                    }
                }

#if DEBUG
            printf("%d %d\n", remcnt, foundzero);
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (i == zx && j == zy)
                    {
                        printf("c");
                    }
                    else if (b & (1 << (i * c + j)))
                    {
                        printf("*");
                    }
                    else if (vis[i * c + j])
                    {
                        printf("X");
                    }
                    else
                    {
                        printf(".");
                    }
                }

                printf("\n");
            }

            printf("\n");
#endif

            if (remcnt == 0 || (!foundzero && remcnt == 1))
            {
                poss = true;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        if (i == zx && j == zy)
                        {
                            printf("c");
                        }
                        else if (b & (1 << (i * c + j)))
                        {
                            printf("*");
                        }
                        else
                        {
                            printf(".");
                        }
                    }

                    printf("\n");
                }

                break;
            }
        }

        if (!poss)
            printf("Impossible\n");
    }

    return 0;
}

