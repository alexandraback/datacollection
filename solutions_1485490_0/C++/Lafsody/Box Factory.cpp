#include<stdio.h>
#include<stdlib.h>

int n,m,t,max,co,dnm[200][200];

struct node1
{
    int type,box;
}a[200];
struct node2
{
    int type,toy;
}b[200];

void dfs(int x,int y,int ux,int uy,int sum)
{
    if(sum>max)max=sum;
    if(x>=n || y>=m)
    {
        
        return;
    }
    /*printf("%d %d %d %d %d\n",x,y,ux,uy,sum);
    system("pause");*/
    if(a[x].type==b[y].type)
    {
        if(a[x].box-ux<b[y].toy-uy)
        {
            dfs(x+1,y,0,uy+b[y].toy-uy-a[x].box+ux,sum+a[x].box-ux);
        }
        if(a[x].box-ux==b[y].toy-uy)
        {
            dfs(x+1,y+1,0,0,sum+a[x].box-ux);
        }
        if(a[x].box-ux>b[y].toy-uy)
        {
            dfs(x,y+1,a[x].box-b[y].toy+uy,0,sum+b[y].toy-uy);
        }
    }else{
        dfs(x+1,y,0,uy,sum);
        dfs(x+1,y+1,0,0,sum);
        dfs(x,y+1,ux,0,sum);
    }
}

int main()
{
    int i,j,l;
    freopen("1.in","r",stdin);
    freopen("1.txt","w",stdout);
    scanf("%d",&t);
    for(l=1;l<=t;l++)
    {
        scanf("%d%d",&n,&m);
        max=0;
        for(i=0;i<n;i++)scanf("%d%d",&a[i].box,&a[i].type);
        for(i=0;i<m;i++)scanf("%d%d",&b[i].toy,&b[i].type);
        for(i=0;i<n;i++)for(j=0;j<m;j++)dnm[i][j]=0;
        dfs(0,0,0,0,0);
        printf("Case #%d: %d\n",l,max);
    }
    
    scanf(" ");
    return 0;
}
