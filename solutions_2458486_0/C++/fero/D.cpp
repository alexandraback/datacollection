#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

const int maxk = 200;
const int maxn = 200;

struct State {
    int keys[maxk];
    bool open[maxn];

    State() {
        CLEAR(keys);
        CLEAR(open);
    }

    State(const State& state) {
        REP(k, maxk)
            keys[k] = state.keys[k];
        REP(i, maxn)
            open[i] = state.open[i];
    }

    void open_chest(int c);
    bool solvable();
    bool explore(int key);
    bool done();
};

int n;
int t[maxn];
vector<int> chest[maxn];
vector<int> opens[maxk];

void State::open_chest(int c) {
    // cerr << "OPEN " << c << endl;
    int k = t[c];
    keys[k]--;
    open[c] = true;
    FOREACH(x, chest[c])
        keys[*x]++;
}

bool State::done() {
    REP(i, n)
        if (!open[i])
            return false;
    return true;
}

bool State::solvable() {
    int need[maxk];
    bool found = true;
    while (found) {

        CLEAR(need);
        REP(i, n)
            if (!open[i])
                need[t[i]]++;

        bool enough = true;
        while (enough) {
            enough = false;
            REP(k, maxk) 
                if (need[k] && keys[k] >= need[k]) {
                    REP(i, n)
                        if (!open[i] && t[i] == k)
                            open_chest(i);
                    need[k] = 0;
                    enough = true;
                }
        }

        if (done())
            return true;

        found = false;
        REP(k, maxk) 
            if (keys[k])
                found = explore(k) || found;
    }

    return false;
}

bool State::explore(int key) {
    int from[maxk];
    REP(k, maxk)
        from[k] = -1;

    queue<int> q;
    q.push(key);

    while (!q.empty() && from[key] == -1) {
        int k = q.front();
        q.pop();
        FOREACH(c, opens[k])
            if (!open[*c])
                FOREACH(x, chest[*c])
                    if (from[*x] == -1) {
                        from[*x] = *c;
                        q.push(*x);
                    }
    }

    if (from[key] != -1) {
        int k = key;
        do {
            int c = from[k];
            open_chest(c);
            k = t[c];
        } while (k != key);

        return true;
    }

    return false;
}

int main() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
	cout << "Case #" << cs << ":";

        int k;
        cin >> k >> n;
        State start;
        REP(i, k) {
            int x;
            cin >> x;
            start.keys[x-1]++;
        }

        REP(k, maxk)
            opens[k].clear();

        REP(i, n) {
            int tt, m;
            cin >> tt >> m;
            t[i] = tt-1;
            opens[t[i]].push_back(i);

            chest[i].clear();
            REP(j, m) {
                int x;
                cin >> x;
                chest[i].push_back(x-1);
            }
        }


        State copy(start);
        if (!copy.solvable()) {
            cout << " IMPOSSIBLE" << endl;
            continue;
        }

        State state(start);
        while (!state.done()) {
            REP(i, n)
                if (state.keys[t[i]] && !state.open[i]) {
                    State copy(state);
                    copy.open_chest(i);
                    if (copy.solvable()) {
                        state.open_chest(i);
                        cout << " " << i+1;
                        break;
                    }
                }
        }
        cout << endl;
    }
}
