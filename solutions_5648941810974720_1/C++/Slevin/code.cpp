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

vector<int> solve(vector< vector<double> >& eqs) {
    for (int col = 0; col < 10; ++col) {
        int idx = -1;
        for (int j = col; j < eqs.size(); ++j) {
            if (eqs[j][col] != 0) {
                idx = j;
                break;
            }
        }
        if (idx == -1) {
            continue;
        }
        swap(eqs[col], eqs[idx]);
        for (int j = 10; j >= col; --j) {
            eqs[col][j] /= eqs[col][col];
        }
        for (int j = 0; j < eqs.size(); ++j) {
            if (j == col) {
                continue;
            }
            double k = eqs[j][col] / eqs[col][col];
            for (int c = col; c < 11; ++c) {
                eqs[j][c] -= eqs[col][c] * k;
            }
        }
    }
    vector<int> sol;
    for (int i = 0; i < 10; ++i) {
        sol.push_back(int(eqs[i].back() / eqs[i][i] + 0.5));
    }
    return sol;
}

void run() {
    int T; cin >> T;

    string digits[] = {
        "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"
    };

    for (int cs = 0; cs < T; ++cs) {
        string s; cin >> s;
        vector< vector<double> > eqs;
        for (int i = 0; i < 26; ++i) {
            char ch = 'A' + i;
            vector<double> eq;
            for (int j = 0; j < 10; ++j) {
                int k = count(all(digits[j]), ch);
                eq.push_back(k);
            }
            eq.push_back(count(all(s), ch));
            eqs.push_back(eq);
        }
        vector<int> sol = solve(eqs);
        cout << "Case #" << cs + 1 << ": ";
        for (int i = 0; i < sol.size(); ++i) {
            for (int j = 0; j < sol[i]; ++j) {
                cout << i;
            }
        }
        cout << endl;
    }
}
