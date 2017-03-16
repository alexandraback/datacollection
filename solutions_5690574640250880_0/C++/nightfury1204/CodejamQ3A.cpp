//BISMILLAHIR RAHMANIR RAHIM
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
#define N 1000000
#define sn scanf
#define pf printf

typedef long long int ll;
using namespace std;
int n,m,v,vis[30000],ar[100][100],R[]={0,0,1,-1,-1,-1,1,1},C[]={1,-1,0,0,-1,1,-1,1};
struct T
{
    int x,y;
}temp;
vector<T>arr[100000];

int area(int x,int y)
{
    arr[v].clear();
    int xx,yy,cnt=0;
    for(int i=0;i<8;i++)
    {

       xx=x+R[i];
       yy =y+C[i];
       if(xx>=0&&yy>=0&&xx<n&&yy<m&&vis[ar[xx][yy]]==0)
       {
           vis[v]=1;
           ar[xx][yy]=v;
           temp.x=xx;temp.y=yy;
           arr[v].push_back(temp);
           cnt++;
       }
    }
    return cnt;
}
int vv=0;
void visit(int x,int w,int a)
{
      if(w==a)
      {
          vv=1;
          return;
      }
     for(int i=0;i<arr[x].size();i++)
     {
         temp=arr[x][i];
         ++v;
         int d=area(temp.x,temp.y);
         int f=v;
         if(a+d<=w&&vv==0)
         {
             visit(f,w,a+d);
             if(vv==0)
               vis[f]=0;
         }
         else
            vis[v]=0;
     }
}
int main()
{
    int i,j,k,l,t,r,x,M,a,b;

    freopen("C-small-attempt1.in","r",stdin);
    freopen("Output.txt","w",stdout);
    scanf("%d",&t);
    for(r=1;r<=t;r++)
    {
        scanf("%d %d %d",&n,&m,&x);
      // printf("%d %d %d\n",n,m,x);
        x=m*n-x;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                memset(ar,0,sizeof(ar));
                memset(vis,0,sizeof(vis));
                v=1;vv=0;
                ar[i][j]=v;
                a=area(i,j);
                visit(v,x,a+1);
                a=i;b=j;
                if(vv==1)
                    j=m,i=n;
            }
        }
        printf("Case #%d:\n",r);
        if(x==1)
        {
            for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==0&&j==0)
                    printf("c");
                else
                    printf("*");
            }
            printf("\n");
        }
        }
       else if(vv==0)
            printf("Impossible\n");
        else
        {
            for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(i==a&&j==b)
                    printf("c");
                else if(vis[ar[i][j]]==1)
                printf(".",ar[i][j]);
                else
                    printf("*");
            }
            printf("\n");
        }
        }
    }
    fclose(stdout);
    fclose(stdin);
        return 0;
}


