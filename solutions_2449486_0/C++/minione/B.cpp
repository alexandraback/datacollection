#include<iostream>
#include<cstdio>
using namespace std;
int T;
int a[1000][1000];

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    cin>>T;
    for (int t=1; t<=T; ++t)
    {
        bool flag=true;
        int n,m;
        cin>>n>>m;
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) cin>>a[i][j];
        for (int i=0; i<n; ++i)
        {
            for (int j=0; j<m; ++j)
            {
                bool f1,f2;
                f1=f2=false;
                for (int k=0; k<n; ++k)
                    if (a[k][j]>a[i][j]) f1=true;
                for (int k=0; k<m; ++k)
                    if (a[i][k]>a[i][j]) f2=true;
                if (f1 && f2) { flag=false; break; }
            }
            if (!flag) break;
        }
        cout<<"Case #"<<t<<": ";
        if (flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
