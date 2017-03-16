#include"iostream"
#include"cstdio"
using namespace std;
int M[101][101];
int MM[101][101];
int rmax[101];
int cmax[101];
int n,m;
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int min(int a,int b)
{
    if(a>b)
    return b;
    return a;
}
void Rmax(int x)
{
    int max=M[x][1];
    int i;
    for(i=2;i<=m;i++)
    {
        if(M[x][i]>max)
        max=M[x][i];
    }
    rmax[x]=max;
    return ;
}
void Cmax(int x)
{
    int max=M[1][x];
    int i;
    for(i=2;i<=n;i++)
    {
        if(M[i][x]>max)
        max=M[i][x];
    }
    cmax[x]=max;
    return ;
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B.output.txt","w",stdout);
    int t,o=0;
    scanf("%d",&t);
    while(t--)
    {

        scanf("%d%d",&n,&m);
        int i,j;
        int flag=1;
        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
           {
               scanf("%d",&M[i][j]);
           }

        for(i=1;i<=n;i++)
            Rmax(i);
        for(j=1;j<=m;j++)
            Cmax(j);

        for(i=1;i<=n&&flag;i++)
            for(j=1;j<=m&&flag;j++)
            {
                MM[i][j]=min(rmax[i],cmax[j]);
                if(M[i][j]<MM[i][j])
                flag=0;

            }

        printf("Case #%d: ",++o);
        if(flag)
        printf("YES\n");
        else
        printf("NO\n");
    }
	return 0;
}
