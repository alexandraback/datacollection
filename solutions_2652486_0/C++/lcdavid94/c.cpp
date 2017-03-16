#include<iostream>
using namespace std;
int a[3],n,r,m,k,t[10];
bool flag;
bool ok()
{
  bool z[1000];
  memset(z,0,sizeof(z));
  z[1]=z[a[0]]=z[a[1]]=z[a[2]]=z[a[0]*a[1]]=z[a[1]*a[2]]=z[a[2]*a[0]]=z[a[0]*a[1]*a[2]]=1;
  for (int i=0;i<k;++i)
   if (!z[t[i]]) return 0;
  return 1;
}
void f(int p,int q)
{
     if (p==n) {if (ok()) {for (int i=0;i<n;++i) cout<<a[i];cout<<endl;flag=1;}}
     else
     for (a[p]=q;a[p]<=m;++a[p])
       {
         f(p+1,a[p]);
         if (flag) return;
       }
 }
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
    int T;
    cin>>T>>r>>n>>m>>k;
    cout<<"Case #1:"<<endl;
    for (int i=1;i<=r;++i)
    {
        memset(t,0,sizeof(t));
        for (int j=0;j<k;++j)
        {
            cin>>t[j];
        }
        flag=0;
        f(0,2);
    }
}