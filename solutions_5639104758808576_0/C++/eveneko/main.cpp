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

int solve(int N, string &S) {
	int res = 0;
	int sum = 0;
	for (int i=0; i<=N; ++i) {
		if (S[i] == '0')
			continue;
		if (i > sum) {
			res += i - sum;
			sum += i - sum;
		}
		sum += S[i] - '0';
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
		string S;
		ifs >> N >> S;
		int ans = solve(N, S);
		ofs << "Case #" << i << ": " << ans << endl;
	}
}