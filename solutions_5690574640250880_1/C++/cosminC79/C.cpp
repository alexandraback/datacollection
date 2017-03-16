#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define NMAX 55
#define pii pair <int, int>
#define mp make_pair
#define x first
#define y second
using namespace std;
int tests, n, m, r, A[NMAX][NMAX];

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool mark[NMAX][NMAX];
queue <pii> Q;
pii st, last;

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
    freopen("output", "w", stdout);
    
    scanf("%d", &tests);
    bool foundSol;
    for (int test_no = 1; test_no <= tests; test_no++)
    {
        scanf("%d%d%d", &n, &m, &r);
        
        printf("Case #%d:\n", test_no);
        foundSol = false;
        st = last = mp(-1, -1);
        
        if (n == 1)
        {
            for (int j = 1; j <= r; j++)
                A[1][j] = 1;
            st = mp(1, m);
            printSol();
            continue ;
        }
        if (m == 1)
        {
            for (int i = 1; i <= r; i++)
                A[i][1] = 1;
            st = mp(n, 1);
            printSol();
            continue ;
        }
        
        memset(A, 0, sizeof(A));
        for (int j = m; j >= 3 && r; j--)
            for (int i = 1; i <= n && r; i++)
            {
                if (r == 1 && i == n - 1)
                    break ;
                A[i][j] = 1; 
                last = mp(i, j); r--;
            }
        
        if (r > 1)
        {
            for (int i = 1; i <= n && r; i++)
                for (int j = 1; j <= 2; j++)
                {
                    if (r == 1 && j == 1)
                        break ;
                    A[i][j] = 1;
                    last = mp(i, j); r--;
                }
        }
        
        if (r == 1)
        {
            for (int i = 1; i <= n && !foundSol; i++)
                for (int j = 1; j <= m && !foundSol; j++)
                    if (!A[i][j])
                    {
                        A[i][j] = 1;
                        if (check())
                        {
                            foundSol = true;
                            break ;
                        }
                        A[i][j] = 0;
                    }
                    
            if (!foundSol && last.y == 3)
            {
                A[last.x][last.y] = 0;
                A[1][1] = A[1][2] = 1;
                if (check())
                    foundSol = true;
            }
            
            if (!foundSol && last.y == 3 && last.x - 2 >= 1 && n >= 2)
            {
                A[last.x - 1][3] = A[last.x - 2][3] = 0;
                A[2][1] = A[2][2] = 1;
                if (check())
                    foundSol = true;
            }
        }
        else
        {
            if (check())
                foundSol = true;
        }
        
        if (foundSol)
        {
            printSol();
            continue ;
        }
        else
            printf("Impossible\n");
    }
    return 0;
}


