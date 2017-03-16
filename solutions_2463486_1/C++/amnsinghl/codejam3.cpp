#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <bitset>
#define SET(p)	 		memset(p,-1,sizeof(p))
#define CLR(p) 			memset(p,0,sizeof(p))
#define LL 				long long int
#define ULL		 		unsigned long long int
#define S(n)			scanf("%d",&n)
#define Sl(n)			scanf("%lld",&n)
#define Sf(n)			scanf("%lf",&n)
#define Ss(n)			scanf("%s",n)
#define INF				(int)1e9
#define LINF			(long long)1e18
#define EPS				1e-9
#define FOR(i,a,b)		for(int i=a;i<b;i++)
#define REP(i,n)		FOR(i,0,n)
using namespace std;
bool ispali(LL a)
{
	char str[100];
	sprintf(str,"%lld",a);
	string s=str;
	int i,j;
	for(i=0,j=s.size()-1;i<j;i++,j--)
		if(s[i]!=s[j])
			return 0;
	return 1;
}
vector<LL> v;
int main()
{
	int t,i,j,k,n,m;
	#ifndef ONLINE_JUDGE
	freopen("example.txt","r",stdin);
	freopen("op.txt","w",stdout);
	#endif
	for(i=0;i<=10000000;i++)
	{
		if(ispali(i)==0)
			continue;
		LL no=(LL)(i)*(LL)(i);
		if(ispali(no)==0)
			continue;
		v.push_back(no);
	}
	S(t);
	int zz=0;
	LL a,b;
	while(t--)
	{
		zz++;
		Sl(a);Sl(b);
		int ans=0;
		if(a>b)
			swap(a,b);
		for(i=0;i<v.size();i++)
		{
			//cout<<v[i]<<endl;
			if(v[i]>=a && v[i]<=b)
				ans++;
		}
		printf("Case #%d: %d\n",zz,ans);
		
		
	}
	return 0;
}
