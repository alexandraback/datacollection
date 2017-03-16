#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        map<int, int> m;
        for (int j = 0 ; j < 2 * n - 1; j++) {
            for (int k = 0; k < n; k++) {
                int v;
                cin >> v;
                m[v]++;
            }
        }
        vector<int> l;
        for (pair<const int, int> &p: m) {
            if (p.second & 1) l.push_back(p.first);
        }
        sort(l.begin(), l.end());
        cout << "Case #" << i << ":";
        for (int v: l) {
            cout << " " << v;
        }
        cout << endl;
    }
    return 0;
}

