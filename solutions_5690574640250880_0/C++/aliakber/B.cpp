#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<list>
#include<string>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;
#define ri(N) scanf("%d",&N)
int row[]={1,1,0,-1,-1,-1,0,1};int col[]={0,1,1,1,0,-1,-1,-1};//8 direction
int m,n,visited[100][100];
int check(int x,int y,int rem)
{
    int cnt=0;
    visited[x][y]=2,cnt++;
    vector<pair<int,int> >temp;
    for(int i=0;i<8;i++)
    {
        int x1=x+row[i];
        int y1=y+col[i];
        if(x1<0||y1<0||x1==m||y1==n)
            continue;
        if(!visited[x1][y1])
          visited[x1][y1]=1,cnt++,temp.push_back(make_pair(x1,y1));
    }
    if(cnt==rem)
        return 1;
    else
    {
        for(int i=0;i<temp.size();i++)
        {
            if(check(temp[i].first,temp[i].second,rem-cnt+1))
              return 1;
        }
        for(int i=0;i<temp.size();i++)
        {
            visited[temp[i].first][temp[i].second]=0;
        }
        return 0;
    }
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int i,j,k,l,mine,t,kase=1;
    ri(t);
    while(t--)
    {
        cin>>m>>n>>mine;
        if(mine+1==m*n)
        {
            printf("Case #%d:\n",kase++);
            for(i=0;i<m-1;i++)
            {
                for(j=0;j<n;j++)
                {
                    printf("*");
                }
                printf("\n");
            }
            for(j=0;j<n-1;j++)
                printf("*");
            printf("c\n");
            continue;
        }
        memset(visited,0,sizeof(visited));
        int rem=m*n-mine;
        printf("Case #%d:\n",kase++);
        if(check(0,0,rem))
        {
            for(i=0;i<m;i++)
            {
                for(j=0;j<n;j++)
                {
                    if(i==0&&j==0)
                        printf("c");
                    else if(!visited[i][j])
                        printf("*");
                    else
                        printf(".");
                }
                printf("\n");
            }
        }
        else
          printf("Impossible\n");
    }
return 0;
}

