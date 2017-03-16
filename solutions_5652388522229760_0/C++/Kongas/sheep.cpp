
#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t){
		long n;
		cin >> n;
		vector<int> count(10);
		long mul;
		long delim = 10000;
		for (mul = 1; mul < delim; ++mul){
			string num(to_string(mul * n));
			for (char c: num)
				count[c - '0'] = 1;
			bool fail = 0;
			for (int d: count)
				if (!d)
					fail = 1;

			if (! fail){
				cout << "Case #" << t + 1 << ": " << num << endl;
				break;
			}
		}
		if (mul == delim)
			cout << "Case #" << t + 1 << ": INSOMNIA" << endl;

	}
	return 0;
}
