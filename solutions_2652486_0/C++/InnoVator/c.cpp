#include<stdio.h>
#include<string.h>
#include<map>
using namespace std;
int r,n,m,k;
int num[10];
map<int,int> hash[6][6][6];
void dfs(int a1,int a2,int a3)
{
    int tt[4];
    tt[0]=1;
    tt[1]=a1;
    tt[2]=a2;
    tt[3]=a3;
    for(int i=0;i<4;i++)
        hash[a1][a2][a3][tt[i]]++;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            hash[a1][a2][a3][tt[i]*tt[j]]++;
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int z=0;z<4;z++)
                hash[a1][a2][a3][tt[i]*tt[j]*tt[z]]++;
}
void doit()
{
    for(int i=2;i<=5;i++)
        for(int j=2;j<=5;j++)
            for(int z=2;z<=5;z++)
            {
                hash[i][j][z].clear();
                dfs(i,j,z);
            }
}
int main()
{
    int T;
    freopen("C-small-1-attempt0.in","r",stdin);
    freopen("c.txt","w",stdout);
    scanf("%d",&T);
    scanf("%d%d%d%d",&r,&n,&m,&k);
    doit();
    printf("Case #1:\n");
    while(r--)
    {
        int r1,r2,r3;
        int res=0;
        r1=r2=r3=2;
        for(int i=0;i<k;i++)
            scanf("%d",&num[i]);
        for(int i=2;i<=5;i++)
            for(int j=2;j<=5;j++)
                for(int z=2;z<=5;z++)
                {
                    int tmp=0;
                    int flag=0;
                    for(int ii=0;ii<k;ii++)
                    {
                        tmp+=hash[i][j][z][num[ii]];
                        if(!hash[i][j][z][num[ii]])
                            flag=1;
                    }
                    if(flag)
                        continue;
                    if(tmp>res)
                    {
                        r1=i;
                        r2=j;
                        r3=z;
                        res=tmp;
                    }
                }
            printf("%d%d%d\n",r1,r2,r3);
    }
}
