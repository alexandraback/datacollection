//Problem C. Recycled Numbers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define foreach(itr, cont) for (typeof(cont.begin()) itr = cont.begin(); itr != cont.end(); itr++)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int main() {
	int T, N;

	ifstream in("C-small-attempt0.in");
	ofstream out("C-small-attempt0.out");
	//ifstream in("C-large.in");
	//ofstream out("C-large.out");

	in >> T;
	for (int cs = 1; cs <= T; cs ++) {
		out << "Case #" << cs << ":" << endl;

		in >> N;
		vector<int> input(N, 0);
		for (int i = 0; i < N; i ++) {
			in >> input[i];
		}
		vector<pair<int, int> > d(1 << N);
		for (int mask = 0; mask < (1 << N); mask ++) {
			int tot = 0;
			for (int j = 0; j < N; j ++) {
				if (mask & (1 << j)) {
					tot += input[j];
				}
			}
			d[mask].first = tot;
			d[mask].second = mask;
		}
		sort(d.begin(), d.end());
		//cout << "end of sort" << endl;
		int x = -1, y = -1;
		for (int i = 0; i < d.size();) {
			int j = i + 1;
			for (; d[i].first == d[j].first; j ++) {
				if (d[i].first == d[j].first && ((d[i].second & d[j].second) == 0)) {
					x = i;
					y = j;
					break;
				}
			}
			if (x != -1) break;
			i = j;
		}
		//cout << x << " " << d[x].first << " " << d[x].second << endl;
		//cout << y << " " << d[y].first << " " << d[y].second << endl;
		if (x == -1) out << "Impossible" << endl;
		else {
			bool first = true;
			for (int i = 0; i < N; i ++) {
				if (d[x].second & (1 << i)) {
					if (first) first = false;
					else out << " ";
					out << input[i];
				}
			}
			out << endl;
			first = true;
			for (int i = 0; i < N; i ++) {
				if (d[y].second & (1 << i)) {
					if (first) first = false;
					else out << " ";
					out << input[i];
				}
			}
			out << endl;
		}
	}
	return 0;
}
