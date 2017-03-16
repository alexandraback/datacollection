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

int dp[10005][10005];
int cnv[4][4] = {
	{ 1,  2,  3,  4},
	{ 2, -1,  4, -3},
	{ 3, -4, -1,  2},
	{ 4,  3, -2, -1}
};

int conv(char ch) {
	return ch - 'i' + 1;
}

void pre(string &S) {
	for (int i=0; i<S.size(); ++i) {
		int c = 1;
		bool plus = true;
		for (int j=i; j<S.size(); ++j) {
			c = cnv[c-1][conv(S[j])];
			if (c < 0) {
				plus = !plus;
				c = -c;
			}
			dp[i][j] = plus ? c : -c;
		}
	}
}

int main() {
	ifstream ifs("/Users/iseki/Downloads/input.txt");
	ofstream ofs("/Users/iseki/Downloads/output.txt");
	int T;
	ifs >> T;
	for (int num=1; num<=T; ++num) {
		int L,X;
		string s;
		ifs >> L >> X >> s;
		string S;
		for (int i=0; i<X; ++i)
			S.append(s);
		pre(S);
		int N = (int)S.size();
		bool ok = false;
		for (int i=1; i<S.size()-1 && !ok; ++i)
			for (int j=i+1; j<S.size() && !ok; ++j)
				if (dp[0][i-1] == 2 && dp[i][j-1] == 3 && dp[j][N-1] == 4)
					ok = true;
		ofs << "Case #" << num << ": " << (ok ? "YES" : "NO") << endl;
	}
}