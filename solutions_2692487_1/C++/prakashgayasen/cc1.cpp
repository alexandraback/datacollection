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

int main()
{
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
int64 i,j,n,m,t,a[1001],vl,ans,mins,cnt=1;;
cin>>t;
//char a[200001],b[200001],ar[200001];
while(t--)
{
cin>>m>>n;
mins = 1000000;
for(i=0;i<n;i++)cin>>a[i];
sort(a,a+n);
if(m==1){mins=n;printf("Case #%lld: %lld\n",cnt,mins);
cnt++;continue;}
for(i=0;i<n;i++)
   {
   vl=m;ans=0;
   for(j=0;j<=i;j++)
   		{
   		if(vl>a[j])vl+=a[j];
   		else {ans++;vl+=(vl-1);j--;}
   		}
   ans+=n-(i+1);
   //cout<<ans<<endl;
   if(ans<mins)mins=ans;
   }
mins = min(mins,n);   
printf("Case #%lld: %lld\n",cnt,mins);
cnt++;
}
return 0;
}
