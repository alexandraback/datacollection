#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int T;
int n,m;
int a[40];
int no[40];
vector<int> V[8];
int ch[10][10];
int ans[10][10];
int now,nub;
int found = 0;
int loop[10];
int fao = 0;
int mem[10][100];
int rec(int x)
{
    if(fao == 1)return 0;
    if(x == n-1)
    {
        nub++;
        return 0;
    }
    if(loop[x] == 1){fao = 1;return 0;}
    if(loop[x] == 0)loop[x] = 1;
    int k = V[x].size();
    for(int i=0;i<k;i++)
    {
        if(ch[x][i] == 0)
        {
           ch[x][i] = 1;
           rec(V[x][i]);
           ch[x][i] = 0;
        }
    }
    loop[x] = 0;
}
int ff()
{
    int i,j,p,q;
    for(i=0;i<n;i++)V[i].clear();
    for(i=0;i<n*n;i++)
    {
        p = i/n;
        q = i%n;
        if(a[i] == 1)V[p].push_back(q);
    }
    now++;
    nub = 0;
    for(i=0;i<n;i++)loop[i]=0;
    fao = 0;
    rec(0);
    //printf("> %d\n",nub);
    if(nub == m && fao == 0)
    {
        found = 1;
        for(i=0;i<n*n;i++)
        {
            p = i/n;
            q = i%n;
            ans[p][q] = a[i];
        }
        return 0;
    }
}
int f(int h)
{
    //printf(">%d\n",h);
    if(found == 1)return 0;
    if(h==n*n)
    {
        ff();
        return 0;
    }
    if(no[h]==0)
    {
        a[h]=0;
        f(h+1);
        a[h]=1;
        f(h+1);
        return 0;
    }
    a[h]=0;
    f(h+1);
    return 0;
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small.txt","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%d %d",&n,&m);
    for(i=0;i<40;i++){a[i]=0;no[i]=0;}
    for(i=0;i<10;i++)for(j=0;j<10;j++)ch[i][j]=0;
    for(i=0;i<n;i++)
    {
        no[i*n+i]=1;
        no[n*(n-1)+i] = 1;
    }
   // for(i=0;i<n;i++){for(j=0;j<n;j++){printf("%d",no[k]);k++;}printf("\n");}printf("\n");
    found = 0;
    f(0);
    printf("Case #%d: ",ii);
    if(found ==  0)printf("IMPOSSIBLE\n");
    else printf("POSSIBLE\n");
    if(found == 1)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                printf("%d",ans[i][j]);
            }
            printf("\n");
        }
    }
}




    return 0;
}
