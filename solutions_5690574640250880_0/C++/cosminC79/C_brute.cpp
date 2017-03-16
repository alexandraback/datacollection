#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define NMAX 55
#define pii pair <int, int>
#define mp make_pair
#define x first
#define y second
#define bit(x) (1 << (x - 1))
#define has_bit(mask, x) (mask & bit(x))
#define HMAX (1 << 25)
using namespace std;
int tests, n, m, r, A[NMAX][NMAX], val[HMAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool mark[NMAX][NMAX];
queue <pii> Q;
pii st;

inline int valid(int x, int y)
{
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

inline int ok(int x, int y)
{
    for (int i = 0; i < 8; i++)
        if (A[x + dx[i]][y + dy[i]])
            return 0;
    return 1;
}

inline int check()
{
    st = mp(-1, -1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!A[i][j] && ok(i, j))
                st = mp(i, j);
    if (st.x == -1)
    {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                if (!A[i][j])
                    st = mp(i, j);
    }
    
    memset(mark, false, sizeof(mark));
    Q.push(mp(st.x, st.y)); mark[st.x][st.y] = true;
    int x, y;
    while (!Q.empty())
    {
        pii node = Q.front();
        Q.pop();
        if (ok(node.x, node.y))
        {
            for (int i = 0; i < 8; i++)
            {
                x = node.x + dx[i]; y = node.y + dy[i];
                if (valid(x, y) && !mark[x][y])
                {
                    mark[x][y] = true;
                    Q.push(mp(x, y));
                }
            }
        }
    }
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!A[i][j] && !mark[i][j])
                return 0;
    
    return 1;
}

void printSol()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            if (!A[i][j])
            {
                if (i != st.x || j != st.y)
                    printf(".");
                else
                    printf("c");
            }
            else
                printf("*");
        printf("\n");
    }
}

int main()
{
    freopen("input", "r", stdin);
    freopen("output2", "w", stdout);
    
    scanf("%d", &tests);
    bool foundSol;
    
    for (int i = 1; i < HMAX; i++)
        val[i] = val[i >> 1] + (i & 1);
    
    for (int test_no = 1; test_no <= tests; test_no++)
    {
        scanf("%d%d%d", &n, &m, &r);
        printf("Case #%d:\n", test_no);
        foundSol = false;
        
        //~ if (n * m > 20)
        //~ {
            //~ printf("Ignore\n");
            //~ continue ;
        //~ }
        
        memset(A, 0, sizeof(A));
        for (int i = 0; i < (1 << (n * m)); i++)
        {
            if (val[i] == r)
            {
                for (int j = 1; j <= n * m; j++)
                {
                    pii curr;
                    if (j % m == 0)
                        curr = mp(j / m, m);
                    else
                        curr = mp(j / m + 1, j % m);
                        
                    if (has_bit(i, j))
                        A[curr.x][curr.y] = 1;
                    else
                        A[curr.x][curr.y] = 0;
                }
                if (check())
                {
                    foundSol = true;
                    break ;
                }
            }
        }
        
        if (foundSol)
        {
            //~ printf("Solution\n");
            printSol();
            continue ;
        }
        else
            printf("Impossible\n");
    }
    return 0;
}

