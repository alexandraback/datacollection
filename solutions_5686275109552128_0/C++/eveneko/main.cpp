#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include <sstream>
#include <set>
#include <cmath>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <cstdio>
//#include <cstdlib>
#include <cstring>
#include <numeric>
#include <bitset>
#include <deque>
#include <memory>

const long long LINF = (5e17);
const int INF = 1000000000;
#define EPS 1e-7
const int MOD = 1000000007;

using namespace std;

int solve(int N, vector<int> &P) {
	int res = INF;
	int M = *max_element(P.begin(), P.end());
	for (int m=1; m<=M; ++m) {
		int val = m;
		for (int i=0; i<N; ++i) {
			if (P[i] > m)
				val += (P[i]-1) / m;
		}
		res = min(res, val);
	}
	return res;
}

int main() {
	ifstream ifs("/Users/iseki/Downloads/input.txt");
	ofstream ofs("/Users/iseki/Downloads/output.txt");
	int T;
	ifs >> T;
	for (int i=1; i<=T; ++i) {
		int N;
		ifs >> N;
		vector<int> P(N);
		for (int i=0; i<N; ++i)
			ifs >> P[i];
		ofs << "Case #" << i << ": " << solve(N, P) << endl;
	}
}