/********************************************
Author: Yinthewind
Sun May 12 17:11:35 CST 2013
********************************************/
#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
using namespace std;
#define MAXN 1000010
#define ll long long

int T,N,q[MAXN],n,sum[MAXN],next[MAXN];

bool isv(char ch)
{
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u') return true;
	return false;
}
int main()
{
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		string s;
		cin>>s>>n;
		N=s.size();
		for(int i=0;i<N;i++)
		{
			if(isv(s[i])) q[i]=0;
			else q[i]=1;
		}
		//cout<<s<<endl;
		//for(int i=0;i<N;i++) cout<<q[i];
		//cout<<endl;
		memset(sum,0,sizeof(sum));
		sum[0]=q[0];
		for(int i=1;i<N;i++) 
			if(q[i]==0) sum[i]=0;
			else sum[i]=sum[i-1]+q[i];
		ll ans=0;
		memset(next,-1,sizeof(next));
		next[N]=-1;
		for(int i=N-1;i>=0;i--) 
			if(sum[i]>=n) next[i]=i;
			else next[i]=next[i+1];
		//for(int i=0;i<N;i++) cout<<sum[i]<<endl;
		//for(int i=0;i<N;i++) cout<<next[i]<<endl;
		for(int i=0;i<N;i++) 
		{
			int p=i+n-1;
			if(p>=MAXN) continue;
			if(~next[p]) ans+=N-next[p];
		}
		cout<<"Case #"<<ii<<": "<<ans<<endl;
	}
	return 0;
}
