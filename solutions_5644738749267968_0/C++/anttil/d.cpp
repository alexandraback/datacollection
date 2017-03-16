#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int t;
int n;
set<double> p1, p2;
set<double> v1, v2;

int main() {
    cin >> t;
    for (int x = 1; x <= t; x++) {
        cin >> n;
        p1.clear();
        for (int i = 0; i < n; i++) {
            double q; cin >> q; p1.insert(q);
        }
        v1 = p1;
        p2.clear();
        for (int i = 0; i < n; i++) {
            double q; cin >> q; p2.insert(q);
        }
        v2 = p2;
        int c1 = 0;
        set<double>::iterator q = p1.end();
        q--;
        for (int i = 0; i < n; i++) {
            set<double>::iterator z = p2.upper_bound(*q);
            if (z == p2.end()) {
                p2.erase(p2.begin());
                c1++;
            } else {
                p2.erase(z);
            }
            q--;
        }
        p1 = v1;
        p2 = v2;
        int c2 = 0;
        q = p2.end();
        q--;
        for (int i = 0; i < n; i++) {
            set<double>::iterator z = p1.end();
            z--;
            if (*z < *q) {
                p1.erase(p1.begin());
            } else {
                p1.erase(z);
                c2++;
            }
            q--;
        }
        cout << "Case #" << x << ": " << c2 << " " << c1 << endl;
    }
}
