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

const lol N = 10001000;
const lol mod = 1000000009;
lol a[N];
bool us[N];
queue<pair<lol, lol>> q;

lol dlina(lol n) {
    lol rev = 0, l = 0;
    while(n) {
        l++;
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    return l - 1;
}
lol rev(lol n) {
    lol x = 0;
    while(n != 0)
        x = x * 10 + n % 10, n /= 10;
    return x;
}

lol ans(lol n) {
    lol l = dlina(n);
    if(l <= 2)
        return a[n];
    lol x = n;
    for(lol i = 1; i < l; i++)
        x /= 10;
    if(x == 10) {
        x = 0;
        for(lol i = 1; i <= l; i++)
            x = x * 10 + 9;
//        cout << n << ' ' << x << "\n";
        return ans(x) + n - x;
    }
    for(lol i = 1; i < l; i++)
        x *= 10;
    x++;
    if(x > n) {
        x = 0;
        for(lol i = 1; i <= l; i++)
            i = i * 10 + 9;
        return ans(x) + n - x;
    }
    return ans(rev(x)) + n - x + 1;
}



int main() {
    inp("input.txt");
    out("output.txt");
    must;
    lol t;
    q.push({1, 1});
    while(!q.empty()) {
        auto x = q.front();
        q.pop();
        t = x.fi;
        a[t] = x.se;
        x.fi = rev(t);
        if(x.fi <= 1000000) {
            if(a[x.fi] == 0)
                q.push({x.fi, x.se + 1}), a[x.fi] = -1;
        }
        if(a[t + 1] == 0 && t + 1 <= 1000000)
            q.push({t + 1, x.se + 1}), a[t + 1] = -1;
    }
    cin >> t;
    for(lol i = 1; i <= t; i++) {
        lol n;
        cin >> n;

        cout << "Case #" << i << ": " << ans(n) << "\n";
//        system("pause");
    }

}


