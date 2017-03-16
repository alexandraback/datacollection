#include <stdio.h>
#include <vector>
#include <iostream>
// #define TEST

using namespace std;
typedef unsigned long long uint64;

int main()
{
	#ifndef TEST
	freopen("D-small-attempt5.in", "r", stdin);
	freopen("D-small-attempt5.out", "w", stdout);
	#endif
	ios_base::sync_with_stdio(0);

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int k, c, s;
		cin >> k >> c >> s;
		uint64 power[c + 1];
		power[0] = 1;
		for (int i = 1; i < c + 1; i++)
			power[i] = power[i - 1] * ((uint64)k);
		
		int index = 1;
		vector<uint64> result; 

		while (index <= k) {
			int last = min(k - index + 1, c);
			uint64 position = 1;
			for (int i = 1; i <= last; i++)
				position += (index + i - 2) * power[c - i];
			result.push_back(position);
			index += c;
		}

		cout << "Case #" << tt << ":";
		if (result.size() > s) {
			cout << " IMPOSSIBLE" << endl;
		} else {
			for (uint64 a : result)
				cout << " " << a;
			cout << endl;
		}
	}
}
