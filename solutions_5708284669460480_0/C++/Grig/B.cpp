#include <functional>
#include <algorithm>
#include <strstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int n, m, s;

string keys, target;
string curs;
int mx;
int tcnt;
int sum;

void bf(int pos)
{
	if (pos == s)
	{
		int tmp = 0;
		for (int i = 0; i <= s - m; ++i)
			if (curs.substr(i, m) == target)
				++tmp;
		mx = max(mx, tmp);
		++tcnt;
		sum += tmp;
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			curs[pos] = keys[i];
			bf(pos + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("B-small-attempt1.out", "w", stdout);
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		
		cin >> n >> m >> s;
		cin >> keys >> target;
		n = keys.size();
		m = target.size();
		vector<int> cnt(30, 0);
		for (char c : keys)
			cnt[c - 'A']++;

		curs.resize(s);
		mx = tcnt = sum = 0;

		bf(0);
		double brute = mx - (double)sum / tcnt;
		printf("Case #%d: %.8lf\n", t, brute);
		continue;

		bool bad = 0;
		for ( char c: target )
			if (cnt[c - 'A'] == 0)
			{
				bad = 1;
				break;
			}
		if (bad)
		{
			printf("Case #%d: 0.00000000\n", t);
			continue;
		}

		double p = 1;
		for (char c : target)
			p *= (double)cnt[c - 'A'] / n;
	//	for (char c : target)
		//	p /= n;
		double mexp = (s - m + 1) * p;
		int mx = -1;
		for (int i = 1; i < m; ++i)
		{
			int j = 0;
			for (; i + j < m; ++j)
				if (target[i] != target[j])
					break;
			if (i + j == m)
			{
				mx = (s - m + i) / i;
				break;
			}
		}
		if (mx == -1)
			mx = s / m;

		if (abs(brute - (mx - mexp)) > 1e-6)
		{
			cerr << "BAD: correct " << brute << " got " << mx - mexp << endl;
		}

		printf("Case #%d: %.8lf\n", t, mx - mexp);
	}

	return 0;
}