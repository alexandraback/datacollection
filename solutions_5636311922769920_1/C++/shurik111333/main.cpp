#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;

ifstream fin("in.in");
ofstream fout("out.txt");
const string impos = "IMPOSSIBLE";


ll pow1(ll a, ll b)
{
	if (b == 0)
		return 1;
	if ((b & 1) == 1)
		return a * pow1(a, b - 1);
	else
	{
		ll k = pow1(a, b / 2);
		return k * k;
	}
}

void printSmall(int s)
{
	for (int i = 1; i <= s; i++)
		fout << i << " ";
}

set<ll> st;
int k, c, s;

ll getIndex()
{
	ll ind = *st.begin();
	ll ind1 = ind;
	st.erase(st.begin());
	for (int i = 2; i <= c; i++)
	{
		if (!st.empty())
		{
			ind1 = *st.begin();
			st.erase(st.begin());
		}
		else
			ind1 = 1;
		ind = k * (ind - 1) + ind1;
	}
	return ind;
}

int main()
{
	int t;
	fin >> t;
	for (int i = 1; i <= t; i++)
	{
		if (i != 1)
			fout << "\n";
		fin >> k >> c >> s;
		fout << "Case #" << i << ": ";
		ll min1 = ((k % c) == 0) ? k / c : k / c + 1;
		if (s < min1)
		{
			fout << impos;
			continue;
		}
		st.clear();
		for (int j = 1; j <= k; j++)
			st.insert(j);
		for (int k1 = 0; k1 < min1; k1++)
			fout << getIndex() << " ";
	}
	return 0;
}
