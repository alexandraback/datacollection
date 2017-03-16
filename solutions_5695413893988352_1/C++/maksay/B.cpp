#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#include <set>
#include <climits>
//#include <priority_queue>
using namespace std;
#define ll long long
#define x first
#define y second
#define pii pair<int, int>
#define pdd pair<double, double>
#define L(s) (int)(s).size()
#define VI vector<int>
#define all(s) (s).begin(), (s).end()
#define pb push_back
#define mp make_pair
#define inf 1000000000
int t;
string a, b;
ll best_a, best_b;
string best_sa, best_sb;

inline void upd(string ca, string cb) {
    ll na = 0, nb = 0;
    for(int i = 0; i < L(ca); ++i) {
        na = na * 10LL + ca[i] - '0';
        nb = nb * 10LL + cb[i] - '0';
    }

    if (best_a == -1 ||
        abs(na - nb) < abs(best_a - best_b) ||
        (abs(na - nb) == abs(best_a - best_b) && (na < best_a || (na == best_a && nb < best_b)))) {
        best_a = na;
        best_b = nb;
        best_sa = ca;
        best_sb = cb;
    }

}
int main() {

    freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> t;
    for(int tc = 1; tc <= t; ++tc) {
        cerr << tc << endl;
        cin >> a >> b;

        best_a = -1;
        best_b = -1;

        string ca = a, cb = b;
        for(int i = 0; i < L(a); ++i) {
            if (ca[i] == '?' && cb[i] == '?') ca[i] = cb[i] = '0'; else
                if (ca[i] == '?') ca[i] = cb[i]; else
                    if (cb[i] == '?') cb[i] = ca[i];
        }

        upd(ca, cb);

        for(int eq = 0; eq < L(a); ++eq) {
            for(int va = 0; va < 10; ++va) {
                for(int vb = 0; vb < 10; ++vb) {
                    for(int fa = 0; fa < 10; fa += 9) {
                        int fb = 9 - fa;
                        ca = a;
                        cb = b;
                        for(int i = 0; i < L(a); ++i) {
                            if (i < eq) {
                                if (ca[i] == '?' && cb[i] == '?') ca[i] = cb[i] = '0'; else
                                    if (ca[i] == '?') ca[i] = cb[i]; else
                                        if (cb[i] == '?') cb[i] = ca[i];
                            }
                            if (i == eq) {
                                if (ca[i] == '?') ca[i] = '0' + va;
                                if (cb[i] == '?') cb[i] = '0' + vb;
                            }
                            if (i > eq) {
                                if (ca[i] == '?') ca[i] = '0' + fa;
                                if (cb[i] == '?') cb[i] = '0' + fb;
                            }
                        }
                        upd(ca, cb);
                    }
                }
            }
        }

        cout << "Case #" << tc << ": " << best_sa << " " << best_sb << endl;

    }
}
