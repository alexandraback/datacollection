#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

struct R {
    int d;
    int n;
    int w, e, s;
    int dd, dp, ds;
};

struct Attack {
    int w, e, s;
    Attack(int w, int e, int s) : w(w), e(e), s(s) {}
};

istream& operator>>(istream &in, R& r) {
    in >> r.d >> r.n >> r.w >> r.e >> r.s >> r.dd >> r.dp >> r.ds;
}

int solve() 
{
    int N;
    cin >> N;
    map<int, vector<Attack>> m;
    for (int i = 0; i < N; ++i) {
        R r;
        cin >> r;
        for (int j = 0; j < r.n; ++j) {
            m[r.d].push_back(Attack(r.w + 50000, r.e + 50000, r.s));
            r.d += r.dd;
            r.e += r.dp;
            r.w += r.dp;
            r.s += r.ds;
        }
    }
    int cc = 0;

    vector<int> w = std::vector<int>(100000);
    vector<int> wp = std::vector<int>(100000);

    for (auto it = m.begin(); it != m.end(); ++it) {

    //    cout << it->first << " " << cc << endl;

        for (Attack &at : it->second) {
            for (int k = at.w; k <= at.e; ++k) {
                if (w[k] < at.s) {
                    ++cc;
                    break;
                }
                if (k != at.e && wp[k] < at.s) {
                    ++cc;
                    break;
                }
            }
        }

    //    cout << it->first << " " << cc << endl;

        for (Attack &at : it->second) {
            for (int k = at.w; k <= at.e; ++k) {
                if (w[k] < at.s) {
                    w[k] = at.s;
                }
                if (k != at.e && wp[k] < at.s) {
                    wp[k] = at.s;
                }
            }
        }
    }

    return cc;   
}

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": " << solve() << endl;
    }
}