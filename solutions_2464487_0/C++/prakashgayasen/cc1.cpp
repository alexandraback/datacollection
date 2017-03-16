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
int64 r,k;
int fn(int64 n)
{
int64 vl = (2*r*n)+((2*n*n)-n);
if(vl<=k)return 1;
else return 0;
}
int main()
{
//freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
int64 i,j,n,m,t,cnt=1,lo,mid,hi,ans;
cin>>t;
while(t--)
{
scanf("%lld %lld",&r,&k);
lo = 0;hi = sqrt(k)+1;
while(lo<hi-1)
 {
 mid = (lo+hi)/2;
 //cout<<lo<<" "<<mid<<" "<<hi<<endl;
 if(fn(mid)==0)hi=mid-1;
 else lo = mid;
 } 
if(fn(hi)==1)ans=hi;
else ans = lo; 
printf("Case #%lld: %lld\n",cnt,ans);
cnt++;
}
return 0;
}
