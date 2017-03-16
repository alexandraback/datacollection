#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll lt[105];

bool solve(int k, int c, int s) {
    lt[0] = 1;
    for (int i = 1; i <= c; i++) lt[i] = lt[i-1] * k;
    vector<ll> kq;
    kq.clear();
    for (int i = 1; i <= k; i += c) {
        ll tmp = lt[c-1] * (i-1) + 1;
        int tg = min(k-i, c-1);
        for (int j = 1; j <= tg; j++)
            tmp += (i+j-1)*lt[c-j-1];
        kq.push_back(tmp);
    }
    int nn = kq.size();
    if (nn > s) return false;
    //cout << kq.size() << ' ';
    for (int i = 0; i < kq.size(); i++) cout << kq[i] << ' ';
    return true;
}

int main() {
    //freopen("D.in", "r", stdin);
    //freopen("D.out", "w", stdout);
    int ct;
    cin >> ct;
    for (int nt = 1; nt <= ct; nt++) {
        int k, c, s;
        cin >> k >> c >> s;
        cout << "Case #" << nt << ": ";
        if (!solve(k,c,s)) cout << "IMPOSSIBLE\n";
        else cout << '\n';
    }
    return 0;
}
