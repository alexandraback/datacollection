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

int R;
int C;
int W;

int solve() {
    int rest = W;
    int ret = 0;
    while (rest >= W * 2) {
        ret++;
        rest -= W;
    }
    if (rest) {
        rest -= W;
        if (rest) {
            while (1) {
                ret++;
                rest = (rest + 1) / 2;
                if (rest <= 1) {
                    break;
                }
            }
        }
    }
    ret += W - 1;
    return ret;
}

//#define SAMPLE
//#define LARGE

int main() {

#ifdef SAMPLE
    ifstream in("A-sample.in");
    ofstream out("A-sample.out");
#else
#ifndef LARGE
    ifstream in("A-small-attempt3.in");
    ofstream out("A-small-attempt3.out");
#else
    ifstream in("A-large.in");
    ofstream out("A-large.out");
#endif
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> R >> C >> W;
        int ret = solve();
        cout << "Case #" << t + 1 << ": " << ret << endl;
        out << "Case #" << t + 1 << ": " << ret << endl;
    }
    getchar();
    return 0;
}
