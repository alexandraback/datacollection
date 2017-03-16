#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define f first
#define s second
#define si(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define CLR(x)  memset(x,0,sizeof(x))
#define RESET(x,a) memset(x,a,sizeof(x))
#define pi pair<int,int>
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<">value ("<<#x<<") : "<<x<<endl;

int mat[10][10];

int dp[10];

int chk(int n)
{
    CLR(dp);
    dp[0]=1;
    int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=i;j<n;j++)
        {
            if(mat[i][j])dp[j]+=dp[i];
        }
    }
    return dp[n-1];
}

int main()
{
    freopen("2.in","r",stdin);
    freopen("B-out.txt","w",stdout);
    int tt,t,j,n,m,i;
    si(tt);
    for(t=1;t<=tt;t++)
    {
        si(n);
        si(m);
        printf("Case #%d: ",t);
        CLR(mat);
        int val=n*(n-1);
        val/=2;
        bool ok=false;
//        for(i=0;i<5;i++)
//        {
//            for(j=0;j<5;j++)
//            {
//                si(mat[i][j]);
//            }
//        }
//        j=chk(5);
        //printf("%d\n",j);
        for(i=1;i<(1<<val);i++)
        {
            int row=0,cnt=0;
            for(j=0;j<val;j++)
            {
                if(j-cnt+1==n)
                {
                    row++;
                    cnt+=n-row-1;
                }
                if(i&(1<<j))
                    mat[row][j-cnt+1]=1;
                else
                    mat[row][j-cnt+1]=0;
            }
//            for(int k=0;k<n;k++)
//            {
//                for(j=0;j<n;j++)
//                    printf("%d ",mat[k][j]);
//                printf("\n");
//            }
//            printf("\n");
            j=chk(n);
            if(j==m)
            {
                ok=true;
                break;
            }
        }
        if(ok)
        {
            printf("POSSIBLE\n");
            for(i=0;i<n;i++)
            {
                for(j=0;j<n;j++)
                    printf("%d",mat[i][j]);
                printf("\n");
            }
        }
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}


