#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

int ones(int i) { int j =0; while (i) { i &= i-1; ++j;} return j;}

vector<vector<int>> v;
vector<int> p[2];

bool Go(int i, vector<int>& was) {
	was[i] = 1;
	
	for (int next : v[i]) {
		if (p[1][next] == -1) {
			p[1][next] = i;
			p[0][i] = next;
			return true;
		} else if (was[p[1][next]] == 0) {
			if (Go(p[1][next], was)) {
				p[0][i] = next;
				p[1][next] = i;
				return true;
			}
		}
	}
}

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		int n;
		ifs >> n;
		vector<string> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			ifs >> a[i] >> b[i];
		}

		map<string, int> ma, mb;
		for (string& s : a) {
			if (ma.count(s) == 0) {
				int sz = ma.size();
				ma[s] = sz;
			}
		}
		for (string& s : b) {
			if (mb.count(s) == 0) {
				int sz = mb.size();
				mb[s] = sz;
			}
		}
		v.assign(ma.size(), {});
		for (int i = 0; i < n; ++i) {
			v[ma[a[i]]].push_back(mb[b[i]]);
		}
		p[0].assign(ma.size(), -1);
		p[1].assign(mb.size(), -1);

		int res = 0;
		for (int i = 0; i < ma.size(); ++i) {
			vector<int> was(ma.size(), 0);
			if (Go(i, was)) ++res;
		}

		for (int i = 0; i < ma.size(); ++i) {
			if (p[0][i] == -1) ++res;
		}
		for (int i = 0; i < mb.size(); ++i) {
			if (p[1][i] == -1) ++res;
		}

		ofs << "Case #" << test+1 << ": " << n-res << endl;
	}
	return 0;
}
