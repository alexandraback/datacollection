#include<iostream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;

long long f[200][200];
long long fr[200][200];
long long a[200],b[200];
int A[200],B[200];

long long get(int ai,int l,int r)
{

    long long ans=0;

    if(l>r)return 0;
    long long re=a[ai];
    for(int i=l;i<=r;i++)
    {
        if(A[ai]==B[i])
        {
            long long temp=min(re,b[i]);
            ans+=temp;
            re-=temp;
        }
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int tt=1;tt<=t;tt++)
    {
        int n,m;
        cin>>n>>m;
        memset(f,0,sizeof(f));
        memset(fr,0,sizeof(fr));
        for(int i=1;i<=n;i++)
        {
            cin>>a[i]>>A[i];
        }
        for(int i=1;i<=m;i++)
        {
            cin>>b[i]>>B[i];
        }
        for(int i=2;i<=n;i++)
        {
            if(A[i]==A[i-1])
            {
                a[i-1]+=a[i];
                for(int j=i;j<=n-1;j++)
                {
                    a[j]=a[j+1];
                    A[j]=A[j+1];
                }
                n--;i--;
            }
        }
        for(int i=2;i<=m;i++)
        {
            if(B[i]==B[i-1])
            {
                b[i-1]+=b[i];
                for(int j=i;j<=m-1;j++)
                {
                    b[j]=b[j+1];
                    B[j]=B[j+1];
                }
                m--;i--;
            }
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                long long ans=0;
                for(int k=0;k<=j;k++)
                {

                    ans=max(ans,f[i-1][k]+get(i,k+1,j));
                }
                f[i][j]=ans;
                //cout<<i<<" "<<j<<" "<<ans<<endl;
            }
        }
        long long ans=0;
        if(n==3&&A[1]==A[3])
        {
            for(int i=1;i<=m;i++)
            {
                if(A[1]==B[i])
                {
                    if(a[1]>0&&b[i]>0)
                    {
                        long long temp=min(a[1],b[i]);
                        ans+=temp;
                        a[1]-=temp;
                        b[i]-=temp;
                    }
                    if(a[3]>0&&b[i]>0)
                    {
                        long long temp=min(a[3],b[i]);
                        ans+=temp;
                        a[3]-=temp;
                        b[i]-=temp;
                    }
                }
            }
        }
        for(int i=1;i<=m;i++)
            ans=max(ans,f[n][i]);
        printf("Case #%d: %lld\n",tt,ans);


    }

    return 0;
}
