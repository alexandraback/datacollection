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

using namespace std;

typedef unsigned long long ull;

//#define LARGE

ull A;
ull B;

vector<ull> number;

bool isPalindrome(ull n) {
    vector<int> v;
    while (n != 0) {
        v.push_back(n % 10);
        n /= 10;
    }
    int len = v.size();
    int mid = len / 2;
    for (int i = 0; i < mid; ++i) {
        if (v[i] != v[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

void init() {
    for (ull i = 1; i <= 10000000; i++) {
        if (isPalindrome(i)) {
            ull n = pow(i, 2.0);
            if (isPalindrome(n)) {
                number.push_back(n);
            }
        }
    }
}

int solve() {
    int cnt = 0;
    for (int i = 0; i < number.size(); i++) {
        if (A <= number[i] && number[i] <= B) {
            cnt++;
        }
    }
    return cnt;
}

int main() {

#ifndef LARGE
    FILE *in = fopen("C-small-attempt0.in", "r");
    FILE *out = fopen("C-small-attempt0.out", "w");
#else
    FILE *in = fopen("C-large.in", "r");
    FILE *out = fopen("C-large.out", "w");
#endif

    init();

    int T;
    fscanf(in, "%d", &T);
    for (int t = 0; t < T; t++) {
        fscanf(in, "%lld", &A);
        fscanf(in, "%lld", &B);
        int num = solve();
        fprintf(out, "Case #%d: %d\n", t + 1, num);
    }
    fclose(in);
    fclose(out);
    return 0;
}
