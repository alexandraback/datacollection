#include<iostream>
using namespace std;
bool flag;
int n,r,m,k,a[100];
void f(int p,int l)
{
     if (p+1==n) {if (l<=m) {flag=1;a[p]=l;for (int i=0;i<n;++i) cout<<a[i]; cout<<endl;}}
     else
     for (a[p]=2;a[p]<=m;++a[p])
     {
         if (l%a[p]==0) f(p+1,l/a[p]);
         if (flag) return;
     }
 }
 int lcm(int a,int b)
 {
     int t=a;
     while (t%b!=0) t+=a;
     return t;
 }
int main()
{
    freopen("c1.in","r",stdin);
    freopen("c1.out","w",stdout);
    int T;
    cin>>T>>r>>n>>m>>k;
    cout<<"Case #1:"<<endl;
    for (int i=1;i<=8000;++i)
    {
        int g=1;
        for (int j=1;j<=k;++j)
        {
            int x;
            cin>>x;
            g=lcm(g,x);
        }
        flag=0;
        f(0,g);
        if (!flag) cout<<"222222222222\n"; 
    }
}
