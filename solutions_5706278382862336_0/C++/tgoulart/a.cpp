#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

void solveTestCase(int testCase);

int main(int argc, char *argv[]) {
    int T;
    cin >> T;
    for (int i=1; i <= T; ++i) {
        solveTestCase(i);
    }

	return 0;
}

// Code begins

void solveTestCase(int testCase) {
    string line;
    cin >> line;
    long long num = 0;
    long long den = 0;
    sscanf(line.c_str(), "%lld/%lld", &num, &den);

    for (long long div = 2; div * div <= den; ++div) {
        while (num % div == 0 && den % div == 0) {
            num /= div;
            den /= div;
        }
    }

    cout << "Case #" << testCase << ": ";

    if (__builtin_popcountll(den) != 1) {
        cout << "impossible" << endl;
        return;
    }

    int ans = 1;
    while (num * 2 < den) {
        den /= 2;
        ++ans;
    }

    cout << ans << endl;
}
