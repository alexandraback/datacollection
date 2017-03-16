#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{

    ifstream cin("A-small-attempt0.in");
    ofstream cout("outasmall.txt");

    ios_base::sync_with_stdio(false);

    int tt;
    cin >> tt;

    for (int step = 0; step < tt; ++step) {
        string s;
        cin >> s;
        string ans = "";
        ans += s[0];
        for (int i = 1; i < sz(s); ++i) {
            if (ans + s[i] > s[i] + ans) {
                ans += s[i];
            } else {
                ans = s[i] + ans;
            }
        }
        cout << "Case #" << step + 1 << ": " << ans << "\n";
    }

}
