#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    for(int T = 1; T <= t; T++) {
        int d, v;
        long long c;
        cin >> c >> d >> v;
        long long cap = 0;
        int ans = 0;
        vector<int> need;
        for(int i = 0; i < d; i++) {
            int nom;
            cin >> nom;
            while(cap + 1 < nom && cap < v) {
                need.push_back(cap+1);
                cap += c * (cap+1);
                ans++;
            }
            cap += c * nom;
        }
        while(cap < v) {
            need.push_back(cap+1);
            cap += c * (cap+1);
            ans++;
        }
        printf("Case #%d: %d\n", T, ans);
//         for(auto n: need)
//             cout << n << " ";
//         cout << "\n";
    }
}