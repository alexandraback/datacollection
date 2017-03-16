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
const char* inputFile = "C-small-attempt0.in";
const char* outputFile = "C-small-attempt0.out";
//const char* inputFile = "B-large.in";
//const char* outputFile = "B-large.out";

const int INF = 1e9;

class Solver {
public:
    Solver() {
    }

    string solveTest() {
        cin >> C >> D >> V;
        d.resize(D);
        for (int i = 0; i < D; ++i) {
            cin >> d[i];
        }
        sort(d.begin(), d.end());
        long long mR = 0;
        int add = 0;
        for (int i = 0; i < d.size(); ++i) {
            while (d[i] > mR + 1) {
                // add mR + 1 to set
                ++add;
                mR += C * (mR + 1);
            }
            mR += C * d[i];
            if (mR >= V) {
                break;
            }
        }
        while (mR < V) {
            ++add;
            mR += C * (mR + 1);
        }
        return to_string(add);
    }

    int C, D, V;
    vector<int> d;
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
