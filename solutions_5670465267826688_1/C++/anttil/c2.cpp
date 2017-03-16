#include <iostream>

using namespace std;

#define ll long long

struct Q {
    int s;
    char x;
};

Q mul(Q a, Q b) {
    Q u;
    u.s = a.s*b.s;
    if (a.x == '1') u.x = b.x;
    if (a.x == 'i' && b.x == '1') u.x = 'i';
    if (a.x == 'i' && b.x == 'i') u.s = -u.s, u.x = '1';
    if (a.x == 'i' && b.x == 'j') u.x = 'k';
    if (a.x == 'i' && b.x == 'k') u.s = -u.s, u.x = 'j';
    if (a.x == 'j' && b.x == '1') u.x = 'j';
    if (a.x == 'j' && b.x == 'i') u.s = -u.s, u.x = 'k';
    if (a.x == 'j' && b.x == 'j') u.s = -u.s, u.x = '1';
    if (a.x == 'j' && b.x == 'k') u.x = 'i';
    if (a.x == 'k' && b.x == '1') u.x = 'k';
    if (a.x == 'k' && b.x == 'i') u.x = 'j';
    if (a.x == 'k' && b.x == 'j') u.s = -u.s, u.x = 'i';
    if (a.x == 'k' && b.x == 'k') u.s = -u.s, u.x = '1';
    return u;
}

Q pow(Q a, ll k) {
    if (k == 0) return {1, '1'};
    if (k%2 == 0) {
        Q u = pow(a, k/2);
        return mul(u,u);
    } else {
        Q u = pow(a, k-1);
        return mul(u,a);
    }
}

Q imul(Q a, Q b) {
    Q u;
    u.s = a.s*b.s;
    if (b.x == '1' && a.x == '1') u.x = '1';
    if (b.x == '1' && a.x == 'i') u.s = -u.s, u.x = 'i';
    if (b.x == '1' && a.x == 'j') u.s = -u.s, u.x = 'j';
    if (b.x == '1' && a.x == 'k') u.s = -u.s, u.x = 'k';
    if (b.x == 'i' && a.x == '1') u.x = 'i';
    if (b.x == 'i' && a.x == 'i') u.x = '1';
    if (b.x == 'i' && a.x == 'j') u.s = -u.s, u.x = 'k';
    if (b.x == 'i' && a.x == 'k') u.x = 'j';
    if (b.x == 'j' && a.x == '1') u.x = 'j';
    if (b.x == 'j' && a.x == 'i') u.x = 'k';
    if (b.x == 'j' && a.x == 'j') u.x = '1';
    if (b.x == 'j' && a.x == 'k') u.s = -u.s, u.x = 'i';
    if (b.x == 'k' && a.x == '1') u.x = 'k';
    if (b.x == 'k' && a.x == 'i') u.s = -u.s, u.x = 'j';
    if (b.x == 'k' && a.x == 'j') u.x = 'i';
    if (b.x == 'k' && a.x == 'k') u.x = '1';
    return u;
}

int t;
ll l, c;
string s;

void solve(int x) {
    cin >> l >> c;
    cin >> s;
    cout << "Case #" << x << ": ";
    Q u = {1, '1'};
    for (int i = 0; i < l; i++) {
        u = mul(u, {1, s[i]});
    }
    Q z = pow(u, c);
    if (z.s != -1 || z.x != '1') {
        cout << "NO\n";
        return;
    }
    u = {1, '1'};
    int c1 = 0;
    bool ok1 = false;
    for (int h = 0; h < 20; h++) {
        for (int i = 0; i < l; i++) {
            c1++;
            u = mul(u, {1, s[i]});
            if (u.s == 1 && u.x == 'i') {
                ok1 = true;
                goto lol1;
            }
        }
    }
    lol1:
    u = {-1, '1'};
    int c2 = 0;
    bool ok2 = false;
    for (int h = 0; h < 20; h++) {
        for (int i = l-1; i >= 0; i--) {
            c2++;
            u = imul({1, s[i]}, u);
            if (u.s == 1 && u.x == 'k') {
                ok2 = true;
                goto lol2;
            }
        }
    }
    lol2:
    if (ok1 && ok2 && c1+c2 < l*c) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
}
