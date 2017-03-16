//Problem A. Safety in Numbers
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

double getNum(const vector<int>& J, int idx) {
	int sum = 0;
	foreach(x, J) sum += *x;
	double left = 0, right = 1.0;
	while (left + 0.000000001 < right) {
		double mid = (left + right) / 2;

		double tot = 0;
		for (int i = 0; i < J.size(); i ++) {
			if (i != idx) {
				if (J[i] < J[idx] + mid * sum) {
					tot += J[idx] + mid * sum - J[i];
				}
			}
		}
		if (tot < sum - mid * sum) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	return (double)left * 100.0;
}

int main() {
	int T, N;

	//ifstream in("A-small-attempt0.in");
	//ofstream out("A-small-attempt0.out");
	FILE *in = fopen("A-large.in", "r");	
	FILE *out = fopen("A-large.out", "w");

	fscanf(in, "%d", &T);
	for (int cs = 1; cs <= T; cs ++) {
		fprintf(out, "Case #%d:", cs);

		fscanf(in, "%d", &N);
		vector<int> J;
		for (int i = 0; i < N; i ++) {
			int x;
			fscanf(in, "%d", &x);
			J.push_back(x);
		}

		for (int i = 0; i < N; i ++) {
			fprintf(out, " %.6lf", getNum(J, i));
		}
		fprintf(out, "\n");
	}
	return 0;
}
