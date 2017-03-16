#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstring>
#include <cmath>
#include <climits>
#include <ctime>
#include <cctype>
#include <fstream>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

#define INF INT_MAX
#define LL_INF LLONG_MAX

int K;
int L;
int S;
string keyboard;
string target;
int total;
int hi;

void dfs(int n, string s) {
    if (n == S) {
        int cnt = 0;
        for (int i = 0; i <= S - L; i++) {
            bool b = true;
            for (int j = i; j < i + L; j++) {
                if (s[j] != target[j - i]) {
                    b = false;
                    break;
                }
            }
            if (b) {
                cnt++;
            }
        }
        total += cnt;
        hi = max(hi, cnt);
        return ;
    }
    for (int i = 0; i < K; i++) {
        dfs(n + 1, s + keyboard[i]);
    }
}

double solve() {
    string s;
    dfs(0, s);
    int sum = 1;
    for (int i = 0; i < S; i++) {
        sum *= K;
    }
    return (double)hi - (double)total / sum;
}

//#define SAMPLE
//#define LARGE

int main() {

#ifdef SAMPLE
    ifstream in("B-sample.in");
    FILE *fout = fopen("B-sample.out", "w");
#else
#ifndef LARGE
    ifstream in("B-small-attempt0.in");
    FILE *fout = fopen("B-small-attempt0.out", "w");
#else
    ifstream in("B-large.in");
    FILE *out = fopen("B-large.out", "w");
#endif
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> K >> L >> S;
        in >> keyboard;
        in >> target;
        total = 0;
        hi = 0;
        double ret = solve();
        fprintf(fout, "Case #%d: %.7f\n", t + 1, ret);
    }
    return 0;
}
