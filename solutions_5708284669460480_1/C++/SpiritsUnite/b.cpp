#include <bits/stdc++.h>

using namespace std;

int T;
int k, l, s, m;
char key[120], tar[120], gen[120];
int keyu[30], taru[30];

int f(int at)
{
	int ret = 0;
	if (at == s)
	{
		for (int i = 0; i < s - l + 1; i++)
		{
			int eq = true;
			for (int j = 0; j < l; j++)
				if (gen[i+j] != tar[j]) eq = false;
			if (eq) ret++;
		}
		m = max(ret, m);
		return ret;
	}
	for (int i = 0; i < k; i++)
	{
		gen[at] = key[i];
		ret += f(at+1);
	}
	return ret;
}

int main()
{
	cout.precision(8);
	cin >> T;
	for (int C = 1; C <= T; C++)
	{
		memset(keyu, 0, sizeof(keyu));
		memset(taru, 0, sizeof(taru));
		m = 0;
		cin >> k >> l >> s;
		for (int i = 0; i < k; i++)
		{
			cin >> key[i];
			keyu[key[i]-'A']++;
		}
		for (int i = 0; i < l; i++)
		{
			cin >> tar[i];
			taru[tar[i]-'A']++;
		}
		bool bad = false;
		for (int i = 0; i < 26; i++)
			if (taru[i] && !keyu[i]) bad = true;
		if (bad)
		{
			cout << "Case #" << C << ": 0.0\n";
			continue;
		}

		int len = 0;
		for (int i = 1; i < l; i++)
		{
			bool eq = true;
			for (int j = 0; j < i; j++)
				if (tar[j] != tar[l-i+j]) eq = false;
			if (eq) len = i;
		}
		m = 1 + (s - l) / (l - len);
		long double prod = s - l + 1;
		for (int i = 0; i < l; i++)
		{
			prod *= (long double)(keyu[tar[i]-'A']) / (long double)(k);
		}
		cout << "Case #" << C << ": " << fixed << m - prod << '\n';
	}
	return 0;
}

