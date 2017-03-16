#include <bits/stdc++.h>

using namespace std;

#define lol long long
#define fi first
#define se second
#define pb push_back
#define sz(s) (lol)s.size()
#define must ios_base::sync_with_stdio(0)

#define inp(s) freopen(s, "r", stdin)
#define out(s) freopen(s, "w", stdout)

const int N = 10001000;
const int mod = 1000000009;
int a[N];
bool us[N];
queue<pair<int, int>> q;

int rev(int n) {
    int x = 0;
    while(n != 0)
        x = x * 10 + n % 10, n /= 10;
    return x;
}

int main() {
    inp("input.txt");
    out("output.txt");
    must;
    int t;
//    cout << update(13);
    q.push({1, 1});
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        t = x.fi;
        a[t] = x.se;
        x.fi = rev(t);
//        cout << t << ' ' << a[t] << "\n\t";
        if(x.fi <= 1000000) {
            if(a[x.fi] == 0)
//            cout << x.fi << " ",
                q.push({x.fi, x.se + 1}), a[x.fi] = -1;
        }
//        cout << t + 1 << "\n";
        if(a[t + 1] == 0 && t + 1 <= 1000000)
            q.push({t + 1, x.se + 1}), a[t + 1] = -1;
    }
//    for(int i = 1; i <= 30; i++)
//        cout << i << ' ' << a[i] << '\n';

    cin >> t;
    for(int i = 1; i <= t; i++) {
        int n;
        cin >> n;
        cout << "Case #" << i << ": " << a[n] << "\n";
    }

}

