#include <bits/stdc++.h>

#define debug(a)

using namespace std;

typedef long long int ll;

void brut();

ll rev(ll x)
{
	ll wyn = 0;
	while(x)
	{
		wyn *= 10;
		wyn += x % 10;
		x /= 10;
	}
	return wyn;
}

ll policz(ll n, const vector<ll> & v)
{
	ll wyn = 1ll;
	ll liczba = 1ll;

	for(ll x : v)
	{
		wyn += x - liczba + 1;
		if(x == n || x == rev(x))
			wyn--;
		liczba = rev(x);
	}

	return wyn + n - liczba;
}

int odl[1000005];

ll przyp()
{
	ll n;
	scanf("%lld", &n);
	if(n <= 100)
		return odl[n];
	
	vector<int> cyf;
	ll m = n - 1;
	while(m)
	{
		cyf.emplace_back((int) (m % 10));
		m /= 10;
	}

	reverse(cyf.begin(), cyf.end());

	debug( for(int i : cyf) printf("%d ", i); printf("\n"); )

	ll liczba = 91;
	int c = 2;

	vector<ll> liczby;
	liczby.emplace_back(19ll);

	ll pot = 10;
	ll dzi = 9;
	while(c + 1 < (int) cyf.size())
	{
		pot *= 10;
		if(c % 2)
			dzi = (dzi * 10 + 9);
		c++;

		liczby.emplace_back(pot + dzi);
		liczba = rev(pot + dzi);
	}

	pot *= 10;
	dzi = 0;
	for(int i = c / 2; i >= 0; i--)
		dzi = (dzi * 10) + cyf[i];
	
	liczby.emplace_back(pot + dzi);

	debug( for(ll x : liczby) printf("%lld ", x); printf("\n"); )

	return policz(n, liczby);
}

int main()
{
	brut();
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++)
		printf("Case #%d: %lld\n", i, przyp());
	return 0;
}


// brut

const int N = 100000;

void brut()
{
	set< pair<int, int> > nic;
	for(int i = 1; i <= N; i++)
	{
		odl[i] = i;
		nic.emplace(i, i);
	}
	auto dorzuc = [&nic] (int w, int o) {
		if(odl[w] > o)
		{
			nic.erase(make_pair(odl[w], w));
			odl[w] = o;
			nic.emplace(odl[w], w);
		}
	};
	while(!nic.empty())
	{
		auto p = *nic.begin();
		nic.erase(nic.begin());
		int w = p.second;
		int o = p.first;

		if(w >= N)
			break;

		dorzuc(w + 1, o + 1);
		dorzuc(rev(w), o + 1);
	}
}
