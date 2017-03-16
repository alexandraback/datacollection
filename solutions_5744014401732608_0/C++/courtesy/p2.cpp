#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<utility>
#define PB push_back
#define pii pair<int,int>
#define MP make_pair
#define sz size()
#define fi first
#define se second
using namespace std;
typedef long long ll;
int B;
ll sm;
ll a[55];
int ch[55];
int an[55][55];
int fn()
{
	int i,j,k;
	for(i=0;i<=B;i++)
	for(j=0;j<=B;j++)an[i][j]=0;
	for(i=1;i<B;i++)
	{
		for(j=i+1;j<B;j++)an[i][j]=1;
	}
	for(i=1;i<B;i++)
	{
		if(ch[i])
		{
			an[i][B]=1;
		}
	}
}
int fun(int c,ll ct)
{
	int i,j,k;
	if(c==B)
	{
		if(ct==sm)
		{
			fn();
			return 1;
		}
		return 0;
	}
	ch[c]=0;
	if(fun(c+1,ct))return 1;
	if(ct+a[c]<=sm)
	{
		ch[c]=1;
		if(fun(c+1,ct+a[c]))return 1;
		ch[c]=0;
	}
	return 0;
}
int main()
{
	int t,i,j,k,cs,css;
	a[1]=1;
	for(i=2;i<=50;i++)
	{
		a[i]=0;
		for(j=i-1;j>0;j--)a[i]+=a[j];
	}
	cin>>css;
	for(cs=1;cs<=css;cs++)
	{
		cin>>B>>sm;
		cout<<"Case #"<<cs<<": ";
		for(i=0;i<=B;i++)ch[i]=0;
		if(fun(1,0))
		{
			cout<<"POSSIBLE\n";
			for(i=1;i<=B;i++)
			{
				for(j=1;j<=B;j++)cout<<an[i][j];
				cout<<endl;
			}
		}
		else
		{
			cout<<"IMPOSSIBLE\n";
		}
	}
	return 0;
}
