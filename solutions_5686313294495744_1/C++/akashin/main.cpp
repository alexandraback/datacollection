#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <set>
#include <memory.h>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_set>

#define DB(x) cerr << #x << ": " << x << endl;
#define REP(i, n) for(int i = 0; i < n; ++i)
#define FOR(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

//const char* inputFile = "file.in";
//const char* outputFile = "file.out";
//const char* inputFile = "C-small-attempt0.in";
//const char* outputFile = "C-small-attempt0.out";
const char* inputFile = "C-large.in";
const char* outputFile = "C-large.out";

const int INF = 1e9;

bool isSet(int mask, int bit)
{
    return mask & (1 << bit);
}

class Solver {
public:
    Solver() {
    }

    int n, k;
    vector < vector<int> > g;
    vector<int> mt;
    vector<char> used;

    bool try_kuhn (int v) {
        if (used[v])  return false;
        used[v] = true;
        for (size_t i=0; i<g[v].size(); ++i) {
            int to = g[v][i];
            if (mt[to] == -1 || try_kuhn (mt[to])) {
                mt[to] = v;
                return true;
            }
        }
        return false;
    }

    int findMatchingSize()
    {
        mt.assign (k, -1);
        for (int v=0; v<n; ++v) {
            used.assign (n, false);
            try_kuhn (v);
        }

        int size = 0;
        for (int i=0; i<k; ++i)
            if (mt[i] != -1)
                ++size;
        return size;
    }

    vector<pair<string, string>> topics;
    vector<pair<int, int>> groups;
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
        int ans = cleverSolve();
        //int stupidAns = stupidSolve();
        //if (ans != stupidAns) {
            //cerr << "FAIL " << ans << " " << stupidAns << endl;
        //}
        return to_string(ans);
    }

    int firstGroupSize;
    int secondGroupSize;
    void buildGraph()
    {
        map<string, int> first;
        map<string, int> second;
        REP(i, N) {
            if (first.find(topics[i].first) == first.end()) {
                int size = first.size();
                first[topics[i].first] = size;
            }
            if (second.find(topics[i].second) == second.end()) {
                int size = second.size();
                second[topics[i].second] = size;
            }
            groups.push_back(make_pair(first[topics[i].first], second[topics[i].second]));
        }
        firstGroupSize = first.size();
        secondGroupSize = second.size();
        n = firstGroupSize;
        k = secondGroupSize;

        g.resize(n);
        REP(i, N) {
            g[groups[i].first].push_back(groups[i].second);
        }
    }

    int cleverSolve() {
        buildGraph();
        int size = findMatchingSize();
        return N - (firstGroupSize + secondGroupSize - size);
    }

    int stupidSolve() {
        int ans = 0;
        for (int mask = 0; mask < (1 << N); ++mask) {
            if (canFake(mask)) {
                ans = max(ans, __builtin_popcount(mask));
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
