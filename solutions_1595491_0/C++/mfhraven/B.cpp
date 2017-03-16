#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
int ans[1000][2],f[1000][1000];
int test,n,s,p;
int sor[1000];

int main()
{
    scanf("%d",&test);
    
    for (int k=1;k<=test;k++)
    {
        scanf("%d%d%d",&n,&s,&p);
        
        memset(ans,255,sizeof(ans));
        
        for (int i=1;i<=n;i++)
        {  
            scanf("%d",sor+i);
            for (int s=0;s<=sor[i] && s<=10;s++)
            for (int b=s;b<=s+2 && b<=10 ;b++)
            {
                int m=sor[i]-s-b;
                if (s<=m && m<=b && m<=10)
                {
                    if (b-s<=1 && b>ans[i][0])  ans[i][0]=b;
                    if (b-s==2 && b>ans[i][1])  ans[i][1]=b;  
                }
            }
        }
        
        memset(f,255,sizeof(f));
        
        f[0][0]=0;
        for (int i=1;i<=n;i++)
        for (int j=0;j<=i && j<=s;j++)
        {
            if (f[i-1][j]!=-1)
            if (ans[i][0]>=p)
            {
                if (f[i-1][j]+1>f[i][j])    f[i][j]=f[i-1][j]+1;
            }
            else
            {
                if (f[i-1][j]>f[i][j])      f[i][j]=f[i-1][j];
            }
            
            if (j && f[i-1][j-1]!=-1)
            if (ans[i][1]>=p)
            {
                if (f[i-1][j-1]+1>f[i][j])  f[i][j]=f[i-1][j-1]+1;
            }
            else
            {
                if (f[i-1][j-1]>f[i][j])    f[i][j]=f[i-1][j-1];
            }
        }
        
        printf("Case #%d: %d\n",k,f[n][s]);
    }
}
