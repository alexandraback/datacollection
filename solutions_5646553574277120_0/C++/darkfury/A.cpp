#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
 
using namespace std;
#define LL long long
#define pb push_back
#define pLL pair<LL,LL>
#define ff x
#define ss y
#define pii pair<LL,LL>
#define rep(i,a,b) for(LL i=a;i<=b;++i)
#define ld long double
#define tr(n) cin>>n
#define tr2(n,m) cin>>n>>m
#define tr3(a,b,c) cin>>a>>b>>c
#define mp make_pair
#define vLL vector<LL>
#define vpLL vector<pLL>
#define vii vector<pii>
#define vii vector<pii>
#define vld vector<ld>
#define pld pair<ld,ld>
#define vpld vector<pld>
#define Si set<LL>
#define SLL set<LL>
#define SpLL set<pLL>
#define Sii set<pii>
#define fill(a,v) memset(a,v,sizeof(a))
#define MOD 10000000000000000
#define NM 100005
#define LNM 20

LL poww(LL a, LL n)
{
	if(n==0)return 1;
	if(n==1)return a%MOD;
	LL v=poww(a,n/2);
	v=(v*v)%MOD;
	if(n%2)
	v=(v*a)%MOD;
	
	return v;
}

LL vis[50];
int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	LL t;
	cin>>t;
	LL cc=0;
	LL c,d,v;
	vector<LL> V;
	vector<LL> tmp;
	while(t--)
	{
		cc++;
		memset(vis,0,sizeof(vis));
		cin>>c>>d>>v;
		V.clear();
		LL x;
		rep(i,1,d)
		{
			cin>>x;V.pb(x);
			vis[x]=1;
		}
	/*	for(int i=1;i<=v;++i)
		cout<<vis[i]<<" ";cout<<"\n";*/
		LL n=V.size();
		rep(msk,0,(1LL<<n)-1)
		{
			LL sum=0;
			rep(j,0,n-1)
			{
				if(msk&(1<<j))
				{
					sum+=V[j];
				}
				
			}
			if(sum<=v)
			vis[sum]=1;
		}
		LL num=0;
		rep(i,1,v)
		{
			if(vis[i]==0)
			{
		//		cout<<i<<"\n";
				num++;tmp.clear();
				rep(j,0,v)
				if(vis[j]&&i+j<=v)
				tmp.pb(i+j);
				rep(j,0,tmp.size()-1)
				vis[tmp[j]]=1;
			}
		}
		cout<<"Case #"<<cc<<": "<<num<<"\n";
		
	}
	
	
	return 0;
}
