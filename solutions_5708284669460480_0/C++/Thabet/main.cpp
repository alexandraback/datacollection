#include <map>
#include <iostream>
#include <iomanip>
using namespace std;

int calc_overlaps(string s) {
	int overlaps = 0;
	for (int i = 1; i < s.length(); ++i)
	{
		if (s[0] == s[i]) {
			overlaps = 1;
			for (int j = 1; j < s.length(); ++j)
			{
				if (j + i == s.length()) {
					return overlaps;
				}
				if (s[j] == s[i + j]) {
					overlaps++;
				}
				else {
					overlaps = 0;
					break;
				}
			}
		}
	}
	return overlaps;
}

int main() {
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
	int t, k, l, s, max, ans, cnt = 0, overlaps;
	string keys, target, optimum, lap;
	bool can;
	map<char, int> mp;
	double p;
	cin >> t;
	while (t--)
	{
		cnt++;
		mp.clear();
		p = 1;
		can = 1;
		cin >> k >> l >> s >> keys >> target;
		for (int i = 0; i < k; ++i)
		{
			mp[keys[i]]++;
		}
		for (int i = 0; i < target.length(); ++i)
		{
			if (mp[target[i]] == 0) {
				can = 0;
				break;
			}
		}
		if (!can) {
			max = 0;
		}
		else {
			overlaps = calc_overlaps(target);
			max = 1 + (s - target.length()) / (target.length() - overlaps);
			optimum = target;
			lap = target.substr(overlaps, target.size());
			int idx = 0;
			for (int i = 0; i < s - optimum.length(); ++i)
			{
				optimum.append(1, lap[idx]);
				idx++;
				if (idx == lap.length())idx = 0;
			}
			for (int i = 0; i < optimum.length() - (optimum.length() % target.length()); ++i)
			{
				p *= 1.0 * mp[optimum[i]] / keys.length();
			}
		}
		double h = optimum.length() / target.length();
		cout << "Case #" << cnt << ": ";
		p *= h;
		printf("%.8f\n", max * (1 - p));
	}

	return 0;
}