// macros {{{
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define BIT(n) ((1LL) << (long long)(n))
#define FOR(i,c) for (auto i=(c).begin(); i != (c).end(); ++i)
#define REP(i,n) for (int i = 0; i < (int)(n); ++i)
#define REP1(i,a,b) for (int i=(int)(a); i <= (int)(b); ++i)
#define MP make_pair
#define PB push_back

#define Fst first
#define Snd second

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> PII;
typedef vector<int> VI;

#define runtime() ((double)clock() / CLOCKS_PER_SEC)

const double eps = 1e-7;
// }}}

#define MAX 51
#define DMAX 8

int last;

int n, m;
int vis[MAX][MAX];

int dir[DMAX][2] = 
{
    {-1, -1}, {-1, 0}, {-1, 1}, 
    {0, 1}, 
    {1, 1}, {1, 0}, {1, -1},
    {0, -1},
};
#define inboard(p, n, m) (0 <= p.first and p.first < n and 0 <= p.second and p.second < m)

bool bfs(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    int cnt = 0;

    vis[x][y] = 1;
    cnt ++;
    if (last == 1) return true;

    queue<PII> q;
    q.push(MP(x, y));

    while (not q.empty())
    {
        PII a = q.front(); 
        q.pop();

        int ct = 0;
        for (int i = 0; i < DMAX; ++i)
        {
            PII b(a.first + dir[i][0], a.second + dir[i][1]);

            if (not inboard(b, n, m)) continue;

            if (not vis[b.first][b.second])
                ct ++;
        }

        //printf("%d %d: %d\n", a.first, a.second, ct);
        if (cnt + ct > last) continue;

        for (int i = 0; i < DMAX; ++i)
        {
            PII b(a.first + dir[i][0], a.second + dir[i][1]);
            if (not inboard(b, n, m)) continue;

            if (not vis[b.first][b.second])
            {
                vis[b.first][b.second] = 1;
                q.push(b);
            }
        }
        cnt += ct;
    }
    //printf("cnt: %d, last: %d\n", cnt, last);
    return cnt == last;
}

int main()
{
    PII NOP(-1, -1);

    int z;
    scanf("%d", &z);

    for (int zi = 1; zi <= z; ++zi)
    {
        fprintf(stderr, "Case %d...\n", zi);
        int bomb;
        scanf("%d %d %d", &n, &m, &bomb);

        last = n * m - bomb;

        PII ans = NOP;
        for (int i = 0; i < n and ans == NOP; ++i)
            for (int j = 0; j < m and ans == NOP; ++j)
            {
                if(bfs(i, j))
                    ans = MP(i, j);
            }

        printf("Case #%d:\n", zi);

        if (ans == NOP)
        {
            printf("Impossible\n");
            continue;
        }

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (i == ans.first and j == ans.second) 
                {
                    printf("c");
                    continue;
                }
                printf("%c", vis[i][j] == 0 ? '*' : '.');
            }
            printf("\n");
        }
    }
}

