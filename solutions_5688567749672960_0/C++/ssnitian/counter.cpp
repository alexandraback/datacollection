#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000001
ll a[N];
int main()
{
	ll i,j,k,l,m,n,t;
	a[1]=1;
	ll sum=0;
	for(i=2;i<N;i++)
	{
     j=i;
     sum=0;
     while(j>0)
     {
     	sum=sum*10;
     	sum=sum+j%10;
     	j=j/10;
     }
     //cout<<sum<<endl;
     if(sum<i && i%10!=0)
     a[i]=min(a[i-1]+1,a[sum]+1);
     else
     a[i]=a[i-1]+1;
     //cout<<a[i]<<endl;
	}
	scanf("%lld",&t);
	j=1;
	while(t--)
	{
		scanf("%lld",&n);
		cout<<"Case #"<<j<<": "<<a[n]<<endl;
		j++;
	}
	return 0;
}
