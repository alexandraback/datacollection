#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,s,p,ans;
int a[100];
bool cmp(int a,int b)
{
    return a<b;
}
int main()
{
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    int T; cin>>T;
    for (int tt=1; tt<=T; tt++)
    {
        cin>>n>>s>>p;
        for (int i=1; i<=n; i++) cin>>a[i];
        sort(a+1,a+1+n,cmp);
        ans=0;
        for (int i=1; i<=n; i++)
        {
            int t;
            if (a[i]%3==0) t=a[i]/3;
            if (a[i]%3==1||a[i]%3==2) t=a[i]/3+1;
            if (s>0&&t<p&&a[i]!=0)
            {
                if (a[i]%3==0) t=a[i]/3+1;
                if (a[i]%3==1) t=a[i]/3+1;
                if (a[i]%3==2) t=a[i]/3+2;
                if (t>=p)
                s--;
            }
            if (t>=p) ans++;
        }
        cout<<"Case #"<<tt<<": "<<ans<<endl;
    }
}
