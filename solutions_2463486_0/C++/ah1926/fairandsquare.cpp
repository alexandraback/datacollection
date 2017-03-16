#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

typedef long long int64;
typedef vector<int>::iterator it;

const int oo = 0x3f3f3f3f;
const int MAX_VALUE = 1e7 + 5;

vector<int64> PalindromicSquares;
vector<int> PalindromicRoots;

inline int64 Reverse(int64 value) {
    int64 revValue;
    for (revValue = 0; value > 0; value /= 10)
        revValue = revValue * 10 + value % 10;
    return revValue;
}

inline bool IsPalindrome(const int64 value) {
    return value == Reverse(value);
}

inline int Count(const int64 maxValue) {
    int palindromeCount = 0;
    for (vector<int64>::iterator value = PalindromicSquares.begin(); value != PalindromicSquares.end(); ++value)
        if (*value <= maxValue)
            ++palindromeCount;
    return palindromeCount;
}

void Preprocess() {
    for (int i = 1; i <= MAX_VALUE; ++i) {
        if (IsPalindrome(i) && IsPalindrome(1LL * i * i)) {
            PalindromicSquares.push_back(1LL * i * i);
            PalindromicRoots.push_back(i);
        }
    }
}

int main() {
    Preprocess();
    ifstream in("input.in");
    ofstream out("output.out");
    int Tests; in >> Tests;
    for (int t = 1; t <= Tests; ++t) {
        int64 A, B; in >> A >> B;
        out << "Case #" << t << ": " << Count(B) - Count(A - 1) << "\n";
    }
    in.close();
    out.close();
    return 0;
}
