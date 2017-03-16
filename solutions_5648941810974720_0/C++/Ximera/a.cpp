#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (int)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

int a[30];
int kol[30];
vector<int> res;

string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


int solve(int cur, int numb) {
    for(auto x: s[numb])
        kol[x - 'A'] -= cur;
    while(cur) {
        res.pb(numb);
        cur--;
    }
}


int main() {
    inp("input.tx");
    out("output.txt");
    int t, i;
    cin >> t;
    for(int tt = 1; tt <= t; tt++) {
        string d;
        res.clear();
        cin >> d;
        for(auto x: d) {
            kol[x - 'A']++;
        }
        solve(kol['Z' - 'A'], 0);
        solve(kol['X' - 'A'], 6);
        solve(kol['W' - 'A'], 2);
        solve(kol['U' - 'A'], 4);
        solve(kol['S' - 'A'], 7);
        solve(kol['V' - 'A'], 5);
        solve(kol['R' - 'A'], 3);
        solve(kol['O' - 'A'], 1);
        solve(kol['T' - 'A'], 8);
        solve(kol['I' - 'A'], 9);
        sort(res.begin(), res.end());
        printf("Case #%d: ", tt);
        for(auto x: res)
            printf("%d", x);
        printf("\n");
    }
    return 0;
}
