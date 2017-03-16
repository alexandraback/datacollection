//be naame khodaa

#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int f[1005];
int cnt[1005];

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	for (int it = 1; it <= t; it++)
	{
		for (int i = 'A'; i <= 'Z'; i++)
			cnt[i] = 0;
		double Max = 0, E = 0;
		int kn, ln, s;
		string k, l;
		cin >> kn >> ln >> s;
		cin >> k >> l;
		bool one = true;
		for (int i = 0; i < l.size(); i++)
		{
			if (cnt[l[i]]) continue;
			for (int j = 0; j < k.size(); j++)
				if (k[j] == l[i])
					cnt[l[i]]++;
			one &= (cnt[l[i]] > 0);
		}
		if (one)
		{
			f[0] = -1;
			for (int i = 1; i <= ln; i++)
			{
				f[i] = f[i-1];
				while (f[i] >= 0 && l[f[i]] != l[i-1])
					f[i] = f[f[i]];
				f[i]++;
			}
			Max = (s - ln)/(ln-f[ln]) + 1;
			double prob = 1;
			for (int i = 0; i < ln; i++)
				prob *= 1.0*cnt[l[i]]/kn;
			E = (s - ln + 1)*prob;
		}
		cout << "Case #" << it << ": " << setprecision(10) << fixed << Max - E << endl;
	}
    return 0;
}
