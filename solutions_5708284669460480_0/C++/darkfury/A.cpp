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

ld freq[26];
int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	LL t;
	cin>>t;
	LL cc=0;
	LL k,l,s;
	
	while(t--)
	{
		cc++;
		cin>>k>>l>>s;
		k=(long double)(k);
		l=(long double)(l);
		s=(long double)(s);
		
		for(int i=0;i<26;++i)
		freq[i]=0.0;
		string a,b;
		cin>>a>>b;
		for(int i=0;i<a.size();++i)
		{
			freq[a[i]-'A']+=(1.0);
		}
		for(int i=0;i<26;++i)
		freq[i]/=k;
		
		int len=0;
		for(int j=b.size()-1;j>=0;--j)
		{
			int fl=0;
			for(int i=0;i<b.size();++i)
			{
				if(i+(b.size()-j)>=b.size())break;
				if(b[i]!=b[i+(b.size()-j)])
				fl=1;
			}
			if(fl==0)
			{
				len=b.size()-j;break;
			}
			
		}
	//	cout<<len<<"\n";
		ld maxi=1.0;
		maxi+=(s-(b.size()))/len;
		ld prob=1.0;
		for(int i=0;i<b.size();++i)
		{
			prob*=freq[b[i]-'A'];
		}
//		cout<<prob;
		if(prob==0.0)maxi=0.0;
	//	cout<<maxi;
		
		ld anse=maxi-(long double)(max((s-b.size()+1),0LL))*prob;
		//anse=maxi-anse;
		cout<<"Case #"<<cc<<": "<<setprecision(14)<<fixed<<showpoint<<anse<<"\n";
		
	}
	
	
	return 0;
}
