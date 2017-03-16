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
		if(sm>a[B])
		{
			cout<<"IMPOSSIBLE\n";
			continue;
		}
		cout<<"POSSIBLE\n";
		for(i=0;i<=B;i++)ch[i]=0;
		for(i=B-1;i>=1;i--)
		{
			if(sm==0)break;
			if(a[i]>sm)continue;
			sm-=a[i];
			ch[i]=1;
		}
		for(i=1;i<=B;i++)
		{
			for(j=1;j<=B;j++)
			{
				if(j==B)
				{
					if(ch[i])cout<<"1";
					else cout<<"0";
				}
				else
				if(j>i)cout<<"1";
				else cout<<"0";
			}
			cout<<endl;
		}
	}
	return 0;
}
