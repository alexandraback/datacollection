#include <map>
#include <set>
#include <stdio.h>
#include <iostream>

using namespace std;

typedef long long ll;

set <ll> numset;
map <ll, ll> nummap;

bool check(ll n)
{
	string s;
	s = "";
	while(n > 0)
	{
		s += char(n % 10 + '0');
		n /= 10;
	}
	int l = s.length();
	for(int i = 0 ; i < l / 2 ; i++)
	{
		if(s[i] != s[l - i - 1]) return false;
	}
	return true;
} 

void init()
{
	numset.clear();
	for(ll i = 1 ; i <= 10000000 ; i++)
	{
		if(check(i) && check(i * i))
			numset.insert(i * i);
	}
	ll k = 0;
	nummap.clear();
	set<ll>::iterator it;
	for(it = numset.begin() ; it != numset.end() ; it++)
	{
		k++;
		nummap.insert(make_pair<ll, ll>(*it, k));
	}
	nummap.insert(make_pair<ll, ll>(0, 0));
}
		

int main()
{
	freopen("QC.in", "r", stdin);
	freopen("QC.out", "w", stdout);
	init();
	int T;
	cin >> T;
	for(int tt = 1 ; tt <= T ; tt++)
	{
		ll a, b;
		cin >> a >> b;
		map<ll, ll>::iterator it1, it2;
		it1 = nummap.lower_bound(a);
		it2 = nummap.upper_bound(b);
		it2--;
		cout << "Case #" << tt << ": " << it2->second - it1->second + 1 << endl;
	}
	return 0;
}

