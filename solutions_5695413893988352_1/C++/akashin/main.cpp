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
//const char* inputFile = "B-small-attempt1.in";
//const char* outputFile = "B-small-attempt1.out";
const char* inputFile = "B-large.in";
const char* outputFile = "B-large.out";

const int INF = 1e9;

using LL = long long;

class Solver {
public:
    Solver() {
    }

    string solveTest() {
        string s1, s2;
        cin >> s1 >> s2;
        //auto ansStupid = stupidSolve(s1, s2);
        auto ans = cleverSolve(s1, s2);
        //if (ans != ansStupid) {
            //cerr << "FAIL" << endl;
            //cerr << s1 << " " << s2 << endl;
            //cerr << ans.first << " " << ans.second << endl;
            //cerr << ansStupid.first << " " << ansStupid.second << endl;
            //exit(0);
        //}

        stringstream ss;
        ss << setw(s1.length()) << setfill('0') << ans.first;
        ss << " ";
        ss << setw(s1.length()) << setfill('0') << ans.second;
        return ss.str();
    }

    vector<int> available(char c)
    {
        if (c == '?') {
            return {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        } else {
            return {c - '0'};
        }
    }

    void updateMax(LL& maxDiff, pair<int, int>& maxDiffTake, LL updDiff, pair<int, int> updDiffTake)
    {
        if (maxDiffTake.first == -1) {
            maxDiff = updDiff;
            maxDiffTake = updDiffTake;
            return;
        }

        if (maxDiff > updDiff) {
            return;
        }
        if (maxDiff < updDiff) {
            maxDiff = updDiff;
            maxDiffTake = updDiffTake;
            return;
        }

        if (updDiffTake < maxDiffTake) {
            maxDiff = updDiff;
            maxDiffTake = updDiffTake;
        }
    }

    void updateMin(LL& minDiff, pair<int, int>& minDiffTake, LL updDiff, pair<int, int> updDiffTake)
    {
        if (minDiffTake.first == -1) {
            minDiff = updDiff;
            minDiffTake = updDiffTake;
            return;
        }

        if (minDiff < updDiff) {
            return;
        }
        if (minDiff > updDiff) {
            minDiff = updDiff;
            minDiffTake = updDiffTake;
            return;
        }

        if (updDiffTake < minDiffTake) {
            minDiff = updDiff;
            minDiffTake = updDiffTake;
        }
    }

    void updateBest(LL& bestDiff, pair<int, int>& bestDiffTake, LL updDiff, pair<int, int> updDiffTake)
    {
        if (bestDiffTake.first == -1) {
            bestDiff = updDiff;
            bestDiffTake = updDiffTake;
            return;
        }

        if (labs(bestDiff) < labs(updDiff)) {
            return;
        }
        if (labs(bestDiff) > labs(updDiff)) {
            bestDiff = updDiff;
            bestDiffTake = updDiffTake;
            return;
        }

        if (updDiffTake < bestDiffTake) {
            bestDiff = updDiff;
            bestDiffTake = updDiffTake;
        }
    }

    pair<LL, LL> cleverSolve(string s1, string s2) {
        LL pow10 = 1;
        int n = s1.length();
        vector<LL> maxDiff(n);
        vector<pair<int, int>> maxDiffTake(n, make_pair(-1, -1));
        vector<LL> minDiff(n);
        vector<pair<int, int>> minDiffTake(n, make_pair(-1, -1));
        REP(i, n) {
            for (int x1 : available(s1[n - i - 1])) {
                for (int x2 : available(s2[n - i - 1])) {
                    LL curMaxDiff = (x1 - x2) * pow10;
                    if (i > 0) {
                        curMaxDiff += maxDiff[i - 1];
                    }
                    updateMax(maxDiff[i], maxDiffTake[i], curMaxDiff, make_pair(x1, x2));

                    LL curMinDiff = (x1 - x2) * pow10;
                    if (i > 0) {
                        curMinDiff += minDiff[i - 1];
                    }
                    updateMin(minDiff[i], minDiffTake[i], curMinDiff, make_pair(x1, x2));
                }
            }
            pow10 *= 10;
        }
        vector<LL> bestDiff(n);
        vector<pair<int, int>> bestDiffTake(n, make_pair(-1, -1));
        pow10 = 1;
        REP(i, n) {
            for (int x1 : available(s1[n - i - 1])) {
                for (int x2 : available(s2[n - i - 1])) {
                    LL curDiff = (x1 - x2) * pow10;
                    if (i > 0) {
                        if (curDiff > 0) {
                            curDiff += minDiff[i - 1];
                        } else if (curDiff < 0) {
                            curDiff += maxDiff[i - 1];
                        } else {
                            curDiff += bestDiff[i - 1];
                        }
                        updateBest(bestDiff[i], bestDiffTake[i], curDiff, make_pair(x1, x2));
                    } else {
                        updateBest(bestDiff[i], bestDiffTake[i], curDiff, make_pair(x1, x2));
                    }
                }
            }
            //DB(minDiff[i]);
            //DB(maxDiff[i]);
            //DB(bestDiff[i]);
            pow10 *= 10;
        }
        pair<LL, LL> ans(0, 0);

        int i = 0;
        while (i < n) {
            ans.first *= 10;
            ans.first += bestDiffTake[n - i - 1].first;
            ans.second *= 10;
            ans.second += bestDiffTake[n - i - 1].second;

            LL curDiff = (bestDiffTake[n - i - 1].first - bestDiffTake[n - i - 1].second);
            ++i;
            if (i < n) {
                if (curDiff > 0) {
                    while (i < n) {
                        ans.first *= 10;
                        ans.first += minDiffTake[n - i - 1].first;
                        ans.second *= 10;
                        ans.second += minDiffTake[n - i - 1].second;
                        ++i;
                    }
                } else if (curDiff < 0) {
                    while (i < n) {
                        ans.first *= 10;
                        ans.first += maxDiffTake[n - i - 1].first;
                        ans.second *= 10;
                        ans.second += maxDiffTake[n - i - 1].second;
                        ++i;
                    }
                }
            }
        }

        return ans;
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
            for (LL x2 : s2fill) {
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
