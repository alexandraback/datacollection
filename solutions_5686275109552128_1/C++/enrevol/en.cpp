#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int tn;
    cin >> tn;    
    for (int ti = 1; ti <= tn; ++ti) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int answer = 1e9;
        int a_max = a.back();
        for (int i = 1; i <= a_max; ++i) {
            int t = 0;
            for (int j = 0; j < n; ++j) {
                int v = a[j];
                int s = (v - 1) / i;
                t += s;
            }
            answer = min(answer, t + i);
        }
        cout << "Case #" << ti << ": " << answer << '\n';
    }
}
