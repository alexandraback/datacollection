#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long T,i,e,r,n,j,k,t,ans,v[10000005],c[10000005],a[10000005];
int main()
{
    //freopen("2.in","r",stdin);
    //freopen("2.out","w",stdout);
    cin >> T;
    for (i=0;i<T;i++)
    {
        cin >> e >> r >> n;
        for (j=0;j<n;j++)
            cin >> v[j];
        for (j=0;j<n;j++)
        {
            for (k=0;k<=e;k++)
                for (t=0;t<=k;t++)
                {
                    c[min(k-t+r,e)]=max(c[min(k-t+r,e)],v[j]*t+a[k]);
                }
            for (k=0;k<=e;k++)
            {
               // cout << k << " " << c[k] << endl;
                a[k]=c[k];
                c[k]=0;
            }
            //cout << endl;
        }
        ans=0;
        for (j=0;j<=e;j++)
        {
            ans=max(ans,a[j]);
            a[j]=0;
        }
        cout << "Case #" << i+1 << ": " << ans << endl;
    }
    return 0;
}

