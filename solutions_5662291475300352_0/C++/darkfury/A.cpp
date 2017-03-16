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

LL rev(LL a)
{
	LL sum=0;
	while(a)
	{
		sum*=10;
		sum+=(a%10);
		a/=10;
	}
	return sum;
}
LL dig(LL a)
{
	LL cnt=0;
	while(a)
	{
		cnt++;
		a/=10;
	}
	return cnt;
}


LL mat[50][50];
int main()
{
	freopen("inputA.txt","r",stdin);
	freopen("outputA.txt","w",stdout);
	LL t;
	cin>>t;
	LL cc=0;LL r,c,n;
	while(t--)
	{
		cc++;
		LL n;
		cin>>n;
		
		LL cn=0;
		if(n==1)
		{
			ld d,h,m;
			cin>>d>>h>>m;
			if(h==1)
			{
				cn=0;
			}
			else
			{
				ld sp1=360.0/m;
				ld sp2=360.0/(m+1);
				ld tim2=(360.0-d)/sp2;
				cn+=floor((tim2*sp1-(360.0-d))/360.0);
				if(cn<0)cn=0;
			}
		}
		else
		{
			ld d1,h1,m1,d2,h2,m2;
			cin>>d1>>h1>>m1>>d2>>h2>>m2;
			if(m1>m2)
			{
				swap(d1,d2);
				swap(h1,h2);
				swap(m1,m2);
			}
			
			ld sp1=(360.0)/m1;
			ld sp2=(360.0)/m2;
			ld tim2=(360.0-d2)/sp2;
			ld dis=tim2*sp1;
			dis-=(360.0-d1);
			cn+=floor((dis)/360.0);
			if(cn<0)cn=0;
		}	
		
		cout<<"Case #"<<cc<<": "<<cn<<"\n";
		
	}
	
	
	return 0;
}
