#include <bits/stdc++.h>

using namespace std;

ifstream fin("C.in");
ofstream fout("output.out");

// #define fin cin
// #define fout cout

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int t;
	fin >> t;
	int u = 0;
	while (u++ < t)
	{
		fout << "Case #" << u << ": ";
		int j, p, s, k;
		fin >> j >> p >> s >> k;
		map<pair<int, int>, int> jp, ps, js;
		vector<string> ans;
		int count = 0;
		for (int jn = 0; jn < j; ++jn)
		{
			for (int pn = 0; pn < p; ++pn)
			{
				for (int sn = 0; sn < s; ++sn)
				{
					pair<int, int> x(jn, pn), y(pn, sn), z(jn, sn);
					if (js[z] >= k || ps[y] >= k || jp[x] >= k) continue;
					js[z]++;
					ps[y]++;
					jp[x]++;
					count++;
					ans.push_back(to_string(jn + 1) + " " + to_string(pn + 1) + " " + to_string(sn + 1));
				}
			}
		}
		fout << count << endl;
		for (int i = 0; i < ans.size(); ++i)
		{
			fout << ans[i] << endl;
		}
	}
	return 0;
}