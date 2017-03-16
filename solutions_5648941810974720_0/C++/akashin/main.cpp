#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cassert>
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
const char* inputFile = "A-small-attempt1.in";
const char* outputFile = "A-small-attempt1.out";
//const char* inputFile = "A-large.in";
//const char* outputFile = "A-large.out";

const int INF = 1e9;

string numbers[10] = {
    "ZERO", //+
    "ONE",
    "TWO", //+
    "THREE", //+
    "FOUR", //+
    "FIVE", //+
    "SIX", //+
    "SEVEN", //+
    "EIGHT", //+
    "NINE",
};

class Solver {
public:
    Solver() {
    }

    string solveTest() {
        string s;
        cin >> s;
        vector<int> charCnt(256, 0);
        for (char c : s) {
            ++charCnt[c];
        }
        vector<int> cnt(10, 0);
        auto kick = [&](int x) {
            REP(i, cnt[x]) {
                for (char c : numbers[x]) {
                    --charCnt[c];
                }
            }
        };

        cnt[0] = charCnt['Z'];
        kick(0);
        cnt[6] = charCnt['X'];
        kick(6);
        cnt[2] = charCnt['W'];
        kick(2);
        cnt[4] = charCnt['U'];
        kick(4);
        cnt[8] = charCnt['G'];
        kick(8);
        cnt[3] = charCnt['H'];
        kick(3);
        cnt[5] = charCnt['F'];
        kick(5);
        cnt[7] = charCnt['V'];
        kick(7);
        cnt[1] = charCnt['O'];
        kick(1);
        cnt[9] = charCnt['N'] / 2;
        kick(9);

        for (char c = 'A'; c <= 'Z'; ++c) {
            if (charCnt[c] != 0) {
                cerr << c << " " << charCnt[c] << endl;
            }
        }

        string result;
        REP(i, 10) {
            REP(j, cnt[i]) {
                result += '0' + i;
            }
        }
        return result;
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
