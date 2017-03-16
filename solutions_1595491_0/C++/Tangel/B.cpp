//Problem B. Dancing With the Googlers
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
	int T, N, S, p, score;

	ifstream in("B-small-attempt0.in");
	ofstream out("B-small-attempt0.out");

	in >> T;
	for (int cs = 1; cs <= T; cs ++) {
		out << "Case #" << cs << ": ";

		in >> N >> S >> p;
		int cnt = 0;
		for (int i = 0; i < N; i ++) {
			in >> score;
			int high = 0;
			high = score / 3;
			if (score % 3) high ++;
			if (high >= p) cnt ++;
			else {
				if (S) {
					high = score / 3;
					if (score % 3 == 0 && high > 0) high ++;
					if (score % 3 == 2) high += 2;
					if (high >= p) {
						cnt ++;
						S --;
					}
				}
			}
		}
		out << cnt << endl;
	}
	return 0;
}
