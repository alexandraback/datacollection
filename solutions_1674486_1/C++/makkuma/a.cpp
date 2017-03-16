#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <functional>  // multiplies
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>  // accumulate
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<pair<int, int> > VII;
typedef vector<string> VS;
typedef map<int, int> MII;
#define REP(i,n) for (int i=0; i<(int)(n); ++i)
#define FOREACH(it,c) for (typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define SORT(c) sort((c).begin(), (c).end());
#define RSORT(c) sort((c).rbegin(), (c).rend());
#define DUMP(x) cerr << #x << "=" << (x) << " ";
#define DUMPLN(x) cerr << #x << "=" << (x) << endl;
const int oo = numeric_limits<int>::max();
#define BEGIN_SOLVER struct Solver {
#define END_SOLVER }; int main() { Solver s; s.main(); }

BEGIN_SOLVER // ------------------------------------------------------------

int N;

void main() {
    int T; cin >> T;
    REP (t, T) {
        VI noParent;

        printf("Case #%d: ", t+1);
        cin >> N;
        VVI children(N);

        REP (n, N) {
            int M; cin >> M;

            if (M == 0) {
                noParent.push_back(n);
                continue;
            }

            REP (m, M) {
                int temp;
                cin >> temp;
                children[temp-1].push_back(n);
            }
        }

        if (solve(noParent, children)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}

bool found(const VI& v, int val) {
    return find(v.begin(), v.end(), val) != v.end();
}

bool dig(VVI& allParent, const VVI& children, int cur, int rootVal) {
    FOREACH (it, children[cur]) {
        if (found(allParent[*it], rootVal)) {
            return true;
        }
        if (dig(allParent, children, *it, rootVal)) {
            return true;
        }
        allParent[*it].push_back(rootVal);
    }

    return false;
}

bool solve(const VI& noParent, const VVI& children) {
    VVI allParent(N);
    REP (i, noParent.size()) {
        if (dig(allParent, children, noParent[i], noParent[i])) {
            return true;
        }
    }
    return false;
}

END_SOLVER // --------------------------------------------------------------
