#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;
string str;
typedef long long LL;
bool isprime[210000];
LL prime[210000];int pn;
LL divisor(LL num)
{
	for(int i=1;i<=5000;i++)
		if(num%prime[i]==0)return prime[i];
	return 0;
}
LL basechg(LL num,int b)
{
	LL ans=0,k=1;
	while(num>0)
	{
		ans+=num%2*k;
		k*=b;num/=2;
	}
	return ans;
}
void output(LL num)
{
	if(num==0)return ;
	output(num/2);
	cout<<(num%2);
}
int main()
{
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	for(int i=2;i<=200000;i++)isprime[i]=true;
	for(int i=2;i<=200000;i++)
		if(isprime[i])
		{
			prime[++pn]=i;
			for(int j=2*i;j<=200000;j+=i)
				isprime[j]=false;
		}
	int T;cin>>T;
	for(int ti=1;ti<=T;ti++)
	{
		cout<<"Case #"<<ti<<":"<<endl;
		int n,j;cin>>n>>j;
		for(LL now=(1LL<<n)-1;;now-=2)
		{
			bool can=true;
			LL d[11]={0};
			for(int b=2;b<=10;b++)
			{
				d[b]=divisor(basechg(now,b));
				if(d[b]==0){can=false;break ;}
			}
			if(can)
			{
				j--;
				output(now);
				for(int b=2;b<=10;b++)cout<<" "<<d[b];
				cout<<endl;
			}
			if(j==0)break;
		}
	}
	return 0;
}
