#include <iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<vector>

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)>(b)?(b):(a))
#define N 105
using namespace std;
struct Node{
       int r,c,val;
}node[N*N];
int n,m;
int mp[N][N];
int row[N],col[N];
bool cmp(const Node &a,const Node&b)
{
       return a.val>b.val;
}
bool Judge()
{
       int i,j,k=0;
       for(i=1;i<=n;i++)
              for(j=1;j<=m;j++)
              {
                     node[k].r=i;node[k].c=j;
                     node[k++].val=mp[i][j];
              }
       sort(node,node+k,cmp);
       memset(row,-1,sizeof(row));
       memset(col,-1,sizeof(col));
       for(i=0;i<k;i++)
       {
              //printf("%d\n",node[i].val);
              bool flag=false;
              if(row[node[i].r]==-1||row[node[i].r]==node[i].val||
                 col[node[i].c]==-1||col[node[i].c]==node[i].val)
              {
                     col[node[i].c]=MAX(node[i].val,col[node[i].c]);
                     row[node[i].r]=MAX(row[node[i].r],node[i].val);
                     flag=true;
              }
              if(!flag)
                     return false;
       }
       return true;
}
int main()
{
       //freopen("B.in","r",stdin);
       //freopen("out.out","w",stdout);
       int ca;
       scanf("%d",&ca);
       for(int i=1;i<=ca;i++)
       {
              printf("Case #%d: ",i);
              scanf("%d%d",&n,&m);
              for(int x=1;x<=n;x++)
                     for(int y=1;y<=m;y++)
                            scanf("%d",&mp[x][y]);
              if(Judge())
                     printf("YES\n");
              else
                     printf("NO\n");
       }
    return 0;
}
