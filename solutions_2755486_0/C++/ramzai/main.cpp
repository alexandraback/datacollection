#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <memory>
#include <cassert>
#include <climits>
using namespace std;

#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); (i)++)
#define FORD(i, a, b) for(int (i) = (a); (i) >= (b); (i)--)
#define REP(i, n) for (int (i) = 0; (i) < n; (i)++)
#define SIZE(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()

typedef long long LL;
typedef vector<pair<int, int> > vpii;

#define DBG(x) cout << #x << " = " << x << endl
// #define DBG(x) ;
template<typename T>
void dbg_vector(const vector<T>& v, const string& name) {
    cout << name << " = ";
    REP(i, SIZE(v)) {
        cout << v[i] << ' ';
    }
    cout << endl;
}

struct TTribe {
    int d;
    int n;
    int w, e;
    int s;
    int delta_d;
    int delta_e;
    int delta_s;
};

TTribe read_tribe() {
    TTribe x;
    scanf("%d %d %d %d %d %d %d %d", &x.d, &x.n, &x.w, &x.e, &x.s, &x.delta_d, &x.delta_e, &x.delta_s);
    return x;
}

struct TEvent {
    int d;
    int s;
    int w, e;
};

void generate_events(TTribe& x, vector<TEvent>& events) {
    while (x.n > 0) {
        TEvent e;
        e.d = x.d;
        e.s = x.s;
        e.w = x.w;
        e.e = x.e;
        events.push_back(e);

        x.d += x.delta_d;
        x.w += x.delta_e;
        x.e += x.delta_e;
        x.s += x.delta_s;
        --x.n;
    }
}

bool less_day(const TEvent& x, const TEvent& y) {
    return x.d < y.d;
}

class TWall {
    // all in all you're just
    // another brick in the wall

private:
    int a[500];
    static const int OFF = 250;

public:
    TWall() {
        memset(a, 0, sizeof(a));
    }

    bool attack(TEvent& event) const {
        int w = event.w + OFF;
        int e = event.e + OFF;
        int s = event.s;
        FOR(i, w, e - 1) {
            if (s > a[i]) {
                return true;
            }
        }
        return false;
    }

    void build(TEvent& event) {
        int w = event.w + OFF;
        int e = event.e + OFF;
        int s = event.s;
        FOR(i, w, e - 1) {
            if (s > a[i]) {
                a[i] = s;
            }
        }
    }
};

int doit(vector<TTribe>& tribes) {
    int res = 0;

    vector<TEvent> events;
    REP(i, SIZE(tribes)) {
        generate_events(tribes[i], events);
    }

    TWall wall;
    int curr_day = -1;
    sort(ALL(events), less_day);
    REP(i, SIZE(events)) {
        TEvent& e = events[i];
        if (e.d != curr_day) {
            FORD(j, i - 1, 0) {
                TEvent& e2 = events[j];
                if (e2.d == curr_day) {
                    wall.build(e2);
                } else {
                    break;
                }
            }
            curr_day = e.d;
        }
        if (wall.attack(e)) {
            ++res;
        }
    }

    return res;
}

int main() {
    int tests;
    cin >> tests;
    REP(zzz, tests) {
        int N;
        scanf("%d", &N);
        vector<TTribe> tribes;
        REP(i, N) {
            tribes.push_back(read_tribe());
        }
        int res = doit(tribes);
        cout << "Case #" << zzz + 1 << ": " << res << endl;
    }

    return 0;
}
