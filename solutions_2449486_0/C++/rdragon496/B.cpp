#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<queue>
#define MAXN 64
#define INF 1<<30
///
using namespace std;

int graph[105][105];
int temp[105][105];
bool rflag[105];
bool cflag[105];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int c=1; c<=cases; c++)
    {
        int m,n;
        scanf("%d %d",&m,&n);
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&graph[i][j]);
            }
        }
        memset(rflag,false,sizeof(rflag));
        memset(cflag,false,sizeof(cflag));
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                temp[i][j]=100;
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j]==2)
                {
                    rflag[i]=true;
                    cflag[j]=true;
                    for(int k=0; k<m; k++)
                    {
                        temp[k][j]=2;
                    }

                    for(int k=0; k<n; k++)
                    {
                        temp[i][k]=2;
                    }
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j]==1)
                {
                    if(!rflag[i])
                    {
                        for(int k=0; k<n; k++)
                        {
                            temp[i][k]=1;
                        }
                    }
                    if(!cflag[j])
                    {
                        for(int k=0; k<m; k++)
                        {
                            temp[k][j]=1;
                        }
                    }
                }
            }
        }
        bool flag=true;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(temp[i][j]!=graph[i][j])
                {
                    flag=false;
                    break;
                }
            }
            if(!flag) break;
        }
        printf("Case #%d: ",c);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
