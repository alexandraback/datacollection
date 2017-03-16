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

LL solve(LL n) {
    LL ret = 0;
    LL i = 0;
    while (i != n) {
        stringstream ss;
        ss << i;
        string s = ss.str(); 
        reverse(s.begin(), s.end());
        LL ii = stoll(s, 0);
        if (ii > i && ii <= n) {
            i = ii;
        } else {
            i++;
        }
        ret++;
    }
    return ret;
}

//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("A-small-attempt0.in");
    ofstream out("A-small-attempt0.out");
#else
    ifstream in("A-large.in");
    ofstream out("A-large.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        LL N; in >> N;
        LL ret = solve(N);
        out << "Case #" << t + 1 << ": " << ret << endl;
        cout << "Case #" << t + 1 << ": " << ret << endl;
    }
    getchar();
    return 0;
}
