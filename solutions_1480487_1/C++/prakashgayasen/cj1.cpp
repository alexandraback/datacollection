#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
typedef long long int int64;
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,m,t,sm,cnt=1,a[1001],n,ns,tos,on;
double k,ans;
cin>>t;
while(t--)
{
ns = sm = 0;
scanf("%lld",&n);for(i=0;i<n;i++){scanf("%lld",&a[i]);sm+=a[i];}
k = 2*((double)(sm/n));
cout<<"Case #"<<cnt<<":";
on = n;
for(i=0;i<on;i++){if(a[i]>k){n--;ns+=a[i];}}
tos = sm*2;
tos -= ns;
k = ((double)tos/n);
for(i=0;i<on;i++){ans = 100*(double)(k-a[i])/sm;if(ans>=0.0)printf(" %0.6f",ans);else printf(" 0.000000");}
cout<<endl;
cnt++;
}
return 0;
}

