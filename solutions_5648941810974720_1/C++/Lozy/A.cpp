#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;
string dg[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR",
		     "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[26], xx[10];
string doit(string s) {
    for (int i = 0; i < 26; ++i) cnt[i] = 0;
    int n = s.size();
    string res = "";
    for (int i = 0; i < n; ++i) ++cnt[s[i] - 'A'];
    xx[0] = cnt['Z' - 'A'];
    for (int i = 0; i < dg[0].size(); ++i) {
	int x = dg[0][i] - 'A';
	cnt[x] -= xx[0];
    }
    xx[6] = cnt['X' - 'A'];
    for (int i = 0; i < dg[6].size(); ++i) {
	int x = dg[6][i] - 'A';
	cnt[x] -= xx[6];
    }
    xx[7] = cnt['S' - 'A'];
    for (int i = 0; i < dg[7].size(); ++i) {
	int x = dg[7][i] - 'A';
	cnt[x] -= xx[7];
    }
    xx[4] = cnt['U' - 'A'];
    for (int i = 0; i < dg[4].size(); ++i) {
	int x = dg[4][i] - 'A';
	cnt[x] -= xx[4];
    }
    xx[2] = cnt['W' - 'A'];
    for (int i = 0; i < dg[2].size(); ++i) {
	int x = dg[2][i] - 'A';
	cnt[x] -= xx[2];
    }
    xx[5] = cnt['V' - 'A'];
    for (int i = 0; i < dg[5].size(); ++i) {
	int x = dg[5][i] - 'A';
	cnt[x] -= xx[5];
    }
    xx[8] = cnt['G' - 'A'];
    for (int i = 0; i < dg[8].size(); ++i) {
	int x = dg[8][i] - 'A';
	cnt[x] -= xx[8];
    }
    xx[9] = cnt['I' - 'A'];
    for (int i = 0; i < dg[9].size(); ++i) {
	int x = dg[9][i] - 'A';
	cnt[x] -= xx[9];
    }
    xx[1] = cnt['N' - 'A'];
    xx[3] = cnt['R' - 'A'];
    for (int i = 0; i < 10; ++i) for (int j = 0; j < xx[i]; ++j) res += ('0' + i);
    return res;
}
int T;
string S;
int main() {
    cin >> T;
    for (int t = 1; t <= T; ++t) {
	cin >> S;
	printf("Case #%d: %s\n", t, doit(S).c_str());
    }
    return 0;
}
