#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

const int INF=1000000007;
const double eps=0.00000001;

bool a[101][101];

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,t;
    long long m;
    cin>>t;
    for(int cas=1;cas<=t;++cas)
    {
        memset(a,0,sizeof(a));
        cout<<"Case #"<<cas<<": ";
        cin>>n>>m;
        long long k=1;
        for(int i=1;i<=n-2;i++)
            k<<=1;
        if(k<m)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }
        else
            cout<<"POSSIBLE"<<endl;
        if(m==1 || m==2)
        {
            a[1][n]=1;
            if(m==2)
                a[1][2]=a[2][n]=1;
            for(int i=1;i<=n;i++,cout<<endl)
                for(int j=1;j<=n;j++)
                    cout<<a[i][j];
            continue;
        }
        k=1;
        int e=0;
        for(int i=2;i<=n;i++)
        {
            if(k*2>=m)
                break;
            for(int j=1;j<i;j++)
                a[j][i]=1;
            if(i>2)
            {
                k<<=1;
                ++e;
            }
        }
        while(m>0 && e>=0)
        {
            if(m>=k)
            {
                m-=k;
                a[e+2][n]=1;
            }
            k>>=1;
            --e;
        }
        if(m==1)
            a[1][n]=1;
        for(int i=1;i<=n;i++,cout<<endl)
            for(int j=1;j<=n;j++)
                cout<<a[i][j];
    }
    return 0;
}
