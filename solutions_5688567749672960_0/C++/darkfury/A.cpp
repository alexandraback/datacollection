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
#define MOD 1000000007
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
LL dp[1000006];
LL rev(LL a)
{
	LL sum=0;
	while(a)
	{
		sum=sum*10+(a%10);
		a/=10;
	}
	return sum;
}
int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	LL t;
	cin>>t;
	int cc=0;
	for(int i=1;i<=1000003;++i)
	{
		dp[i]=MOD;
	}
	dp[1]=0;
	for(int i=1;i<=1000000;++i)
	{
		dp[i+1]=min(dp[i+1],dp[i]+1);
		dp[rev(i)]=min(dp[rev(i)],dp[i]+1);
	}
	while(t--)
	{
		cc++;
		
		LL n;
		cin>>n;
		
		
		
		cout<<"Case #"<<cc<<": "<<dp[n]+1<<"\n";
		
	}
	
	
	return 0;
}
