#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>
#define repeat(i,n) for (int i = 0; (i) < (n); ++(i))
#define repeat_from(i,m,n) for (int i = (m); (i) < (n); ++(i))
using namespace std;
namespace mp = boost::multiprecision;
void solve() {
    random_device device;
    default_random_engine gen(device());
    uniform_int_distribution<int> dist(0,1); // bool
    int n, j; cin >> n >> j;
    set<string> used;
    while (used.size() < j) {
        string s; s += '1'; repeat (i,n-2) s += dist(gen) + '0'; s += '1';
        if (used.count(s)) continue;
        vector<int> witnesses;
        repeat_from (base,2,10+1) {
            mp::cpp_int p = 0;
            repeat (i,n) {
                p *= base;
                if (s[i] == '1') p += 1;
            }
            repeat_from (i,2,10000) {
                if (p % i == 0) {
                    witnesses.push_back(i);
                    goto next;
                }
            }
            break;
next:;
        }
        if (witnesses.size() == 9) {
            cout << s;
            for (int it : witnesses) cout << ' ' << it;
            cout << endl;
            used.insert(s);
        }
    }
}
int main() {
    int t; cin >> t;
    repeat (i,t) {
        cout << "Case #" << i+1 << ":" << endl;
        solve();
    }
    return 0;
}
