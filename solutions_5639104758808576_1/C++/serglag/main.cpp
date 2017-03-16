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
		int s_max;
		in >> s_max;

		string s;
		in >> s;

		int ans = 0, standing = s[0] - '0';
		for (int i = 1; i <= s_max; ++i) {
			int needed = max(0, i - standing);
			ans += needed;
			standing += (needed + (s[i] - '0'));
		}

		out << "Case #" << c << ": " << ans << "\n";
	}

	return 0;
}