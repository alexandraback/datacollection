#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <unordered_set>
#include <sstream>

#define DB(x) cerr << #x << ": " << x << endl;
#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define mp make_pair

using namespace std;

//const char* inputFile = "file.in";
//const char* outputFile = "file.out";
const char* inputFile = "B-small-attempt1.in";
const char* outputFile = "B-small-attempt1.out";
//const char* inputFile = "A-large.in";
//const char* outputFile = "A-large.out";

const int INF = 1e9;

using LL = long long;

class Solver {
public:
    Solver() {
    }

    unordered_set<int> toVisit;

    void visit(long long x) {
        while (x) {
            toVisit.erase(x % 10);
            x /= 10;
        }
    }

    string solveTest() {
        string s1, s2;
        cin >> s1 >> s2;
        auto ans = stupidSolve(s1, s2);
        stringstream ss;
        ss << setw(s1.length()) << setfill('0') << ans.first;
        ss << " ";
        ss << setw(s1.length()) << setfill('0') << ans.second;
        return ss.str();
    }

    void fill(string& s, int pos, vector<LL>& ans)
    {
        if (pos == s.length()) {
            ans.push_back(stoll(s));
            return;
        }

        if (s[pos] == '?') {
            REP(i, 10) {
                s[pos] = '0' + i;
                fill(s, pos + 1, ans);
            }
            s[pos] = '?';
        } else {
            fill(s, pos + 1, ans);
        }
    }

    void update(pair<LL, LL>& cur, pair<LL, LL> upd) {
        if (cur.first == -1) {
            cur = upd;
            return;
        }

        int curDiff = labs(cur.first - cur.second);
        int updDiff = labs(upd.first - upd.second);
        if (updDiff > curDiff) {
            return;
        }
        if (updDiff < curDiff) {
            cur = upd;
            return;
        }

        if (upd.first > cur.first) {
            return;
        }
        if (upd.first < cur.first) {
            cur = upd;
            return;
        }

        if (upd.second > cur.second) {
            return;
        }
        if (upd.second < cur.second) {
            cur = upd;
            return;
        }
    }

    pair<LL, LL> stupidSolve(string s1, string s2)
    {
        vector<LL> s1fill;
        vector<LL> s2fill;
        fill(s1, 0, s1fill);
        fill(s2, 0, s2fill);

        pair<LL, LL> ans(-1, -1);
        for (LL x1 : s1fill) {
            //DB(x1);
            for (LL x2 : s2fill) {
                //DB(x2);
                update(ans, mp(x1, x2));
            }
        }

        return ans;
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
