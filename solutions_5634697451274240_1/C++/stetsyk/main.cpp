#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
const int inf = 1e9 + 9;

int main()
{
    freopen("B-large.in", "r", stdin); freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for(int qw = 1; qw <= T; ++qw){
         string s;
        cin >> s;
        s += '+';
        int ans = 0;
        for(int i = 0; i < (int)s.size() - 1; ++ i){
            ans += (s[i] != s[i + 1]);
        }
        cout << "Case #" << qw <<": " << ans << "\n";
    }
    return 0;
}
