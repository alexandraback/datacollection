#include <cstdio>

bool graph[1005][1005];
int indegree[1005], outdegree[1005];
int nPoint;

int pathCount(int x, int y)
{
    if(x == y) return 1;
    int cnt = 0;
    for(int iPoint = 1; iPoint <= nPoint && cnt < 2; iPoint++)
    {
        if ( graph[x][iPoint] && pathCount(iPoint, y) ) cnt++;
    }
    return cnt;
}

void clear(int nPoint)
{
    for(int i = 1; i <= nPoint; ++i)
    {
        indegree[i] = 0;
        outdegree[i] = 0;
        for(int j = 1; j <= nPoint; ++j)
        {
            graph[i][j] = false;
        }
    }
}

void input(int nPoint)
{
    for(int iPoint = 1; iPoint <= nPoint; iPoint++)
    {
        int nForX;
        scanf("%d", &nForX);
        while(nForX--)
        {
            int y;
            scanf("%d", &y);                
            graph[iPoint][y] = true;
            indegree[y]++;
            outdegree[iPoint]++;
        }
    }
}

void solve(int iCase)
{
    scanf("%d", &nPoint);
    clear(nPoint);
    input(nPoint);
    bool yes = false;
    for(int x = 1; x <= nPoint && !yes; x++)
    {
        if(outdegree[x] < 2) continue;
        for(int y = 1; y <= nPoint && !yes; y++)
        {
            if( x==y || indegree[y] < 2) continue;
            if(pathCount(x,y) == 2) yes = true;
        }
    }
    printf("Case #%d: %s\n", iCase, yes ? "Yes" : "No");
}

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int nCase;
    scanf("%d", &nCase);
    for(int iCase = 1; iCase <= nCase; iCase++)
    {
        solve(iCase);
    }
    return 0;
}