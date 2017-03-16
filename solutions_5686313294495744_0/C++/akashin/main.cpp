#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <unordered_set>

#define DB(x) cerr << #x << ": " << x << endl;
#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

//const char* inputFile = "file.in";
//const char* outputFile = "file.out";
const char* inputFile = "C-small-attempt0.in";
const char* outputFile = "C-small-attempt0.out";
//const char* inputFile = "A-large.in";
//const char* outputFile = "A-large.out";

const int INF = 1e9;

bool isSet(int mask, int bit)
{
    return mask & (1 << bit);
}

class Solver {
public:
    Solver() {
    }

    vector<pair<string, string>> topics;
    int N;

    bool canFake(int mask) {
        set<string> first;
        set<string> second;
        REP(i, N) {
            if (!isSet(mask, i)) {
                first.insert(topics[i].first);
                second.insert(topics[i].second);
            }
        }
        REP(i, N) {
            if (isSet(mask, i)) {
                if (first.find(topics[i].first) == first.end()) {
                    return false;
                }
                if (second.find(topics[i].second) == second.end()) {
                    return false;
                }
            }
        }
        return true;
    }

    string solveTest() {
        cin >> N;
        topics.resize(N);
        REP(i, N) {
            cin >> topics[i].first >> topics[i].second;
        }
        int ans = 0;
        for (int mask = 0; mask < (1 << N); ++mask) {
            if (canFake(mask)) {
                ans = max(ans, __builtin_popcount(mask));
            }
        }
        return to_string(ans);
    }
};

int main() {
    freopen(inputFile, "r", stdin);
    freopen(outputFile, "w", stdout);
    int T;
    scanf("%d", &T);

    for (int testNumber = 1; testNumber <= T; ++testNumber) {
        Solver solver;
        string verdict = solver.solveTest();
        printf("Case #%d: %s\n", testNumber, verdict.c_str());
    }
    return 0;
}
