/*  Vivek Kantariya  */
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#include<queue>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int a[1000006];
queue<pair<int,int> > Q;
int rev(int n)
{
	int k=0;
	while(n>0)
	{
		k=k*10+n%10;
		n/=10;
	}
	return k;
}
int main()
{
	int t,i,j,k,cs,css;
	a[1]=1;
	Q.push(MP(1,1));
	while(Q.sz>0)
	{
		pair<int,int> pi=Q.front();
		Q.pop();
		if((pi.fi+1<=1000000)&&(a[pi.fi+1]==0))
		{
			a[pi.fi+1]=pi.se+1;
			Q.push(MP(pi.fi+1,pi.se+1));
		}
		k=rev(pi.fi);
		if((k<=1000000)&&(a[k]==0))
		{
			a[k]=pi.se+1;
			Q.push(MP(k,pi.se+1));
		}
	}
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cout<<"Case #"<<cs<<": ";
		cin>>k;
		cout<<a[k]<<endl;
	}
	return 0;
}
