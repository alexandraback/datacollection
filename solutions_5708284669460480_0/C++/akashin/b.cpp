#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <sstream>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

//const char* inputFile = "file.in";
//const char* outputFile = "file.out";
const char* inputFile = "B-small-attempt0.in";
const char* outputFile = "B-small-attempt0.out";
//const char* inputFile = "B-large.in";
//const char* outputFile = "B-large.out";

const int INF = 1e9;

class Solver {
public:
    Solver() {
    }

    int maxPref(string word) {
        for (int pLen = 1; pLen < word.size(); ++pLen) {
            for (int i = 0; i < pLen; ++i) {
                if (word[i] != word[word.size() - pLen + i]) {
                    return pLen - 1;
                }
            }
        }
        return word.size() - 1;
    }

    int maxCount(string word, string keyboard, int S) {
        set<char> kChar(keyboard.begin(), keyboard.end());
        for (char c : word) {
            if (!kChar.count(c)) {
                return false;
            }
        }
        int p = maxPref(word);
        int count = 1;
        S -= word.length();
        count += S / (word.length() - p);
        return count;
    }

    double wordProb(string word, string keyboard, int S) {
        map<char, int> kFreq;
        for (int i = 0; i < keyboard.size(); ++i) {
            ++kFreq[keyboard[i]];
        }
        map<char, int> wFreq;
        for (int i = 0; i < word.size(); ++i) {
            ++wFreq[word[i]];
        }

        double prob = 1.0;
        for (auto charFreq : wFreq) {
            char c = charFreq.first;
            int f = charFreq.second;
            double cProb = kFreq[c] * 1.0 / keyboard.length();
            prob *= pow(cProb, f);
        }
        return prob;
    }

    double expCount(string word, string keyboard, int S) {
        double prob = wordProb(word, keyboard, S);
        return prob * (S - word.length() + 1);
    }

    string solveTest() {
        cin >> K >> L >> S;
        cin >> keyboard;
        cin >> word;

        //DB(maxCount(word, keyboard, S));
        //DB(expCount(word, keyboard, S));
        double ans = maxCount(word, keyboard, S) - expCount(word, keyboard, S);

        stringstream ss;
        ss.precision(6);
        ss << fixed << ans;
        return ss.str();
    }
    int K, L, S;
    string keyboard, word;
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
