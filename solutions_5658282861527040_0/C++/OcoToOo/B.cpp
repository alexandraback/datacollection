#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <limits.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <float.h>
#include <fstream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;

int A;
int B;
int K;

vector<int> v;

int solve() {
    int ret = 0;
    for (int a = 0; a < A; a++) {
        for (int b = 0; b < B; b++) {
            int n = a & b;
            if (n < K) {
                ret++;
            }
        }
    }
    return ret;
}

//#define LARGE

int main() {

#ifndef LARGE
    ifstream in("B-small-attempt0.in");
    ofstream out("B-small-attempt0.out");
#else
    ifstream in("B-large-attempt.in");
    ofstream out("B-large-attempt.out");
#endif

    int T; in >> T;
    for (int t = 0; t < T; t++) {
        in >> A >> B >> K;
        out << "Case #" << t + 1 << ": " << solve() << endl;
    }
    return 0;
}
