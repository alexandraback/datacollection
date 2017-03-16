#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <float.h>

using namespace std;

#define REP(i, from, to) for (int i = (from); i < (to); ++i)
#define FOR(i, n) REP(i, 0, (n))
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)x.size()
#define PB push_back
#define MP make_pair

typedef long long i64;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef pair<int, int> PII;

int solveDeceitfulWar(set<int> naomi, set<int> ken) {
    int points = 0;
    while (!naomi.empty()) {
        int bestNaomiChoice1 = -1;
        int bestKenChoice1 = -1;

        for (auto naomiChoice : naomi) {
            int kenChoice = *ken.rbegin();

            if (naomiChoice > kenChoice) {
                bestNaomiChoice1 = naomiChoice;
                bestKenChoice1 = kenChoice;
                break;
            }
        }

        if (bestNaomiChoice1 > bestKenChoice1) {
            ++points;
            naomi.erase(bestNaomiChoice1);
            ken.erase(bestKenChoice1);
        } else {
            naomi.erase(naomi.begin());
            ken.erase(*ken.rbegin());
        }
    }

    return points;
}

int solveWar(set<int> naomi, set<int> ken) {
    int points = 0;
    while (!naomi.empty()) {
        int const naomiChoice = *naomi.rbegin();
        int kenChoice;
        auto it = ken.upper_bound(naomiChoice);
        if (it == ken.end()) {
            kenChoice = *ken.begin();
        } else {
            kenChoice = *it;
        }

        points += naomiChoice > kenChoice;
        naomi.erase(naomiChoice);
        ken.erase(kenChoice);
    }

    return points;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;

    FOR (t, tests) {
        int n;
        cin >> n;

        set<int> naomi, ken;
        FOR (i, n) {
            string number;
            cin >> number;
            if (SIZE(number) < 8)
                number += string(8 - SIZE(number), '0');
            naomi.insert(atoi(number.substr(2).c_str()));
        }

        FOR (i, n) {
            string number;
            cin >> number;
            if (SIZE(number) < 8)
                number += string(8 - SIZE(number), '0');
            ken.insert(atoi(number.substr(2).c_str()));
        }

        int const score1 = solveDeceitfulWar(naomi, ken);
        int const score2 = solveWar(naomi, ken);
        printf("Case #%d: %d %d\n", t + 1, score1, score2);
    }

    return 0;
}
