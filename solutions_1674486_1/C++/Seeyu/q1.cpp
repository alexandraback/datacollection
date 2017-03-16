#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>

using namespace std;
#define MAXN 1004

int C[MAXN][MAXN];
int N;
bool visit[MAXN];
int DFS(int s)
{
    int i , tmp;
    visit[s] = true;
    for(i = 1; i <= N; i++)
    {
        if(C[s][i])
        {
            if( visit[i] )
                return 1;
            else
                tmp = DFS(i);
            if(tmp == 1)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int count, tmpi;
    //freopen ("q1.out", "w+", stdout);
    //freopen ("A-small-attempt2.in", "r", stdin);
    freopen ("A-large.in", "r", stdin);
    scanf("%d\n", &count);

    for(tmpi = 1; tmpi <= count; tmpi++)
    {


        memset(C, 0, sizeof(C));
        scanf("%d", &N);
        for(int i = 1; i <= N; i++)
        {
            int t;
            scanf("%d", &t);
            while(t--)
            {
                int j;
                scanf("%d", &j);
                C[i][j] = 1;
            }
        }
        int i;
        printf("Case #%d: ", tmpi);
        for(i = 1; i <=N; i++)
        {
            memset(visit, 0, sizeof(visit));
            if(DFS(i))
            {
                printf("Yes\n");
                break;
            }
        }
        if(i>N)
            printf("No\n");
    }
}
