//azariamuh

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <cassert>
#include <map>
using namespace std;

int inf = 1000000000;
typedef long long LL;

#define forn(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define reset(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()

int T;
long long n;
long long MAXN = 100000000000000LL; //10^14
//long long MAXN = 10000000000LL; //10^10
vector<long long> beda;
long long dp[30000005];
map<long long,int> ix;

long long balik(long long k)
{
	long long res = 0;
	while (k > 0) 
	{
		res = res * 10 + (k % 10);
		k /= 10;
	}
	return res;
}

int main()
{
	scanf("%d",&T);
	long long now = 1;
	beda.push_back(now);
	while (1) {
		long long nxt = now * 10;
		for (long long i = now + 1; i < nxt; ++i) {
			long long add = i * nxt + 1;
			if (add > MAXN) goto selesai;
			beda.push_back(add);
			long long k = balik(add);
			if (k < add) beda.push_back(k);
		}
		for (long long i = now + 1; i < nxt; ++i) {
			long long add = i * nxt * 10 + 1;
			if (add > MAXN) goto selesai;
			beda.push_back(add);
			long long k = balik(add);
			if (k < add) beda.push_back(k);
		}
		now = now * 10;
	}
	selesai:;
	sort(beda.begin(),beda.end());
	beda.erase(unique(beda.begin(),beda.end()),beda.end());
	forn(i,0,beda.size()-1)
	{
		ix[beda[i]] = i;
		dp[i] = inf;
	}
	dp[0] = 1;
	forn(i,0,beda.size()-1)
	{
		//if (i % 1000 == 0) printf("%d\n",i);
		if (i != beda.size() - 1) dp[i + 1] = min(dp[i + 1],dp[i] + beda[i+1] - beda[i]);
		long long k = balik(beda[i]);
		if (ix.count(k) > 0) {
			int x = ix[k];
			dp[x] = min(dp[x],dp[i] + 1);
		}
		//printf("%d %lld %lld\n",i,beda[i],dp[i]);
	}
	forn(cases,1,T)
	{
		printf("Case #%d: ",cases);
		scanf("%lld",&n);
		int x = upper_bound(beda.begin(),beda.end(),n) - beda.begin() - 1;
		printf("%lld\n",dp[x] + n - beda[x]);
	}
	return 0;
}













