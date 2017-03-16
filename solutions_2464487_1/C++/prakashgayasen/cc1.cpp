#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<map>
using namespace std;
typedef long long int int64;
unsigned long long r,k;
int64 nd(int64 a)
{
int64 ans=0;
while(a>0){a/=10;ans++;}
return ans;
}
//int64 r,k,tp=1000000000;
int fn(int64 n)
{
int64 vl = (2*r*n)+((2*n*n)-n);
if(nd(r)+nd(n)>19)return 0;
if(vl<=k)return 1;
else return 0;
}
int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,n,m,t,cnt=1,lo,mid,hi,ans;
fn(952);
cin>>t;
while(t--)
{
scanf("%lld %lld",&r,&k);
lo = 0;hi = sqrt(k);
while(lo<hi-1)
 {
 mid = (lo+hi)/2;
// cout<<lo<<" "<<mid<<" "<<hi<<endl;
 if(fn(mid)==0)hi=mid-1;
 else lo = mid;
 } 
if(fn(hi)==1)ans=hi;
else ans = lo; 
//ans = (1-(2*r)+sqrt((2*r-1)*(2*r-1)+8*k))/4;
printf("Case #%lld: %lld\n",cnt,ans);
cnt++;
}
return 0;
}
