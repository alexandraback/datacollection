#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

struct level {
    int a, b;
};

int N;

vector<level> gl;

struct state {
    int stars;
    vector<int> levels;
    int num;
    state() : stars(0), levels(N, 0), num(0) { }
    bool doLevel(int n) {
        const level& l = gl[n];
        if (stars < l.a) return false;
        int s = 1;
        if (stars >= l.b) {
            s = 2;
        }
        if (levels[n] >= s) return false;
        stars += s - levels[n];
        levels[n] = s;
        ++num;
        return true;
    }
    bool doBestLevel() {
        for (int i = 0; i < N; ++i) {
            if (stars >= gl[i].b && levels[i] < 2) {
                bool r = doLevel(i);
                assert(r);
                return true;
            }
        }
        int best = -1;
        for (int i = 0; i < N; ++i) {
            if (stars >= gl[i].a && levels[i] < 1) {
                if (best == -1 || gl[i].b > gl[best].b) {
                    best = i;
                }
            }
        }
        if (best > -1) {
            bool r = doLevel(best);
            assert(r);
            return true;
        }
        return false;
    }
    bool win() {
        for (int i = 0; i < N; ++i) if (levels[i] != 2) return false;
        return true;
    }
};

int main() {
    int T;
    cin >> T;
    for (int z = 1; z <= T; ++z) {
        cout << "Case #" << z << ": ";
        cin >> N;
        gl.clear();
        for (int i = 0; i < N; ++i) {
            level L;
            cin >> L.a >> L.b;
            gl.push_back(L);
        }
/*        queue<state> states;
        states.push(state());
        while (states.size()) {
            state s = states.front();
            states.pop();
            for (int i = 0; i < N; ++i) {
                state sp = s;
                if (sp.doLevel(i)) {
                    if (sp.win()) {
                        cout << sp.num << endl;
                        goto ok;
                    }
                    states.push(sp);
                }
            }
        }*/
        state s;
        int n = 0;
        while (s.doBestLevel()) ++n;
        if (!s.win())
            cout << "Too Bad" << endl;
        else 
            cout << n << endl;
        ok:
        0;
    }
}