#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

int z[(1 << 18) + 10];
string s[18][2];

void solve(int T) {
    printf("Case #%d: ", T);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i][0] >> s[i][1];
    }
    memset(z, 0, sizeof z);
    for(int mask = 0; mask < (1 << n); mask++) {
       set < string > usd[2];
       for(int i = 0; i < n; i++) {
         if ((mask & (1 << i))) {
            usd[0].insert(s[i][0]);
            usd[1].insert(s[i][1]);
         }
       }
       for(int i = 0; i < n; i++) {
          if (!((mask & (1 << i)))) {
             if (usd[0].count(s[i][0]) && usd[1].count(s[i][1])){
                z[mask | (1 << i)] = max(z[mask | (1 << i)], z[mask] + 1);
             }
             z[mask | (1 << i)] = max(z[mask | (1 << i)], z[mask]);
          }
       }
    }
    cout << z[(1 << n) - 1] << endl;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 0; i < T; i++) {
        solve(i + 1);
    }
}
