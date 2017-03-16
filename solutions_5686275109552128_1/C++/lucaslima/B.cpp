#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int caso = 1; caso <= T; ++caso) {
        int d;
        cin >> d;
        vector<int> p(d);
        for (int& x : p) cin >> x;
        
        int rsp = *max_element(p.begin(), p.end());
        for (int i = 1; i < rsp; ++i) {
            int cnt = i;
            for (int& x : p) {
                if (x > i) cnt += (x + i - 1) / i - 1;
            }
            rsp = min(rsp, cnt);
        }
   
        cout << "Case #" << caso << ": " << rsp << endl;
        cerr << "finished test case " << caso << endl;
    }
    return 0;
}
