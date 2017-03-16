#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

set<tuple<int, int, int>> res;
map<tuple<int, int>, int> jp;
map<tuple<int, int>, int> js;
map<tuple<int, int>, int> ps;
int j, p, s, k;

int main()
{
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		res.clear();
		jp.clear();
		js.clear();
		ps.clear();
		cin >> j >> p >> s >> k;

		for(int x = 0; x < j; ++x) {
			for(int y = 0; y < p; ++y) {
				for(int z = 0; z < s; ++z) {	
					auto a = make_tuple(x, y);
					auto b = make_tuple(x, z);
					auto c = make_tuple(y, z);
					if(jp[a] == k) continue;
					if(js[b] == k) continue;
					if(ps[c] == k) continue;

					res.emplace(x, y, z);
					jp[a]++;
					js[b]++;
					ps[c]++;
				}
			}
		}

		for(auto& a : res) {
			cout << get<0>(a) + 1 << ' ' << get<1>(a) + 1 << ' ' << get<2>(a) + 1 << endl;
		}
	}
}
