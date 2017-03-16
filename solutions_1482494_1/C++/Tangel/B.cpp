//Problem A. Password Problem
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

int a[1001], b[1001];
int main() {
	int T, N;

	ifstream in("B-large.in");
	ofstream out("B-large.out");
	//ifstream in("C-large.in");
	//ofstream out("C-large.out");

	in >> T;
	for (int cs = 1; cs <= T; cs ++) {
		out << "Case #" << cs << ": ";

		in >> N;
		for (int i = 0; i < N; i ++) 
			in >> a[i] >> b[i];
		vector<int> valid(N, 3);
		int left = N, time = 0;
		int cur = 0;
		bool no_answer = false;
		while (left > 0) {
			int c = -1;
			for (int i = 0; i < N; i ++) {
				if (valid[i] & 2) {
					if (b[i] <= cur) {
						left --;
						cur += (valid[i]&1) ? 2 : 1;
						c = i;
						time ++;
						valid[i] = 0;
						break;
					}
				}
			}
			if (c == -1) {
				int diff = -1;
				for (int i = 0; i < N; i ++) {
					if (valid[i] & 1) {
						if (a[i] <= cur) {
							if (diff < b[i] - a[i]) {
								diff = b[i] - a[i];
								c = i;
							}
						}
					}
				}
				if (c == -1) {
					no_answer = true;
					break;
				}
				valid[c] &= 2;
				cur += 1;
				time ++;
			}
		}

		if (no_answer) out << "Too Bad" << endl;
		else out << time << endl;
	}
	return 0;
}
