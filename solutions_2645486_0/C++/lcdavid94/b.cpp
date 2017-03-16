#include<iostream>
using namespace std;
int e,r,n,a[100],f[100][100];
bool s[100][100];
int fn(int en,int p)
{
    if (p==n-1) return (en*a[p]);
    if (s[en][p]) return f[en][p];
    int x=0;
    for (int i=0;i<=en;++i)
    {
        x>?=i*a[p]+fn(min(e,en-i+r),p+1);
    }
    s[en][p]=1;
    return (f[en][p]=x);
}
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    int T;
    cin>>T;
    for (int TT=1;TT<=T;++TT)
    {
        cin>>e>>r>>n;
        for (int i=0;i<n;++i)
            cin>>a[i];
        memset(s,0,sizeof(s));
        int ans=fn(e,0);
        cout<<"Case #"<<TT<<": "<<ans<<endl;
    }
}
