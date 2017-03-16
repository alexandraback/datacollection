#include<iostream>
#include<algorithm>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<deque>
#include<cctype>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<sstream>
using namespace std;
#define FOR(i, a, b) for(int i=a; i<b; ++i)
#define FORC(i, a, b) for(int i=a; i<=b; ++i)
#define FORD(i, a, b) for(int i=a-1; i>=b; --i)
#define FORDC(i, a, b) for(int i=a; i>=b; --i)
#define endl '\n'
#define pb push_back
#define size(v) (int)((v).size())
#define all(v) (v).begin(), (v).end()
#define DREP(v) sort(all(v)); v.erase(unique(all(v)), (v).end())
#define F first
#define S second
#define mp make_pair
#define VI vector<int>
#define index(a, val) (lower_bound(all(a), val)-(a).begin())
#define iter(i, c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define PII pair<int, int>
#define ll long long
#define ini(arr, val) memset(arr, val, sizeof(arr))
#define debug(a) cerr<<"DEBUG: "<<#a<<" = "<<a<<endl
#define deb debug("gauss")
#define ld long double

ld comp(int n, int r)
{
	ld ans = 1.0;
	int run1 = 1, run2 = 1;
	for(int i = 1; i<=n; ++i)
	{
		ans *= (ld)i;
		if(run1 <= r) {ans /= (ld)run1; ++run1; }
		if(run2 <= n-r) { ans /= (ld)run2; ++run2; }
		ans /= 2.0;
	}
	return ans;
}

ld ans(int n, int x, int y)
{
	int odd = 1, sum = 1;
	while(sum <= n)
	{
		sum += odd + 1 + odd + 2;
		odd += 2;
	}
	odd -= 2; sum -= odd + 1 + odd + 2;
	++odd;
	if(abs(x) + abs(y) < odd ) return (ld)1.0;
	else if(abs(x) + abs(y) > odd) return (ld)0.0;
	int rem = n - sum; ++y;
	if(rem < y) return (ld)0.0;
	ld ans = 0.0; ++odd;
	if(y == odd)
	{
		if(rem != 2*odd -1)
			return 0.0;
		return 1.0;
	}
	if(rem >= 2*odd -1) return 1.0;
	FORC(i, y, rem)
	{
		ans += comp(rem, i);
	}
	return ans;
}
int main()
{
	int tourist; cin>>tourist;
	FORC(i, 1, tourist)
	{
		int n, x, y; cin>>n>>x>>y;
		cout<<"Case #"<<i<<": "<<setprecision(6)<<ans(n, x, y)<<endl;
	}
	return 0;
}