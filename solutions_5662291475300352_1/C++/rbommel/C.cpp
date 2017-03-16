#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>

#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm> 

using namespace std;

int N;
int D[123];
int H[123];
double M[123];
double pass[123][123];
double eps = 0.000001;
int k;

int prob(int i, int L) {
	double t = pass[i][L];
	t += eps;
	int sol = 0;
	for (int j = 0; j < k; j++) {
		if (t < pass[j][0]) {
			sol++;
		} else {
			int nu = 1;
			while (pass[j][nu] < t) {
				sol++;
				nu++;
				if (nu == 122)
					break;
			}
		}
	
	}
	return sol;
}

void doit() {
	cin >> N;
	k = 0;
	for (int i = 0; i < N; i++) {
		cin >> D[i] >> H[i] >> M[i];
		for (int j = 0; j < H[i]; j++) {
			for (int L = 0; L < 123; L++) {
				pass[k][L] = (M[i]+j)*(360.0-D[i])/360.0 + L*(M[i]+j);
			}
			k++;
		}
	}
	
	int opt = 100;
	for (int i = 0; i < k; i++) {
		for (int L = 0; L < 123; L++) {
			opt = min(opt, prob(i,L));
		}
	}
	cout << opt << '\n';
}

int main () {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		doit();
	}
	return 0;
}

