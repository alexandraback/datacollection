#include <cstdio>
#include <cstring>
#include <cmath>
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
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

int A, B, K;

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
    int testCount;
    cin >> testCount;
    for (int test = 1; test <= testCount; ++test) {
        cin >> A >> B >> K;
        int answer = 0;
        for (int a = 0; a < A; ++a)
            for (int b = 0; b < B; ++b)
                if ((a & b) < K)
                    ++answer;
        cout << "Case #" << test << ": " << answer << "\n";
    }
    return 0;
}
