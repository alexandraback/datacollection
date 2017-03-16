#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <list>
#include <stack>
#include <cstdio>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <ctime>
#include <cstring>

#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long int LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

int main() {
	ifstream fin("b1.in");
	ofstream fout("b1.out");
	int t;
	fin >> t;
	for (int tt = 1; tt <= t; ++tt) {
		int x,y;
		fin >> x >> y;
		int k;
		set< pair<int,pair<int,int> > > vis;
		queue< pair<int,pair<int,int> > > sor;
		sor.push(make_pair(0,make_pair(0,0)));
		vis.insert(sor.front());
		while (true) {
			k = sor.front().first;
			int cx = sor.front().second.first;
			int cy = sor.front().second.second;
			sor.pop();
			if (cx == x && cy == y) break;
			int step = k + 1;
			pair<int,pair<int,int> > np;
			np.first = step;
			np.second.first = cx + step;
			np.second.second = cy;
			if (!vis.count(np)) {
				vis.insert(np);
				sor.push(np);
			}
			np.second.first = cx - step;
			np.second.second = cy;
			if (!vis.count(np)) {
				vis.insert(np);
				sor.push(np);
			}
			np.second.first = cx;
			np.second.second = cy + step;
			if (!vis.count(np)) {
				vis.insert(np);
				sor.push(np);
			}
			np.second.first = cx;
			np.second.second = cy - step;
			if (!vis.count(np)) {
				vis.insert(np);
				sor.push(np);
			}
		}
		stack<char> res;
		pair<int,pair<int,int> > np;
		np.first = k;
		np.second.first = x;
		np.second.second = y;
		while (np.first != 0) {
			int step = np.first;
			x = np.second.first;
			y = np.second.second;
			np.first = np.first - 1;
			np.second.first = x + step;
			if (vis.count(np)) {
				res.push('W');
				continue;
			}
			np.second.first = x - step;
			if (vis.count(np)) {
				res.push('E');
				continue;
			}
			np.second.first = x;
			np.second.second = y + step;
			if (vis.count(np)) {
				res.push('S');
				continue;
			}
			np.second.second = y - step;
			if (vis.count(np)) {
				res.push('N');
				continue;
			}
			np.second.second = y;
			cerr << "WTF\n";
		}

		fout << "Case #" << tt << ": ";
		while (!res.empty()) {
			fout << res.top();
			res.pop();
		}
		fout << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
