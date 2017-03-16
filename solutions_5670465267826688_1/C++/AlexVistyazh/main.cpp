#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>

using namespace std;

template<class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

enum IJK { ONE = 1, MINUS_ONE = -1, I = 2, MINUS_I = -2, J = 3, MINUS_J = -3, K = 4, MINUS_K = -4 };

IJK mul(IJK a, IJK b) {
    if (a == ONE || a == MINUS_ONE || b == ONE || b == MINUS_ONE) return IJK((int)a * (int)b);
    int key = 1;

    if ((int)a < 0) {
        a = IJK((int)a * -1);
        key *= -1;
    }

    if ((int)b < 0) {
        b = IJK((int)b * -1);
        key *= -1;
    }

    IJK res;
    if (a == I && b == I) res = MINUS_ONE;
    else if (a == I && b == J) res = K;
    else if (a == I && b == K) res = MINUS_J;
    else if (a == J && b == I) res = MINUS_K;
    else if (a == J && b == J) res = MINUS_ONE;
    else if (a == J && b == K) res = I;
    else if (a == K && b == I) res = J;
    else if (a == K && b == J) res = MINUS_I;
    else res = MINUS_ONE;
    if (key == -1) res = IJK((int)res * -1);
    return res;
}

IJK CharToIJK(char x) {
    if (x == 'i') return I;
    if (x == 'j') return J;
    return K;
}

void solve(int tc) {
    int L;
    ll X;
    string s;

    cin >> L >> X;
    cin >> s;

    IJK sVal = ONE;

    for (size_t i = 0; i < s.size(); i++)
        sVal = mul(sVal, CharToIJK(s[i]));

    int q = X % 4;

    IJK tVal = ONE;

    while (q--) {
        tVal = mul(tVal, sVal);
    }

    IJK need = mul(I, mul(J, K));

    if (tVal != need) {
        cout << "Case #" << tc << ": " << "NO" << "\n";
        return;
    }

    if (L * X < 3) {
        cout << "Case #" << tc << ": " << "NO" << "\n";
        return;
    }

    int it = 0;

    IJK cur = ONE;
    ll posI = (ll)1e17;

    for (int i = 1; i <= 100000; i++, it = (it + 1) % ((int)s.size())) {
        cur = mul(cur, CharToIJK(s[it]));
        if (cur == I) {
            posI = i;
            break;
        }
    }

    it = (int)s.size() - 1;

    ll posK = (ll)1e17;

    cur = ONE;

    for (ll i = 1; i <= 100000; i++, it = (it - 1 + (int)s.size()) % ((int)s.size())) {
        cur = mul(CharToIJK(s[it]), cur);
        if (cur == K) {
            posK = i;
            break;
        }
    }

    if (posI + posK + 1 <= L * X) {
        cout << "Case #" << tc << ": " << "YES" << "\n";
        return;
    }

    cout << "Case #" << tc << ": " << "NO" << "\n";
}

int main()
{
    srand(time(0));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int T;

    cin >> T;

    for (int i = 1; i <= T; i++)
        solve(i);

    return 0;
}
