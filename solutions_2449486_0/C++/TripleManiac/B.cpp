#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
#define maxn 230
long n,m;
long maxi[maxn],maxj[maxn];
long i,j,test,cas;
long a[maxn][maxn];
int main()
{
    for (cin>>test,cas=1;cas<=test;cas++)
    {
        cin>>n>>m;
        for (i=0;i<n;i++)
            for (j=0;j<m;j++) cin>>a[i][j];
        cout<<"Case #"<<cas<<": ";
        for (i=0;i<n;i++)
            for (j=0;j<m;j++) if (a[i][j]<0 || a[i][j]>100) goto NO;
        for (i=0;i<n;i++)
        {
            maxi[i]=0;
            for (j=0;j<m;j++) if (a[i][j]>maxi[i]) maxi[i]=a[i][j];
        }
        for (j=0;j<m;j++)
        {
            maxj[j]=0;
            for (i=0;i<n;i++) if (a[i][j]>maxj[j]) maxj[j]=a[i][j];
        }
        for (i=0;i<n;i++)
            for (j=0;j<m;j++)
                if (a[i][j]!=maxi[i] && a[i][j]!=maxj[j]) goto NO;
        cout<<"YES\n";
        if (0) NO:cout<<"NO\n";
    }
//    system("PAUSE");
    return 0;
}
