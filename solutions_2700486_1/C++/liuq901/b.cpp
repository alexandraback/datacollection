#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
double f[2000][2000];
double calc(int n,int X,int Y)
{
    int step=(abs(X)+abs(Y))/2+1,sum=0,T;
    for (int i=1;;i++)
    {
        int len=2*i-1;
        sum+=2*len-1;
        if (sum>=n)
        {
            T=i;
            sum-=2*len-1;
            n-=sum;
            break;
        }
    }
    if (step<T)
        return(1);
    if (step>T)
        return(0);
    int len=2*T-1;
    if (n==2*len-1)
        return(1);
    int m=Y+1;
    memset(f,0,sizeof(f));
    f[0][0]=1;
    for (int i=0;i<len;i++)
        for (int j=0;j<len;j++)
            if (i==len-1)
                f[i][j+1]+=f[i][j];
            else if (j==len-1)
                f[i+1][j]+=f[i][j];
            else
            {
                f[i+1][j]+=f[i][j]*0.5;
                f[i][j+1]+=f[i][j]*0.5;
            }
    double ans=0;
    for (int i=m;i<=min(len-1,n);i++)
        ans+=f[i][n-i];
    return(ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,X,Y;
        scanf("%d%d%d",&n,&X,&Y);
        static int id=0;
        printf("Case #%d: %.10f\n",++id,calc(n,X,Y));
    }
    return(0);
}

