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

vector<pair<int, int> > ids;
vector<int> id;
int n, m;

int mem[8][1 << 8];
int best[8][1 << 8];
bool cango[10][10];

// int candoit(int at, int done)
// {
//     if (done == ((1 << n) - 1))
//         return done;
// 
//     if (mem[at][done] != -1)
//         return mem[at][done];
// 
//     int meow = done;
//     for (int i = 0; i < n; i++)
//     {
//         int nxt = ids[i].second;
//         if ((~meow & (1 << nxt)) && cango[at][nxt])
//         {
//             int rest = candoit(nxt, meow | (1 << nxt));
//             if (rest != -2)
//             {
//                 meow |= rest;
//             }
//         }
//     }
// 
//     return mem[at][done] = meow;
// }
// 
// void doit(int at, int done)
// {
//     cout << id[at];
//     int meow = done;
//     for (int i = 0; i < n; i++)
//     {
//         int nxt = ids[i].second;
//         if ((~meow & (1 << nxt)) && cango[at][nxt])
//         {
//             int rest = candoit(nxt, meow | (1 << nxt));
//             if (rest != -2)
//             {
//                 doit(nxt, meow | (1 << nxt));
//                 meow |= rest;
//             }
//         }
//     }
// }

int main()
{
    int ts;
    scanf("%d\n", &ts);

    for (int t = 0; t < ts; t++)
    {
        printf("Case #%d: ", t+1);

        scanf("%d %d\n", &n, &m);

        id.clear();
        ids.clear();
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            id.push_back(x);
            ids.push_back(make_pair(id[i], i));
        }

        memset(cango, 0, sizeof(cango));
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            a--, b--;
            cango[a][b] = cango[b][a] = true;
        }

        sort(all(ids));

        vector<bool> done(n, false);

        int start = ids[0].second;
        vector<int> curpath;

        done[start] = true;
        curpath.push_back(start);

        vector<int> curpathat(n, -1);
        curpathat[start] = 0;

        // while (true)
        for (int it = 0; it < n; it++)
        {
            int at = curpath[size(curpath) - 1];
            cout << id[at];

            vector<int> highest(n, -1);
            for (int i = size(curpath) - 1; i >= 0; i--)
            {
                stack<int> S;
                S.push(curpath[i]);
                vector<bool> visited(n, false);
                visited[curpath[i]] = true;
                while (!S.empty())
                {
                    int cur = S.top(); S.pop();
                    for (int j = 0; j < n; j++)
                    {
                        if (cango[cur][j] && !visited[j] && curpathat[j] == -1)
                        {
                            visited[j] = true;
                            highest[j] = i;
                            S.push(j);
                        }
                    }
                }
            }

            for (int i = 0; i < n; i++)
            {
                int nxt = ids[i].second;
                if (done[nxt]) continue;

                int lowest = -1;
                for (int j = 0; j < size(curpath); j++)
                {
                    if (cango[nxt][curpath[j]])
                    {
                        lowest = j;
                    }
                }

                if (lowest == -1) continue;

                bool ok = true;
                for (int j = 0; j < n; j++)
                {
                    ok = ok && (done[j] || highest[j] <= lowest);
                }

                if (!ok) continue;

                while (size(curpath) - 1 != lowest)
                {
                    curpathat[curpath[size(curpath) - 1]] = -1;
                    curpath.pop_back();
                }

                curpath.push_back(nxt);
                curpathat[nxt] = size(curpath) - 1;
                done[nxt] = true;
                break;
            }

            // for (int i = 0; i < n; i++)
            // {
            //     int nxt = ids[i].second;
            //     if (done[nxt])
            //         continue;

            //     int deepest = -1;
            //     for (int j = size(curpath) - 1; j >= 0; j--)
            //     {
            //         bool ok = true;

            //         for (int k = 0; k < n; k++)
            //         {
            //             if (done[k])
            //                 continue;

            //             vector<bool> visited(n, false);
            //             visited[k] = true;
            //             queue<int> Q;
            //             Q.push(k);

            //             int curdeepest = -1;
            //             while (!Q.empty())
            //             {

            //             }
            //         }

            //         if (ok)
            //         {
            //             deepest = j;
            //             break;
            //         }
            //     }
            // }
        }

        cout << endl;

        // priority_queue<ii, vector<ii>, greater<ii> > pq;
        // pq.push(ii(ids[0].first, ids[0].second));
        // vector<bool> done(n, false);

        // while (!pq.empty())
        // {
        //     ii cur = pq.top(); pq.pop();
        //     if (done[cur.first])
        //         continue;

        //     done[cur.second] = true;
        //     cout << cur.first;
        // }


        // memset(mem, -1, sizeof(mem));
        // doit(ids[0].second, 1 << ids[0].second);

        // int ok = candoit(ids[0].second, 1 << ids[0].second);
        // assert(ok == 1);

        // int at = ids[0].second,
        //     done = 1 << at;



        // for (int i = 0; i < n; i++)
        // {
        //     cout << id[at];

        //     int meow = done;
        //     for (int i = 0; i < n; i++)
        //     {
        //         int nxt = ids[i].second;
        //         if ((~meow & (1 << nxt)) && cango[at][nxt])
        //         {
        //             int rest = candoit(nxt, meow | (1 << nxt));
        //             if (rest != -2)
        //             {
        //                 meow |= rest;
        //             }
        //         }
        //     }

        //     done = meow;
        //     at = best[at][mask];
        //     mask |= 1 << at;
        // }

        // cout << endl;
    }

    return 0;
}

