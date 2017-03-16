#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main() {
    int t;
    cin>>t;
    for (int tt = 1; tt <= t; ++tt) {
        long long a;
        int n;
        cin>>a>>n;
        vector< long long > v(n);
        for (int i = 0; i < n; ++i) {
            cin>>v[i];
        }
        sort(v.begin(), v.end());
        int mn = n;
        int ins = 0;
        if (a > 1) {
            for (int i = 0; i < n; ++i) {
                while (a <= v[i]) {
                    ++ins;
                    a += a - 1;
                }
                a += v[i];
                mn = min(mn, ins + n - i - 1);
            }
        }
        cout<<"Case #"<<tt<<": "<<mn<<endl;
    }
    return 0;
}

