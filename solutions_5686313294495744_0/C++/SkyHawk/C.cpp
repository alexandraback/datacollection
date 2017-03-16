#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iterator>
#include <utility>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>

using namespace std;

#define pb push_back
#define sz(v) ((long long)v.size())
#define mp make_pair
#define FOR(i,n) for(long long i = 0;i < (n);++i)
#define MOD 1000000007

int main() {
    int T;
    cin >> T;
    FOR(iter, T) {
        cout << "Case #" << iter + 1 << ": ";
        int n;
        cin >> n;
        vector<string> ws1, ws2;
        FOR(i, n) {
            string w1, w2;
            cin >> w1 >> w2;
            ws1.push_back(w1);
            ws2.push_back(w2);
        }
        int ans = 0;
        FOR(mask, (1 << ws1.size())) {
            set<string> s1, s2;
            FOR(i, ws1.size()) {
                if(mask & 1<<i) {
                    s1.insert(ws1[i]);
                    s2.insert(ws2[i]);
                }
            }
            bool ok = true;
            int counter = 0;
            FOR(i, ws1.size()) {
                if(!(mask & 1<<i)) {
                    if (s1.find(ws1[i]) == s1.end() || s2.find(ws2[i]) == s2.end()) {
                        ok = false;
                        break;
                    }
                    ++counter;
                }
            }
            if (ok) {
                ans = max(ans, counter);
            }
        }
        cout << ans << endl;
    }
  
}