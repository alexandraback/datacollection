#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


int graph[1011][1012];
int visited[1011];

int solve(int node)
{
    int j, ret;

    //printf("visit node %d \n",node);
    if (visited[node] == 1)
        return 1;
    visited[node]=1;
    for (j=1;j<=graph[node][0];j++)
    {
        //printf("goto node %d\n",graph[node][j]);
        ret = solve(graph[node][j]);
        if (ret == 1)
            return 1;
    }
    return 0;
}


int main(int argc, char **argv)
{
    int t,i,n,j,k,ret;


    assert (scanf("%d ",&t) == 1);
    for(i=1;i<=t;i++)
    {
        assert (scanf("%d ",&n) == 1);
        for(j=1;j<=n;j++)
        {
            assert (scanf("%d ",&graph[j][0]) == 1);
            for(k=1;k<=graph[j][0];k++)
            {
                assert (scanf("%d ",&graph[j][k]) == 1);
            }
        }

        printf("Case #%d: ",i);
        for(j=1;j<=n;j++)
        {
            for(k=0;k<1011;k++)
                visited[k]=0;
            //bzero(visited,1011);
            ret = solve(j);
            if(ret == 1)
            {
                printf("Yes");
                break;
            }

        }
        if (ret==0)
            printf("No");
        printf("\n");

    }
    return 1;
}
