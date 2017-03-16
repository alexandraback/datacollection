#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <map>
#include <numeric>
#include <fstream>

using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);

	ifstream in("d:\\input.txt");
	ofstream out("d:\\output.txt");

	int t;
	in >> t;

	for (int c = 1; c <= t; ++c) {
		int d;
		in >> d;

		vector<int> p(d);
		for (int i = 0; i < d; ++i)
			in >> p[i];

		int m = *max_element(p.begin(), p.end());
		vector<int> f(m+1);

		int ans = m;
		for (int i = 1; i <= m; ++i) {
			for (int j = 0; j < d; ++j) {
				int x = (p[j] % i == 0 ? p[j] / i - 1 : p[j] / i);
				f[i] += x;
			}
			ans = min(ans, f[i] + i);
		}

		out << "Case #" << c << ": " << ans << "\n";
	}

	return 0;
}