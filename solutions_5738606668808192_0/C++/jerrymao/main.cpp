#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

vector<int> primes;
bool sv[100000000];
int n, j;

bool isprime(long long v, vector<int>& x)
{
	for (int u: primes) if (v%u == 0 && v != u)
	{
		x.push_back(u);
		return false;
	}
	return true;
}

void solve()
{
	sv[0] = true;
	sv[1] = true;
	for (int i = 2;i <= 10000;i++) if (!sv[i])
	{
		primes.push_back(i);
		for (int k = i*i;k < 100000000;k+=i) sv[k] = true;
	}
	for (int i = 10001;i < 100000000;i++) if (!sv[i]) primes.push_back(i);
	scanf("%d%d", &n, &j);
	vector<pair<int, vector<int> > > ans;
	for (int u = 1;u < 65536;u+=2)
	{
		vector<int> tmp;
		for (int i = u;i;i/=2) tmp.push_back(i%2);
		bool ok = true;
		if (tmp.size() != n) ok = false;
		vector<int> div;
		for (int b = 2;b <= 10 && ok;b++)
		{
			long long oth = 0, exp = 1;
			for (int v: tmp)
			{
				oth += exp*v;
				exp *= b;
			}
			if (isprime(oth, div))
			{
				ok = false;
				break;
			}
		}
		if (ok) ans.emplace_back(u, div);
		if (ans.size() == j) break;
	}
	for (auto u: ans)
	{
		vector<int> tmp;
		for (int i = u.first;i;i/=2) tmp.push_back(i%2);
		reverse(tmp.begin(), tmp.end());
		for (int v: tmp) printf("%d", v);
		for (int v: u.second) printf(" %d", v);
		printf("\n");
	}
}

int main()
{
	int t; scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		fprintf(stderr, "\tCase #% 3d...", _); fflush(stdout);
		milliseconds start_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

		printf("Case #%d:\n", _);
		solve();

		milliseconds end_ti = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		long long time_used = end_ti.count() - start_ti.count();
		fprintf(stderr, " done\t% 6lldms\n", time_used); fflush(stdout);
	}
	fprintf(stderr, "\n\n\n");
	return 0;
}
