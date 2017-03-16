#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <numeric>
#include <list>

using namespace std;

typedef long long ll;

#define FOR(i, n) for(ll i = 0; i < (n); ++i)
#define SIZEOF(a) (sizeof(a)/sizeof((a)[0]))


string ToStr(ll x, ll n){
	string res;
	while(x){
		res.append(1, '0'+x%10);
		x/=10LL;
	}
	while(res.size() < n){
		res.append(1, '0');
	}
	reverse(res.begin(), res.end());
	return res;
}

bool IsOk(string& a, string& b){
	if(a.size() != b.size())
		return false;
	FOR(i,a.size()){
		if(a[i]=='?' || b[i]=='?')
			continue;
		if(a[i] != b[i])
			return false;
	}
	return true;
}

void SolveCase()
{
	string co, ja; cin >> co >> ja;
	ll n = 1000;
	ll sz = co.size();
	vector<pair<ll, pair<ll, ll> > > res;
	FOR(i,n) FOR(j,n){
		string a = ToStr(i, sz);
		string b = ToStr(j, sz);
		if(!IsOk(a, co) || !IsOk(b, ja))
			continue;
		ll dif = abs(i - j);
		res.push_back(make_pair(dif, make_pair(i, j)));
	}
	sort(res.begin(), res.end());
	cout << ToStr(res[0].second.first, sz) <<
		" " << ToStr(res[0].second.second, sz);
}

void test()
{
}

int main()
{
	//test();return 0;
	int t; cin >> t;
	FOR(i,t){
		cout << "Case #" << i+1 << ": ";
		SolveCase();
		cout << endl;
	}
	return 0;
}