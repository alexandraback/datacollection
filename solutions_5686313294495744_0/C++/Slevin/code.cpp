#include <cassert>
#include <complex>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iterator>
#include <limits>
#include <numeric>
#include <sstream>
#include <utility>
#include <cmath>

#include <algorithm>
#include <bitset>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#include <memory.h>
using namespace std;

#define Pi 3.141592653589793
#define all(c) (c).begin(), (c).end()
typedef long long ll;

template <typename T>
int numbits(T n) {
    return n ? 1 + numbits(n & (n - 1)) : 0;
}

class timer {
public:
    timer() : t_(clock()) {}
    void restart() { t_ = clock(); }
    float elapsed() { return float(clock() - t_) / CLOCKS_PER_SEC; }
private:
    clock_t t_;
};

void run();

int main() {
#ifdef LOCAL_HOST
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    timer t;
#endif
    run();
#ifdef LOCAL_HOST
    // printf("\nElapsed time: %.9f\n", t.elapsed());
#endif
    return 0;
}

struct Sol {
    int score;
    int f;
    int s;
    Sol(int a, int b, int c) {
        score = a;
        f = b;
        s = c;
    }
    bool operator<(const Sol& that) const {
        if (score != that.score) {
            return score < that.score;
        }
        if (f != that.f) {
            return f < that.f;
        }
        return s < that.s;
    }
};

void run() {
    int T; cin >> T;

    for (int cs = 0; cs < T; ++cs) {
        vector< pair<string, string> > vs;
        set<string> s1;
        set<string> s2;
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            string str1, str2;
            cin >> str1 >> str2;
            vs.push_back(make_pair(str1, str2));
            s1.insert(str1);
            s2.insert(str2);
        }
        int sol = 0;
        for (int mask = 0; mask < (1 << n); ++mask) {
            set<string> ss1;
            set<string> ss2;
            for (int bit = 0; bit < n; ++bit) {
                if ((1 << bit) & mask) {
                    ss1.insert(vs[bit].first);
                    ss2.insert(vs[bit].second);
                }
            }
            if (s1.size() == ss1.size() && s2.size() == ss2.size()) {
                sol = max(sol, n - numbits(mask));
            }
        }
        cout << "Case #" << cs + 1 << ": " << sol << endl;
    }
}
