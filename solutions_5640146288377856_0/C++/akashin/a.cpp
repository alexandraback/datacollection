#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

//const char* inputFile = "file.in";
//const char* outputFile = "file.out";
const char* inputFile = "A-small-attempt0.in";
const char* outputFile = "A-small-attempt0.out";
//const char* inputFile = "B-large.in";
//const char* outputFile = "B-large.out";

const int INF = 1e9;

class Solver {
public:
    Solver() {
    }

    int minGuess(int C, int W) {
        return C / W;
    }

    int toKill(int C, int W) {
        int ans = 0;
        while (C > 2 * W) {
            ans += 1;
            C -= W;
        }
        if (C == W) {
            ans += W;
        } else {
            ans += W + 1;
        }
        return ans;
    }

    string solveTest() {
        cin >> R >> C >> W;
        int ans = (R - 1) * minGuess(C, W);
        ans += toKill(C, W);

        return std::to_string(ans);
    }
    int R, C, W;
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
