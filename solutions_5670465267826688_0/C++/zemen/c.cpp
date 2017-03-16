#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int) (x).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = int(a); i < int(b); ++i)

typedef long long ll;
typedef long double ld;

const int INF = 1000001000;
const ll INFL = 2000000000000001000;
int solve();


int main()
{
    srand(2317);
    cout.precision(10);
    cout.setf(ios::fixed);
    #ifdef LOCAL
    freopen("c.in", "r", stdin);
    #else
    #endif
    int tn = 1;
    cin >> tn;
    for (int i = 0; i < tn; ++i)
        solve();
    #ifdef LOCAL
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif
}

enum Qu
{
    E, I, J, K
};

struct Quat
{
    Qu a;
    bool s;

    Quat(): a(E), s(false) {}

    Quat(Qu a, bool s): a(a), s(s) {}

};

const Qu prod[][4] = 
{
    {E, I, J, K},
    {I, E, K, J},
    {J, K, E, I},
    {K, J, I, E}
};

const bool sign[][4] = 
{
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1}
};

Quat operator*(Quat a, Quat b)
{
    return Quat(prod[a.a][b.a], sign[a.a][b.a] ^ a.s ^ b.s);
}

bool operator==(Quat a, Quat b)
{
    return a.a == b.a && a.s == b.s;
}

bool operator!=(Quat a, Quat b)
{
    return a.a != b.a || a.s != b.s;
}

Qu conv(char c)
{
    if (c == 'i')
        return I;
    if (c == 'j')
        return J;
    if (c == 'k')
        return K;
    assert(false);
}

int test = 1;
string s;
vector <Quat> a;

Quat binpow(Quat a, ll deg)
{
    Quat res;
    while (deg)
    {
        if (deg & 1)
            res = res * a;
        deg >>= 1;
        a = a * a;
    }
    return res;
}

int solve()
{
    ll l, x;
    cin >> l >> x >> s;
    a.clear();
    forn (i, l)
        a.emplace_back(conv(s[i]), false);
    bool ok = true;

    Quat s_pr;
    forn (i, l)
        s_pr = s_pr * a[i];
    s_pr = binpow(s_pr, x);
    if (s_pr != Quat(E, true))
        ok = false;

    int i_len = 0;
    Quat i_pr;
    forn (i, min(10ll, x) * l)
    {
        i_pr = i_pr * a[i % l];
        ++i_len;
        if (i_pr == Quat(I, false))
            break;
    }
    if (i_pr != Quat(I, false))
        ok = false;

    int k_len = 0;
    Quat k_pr;
    forn (i, min(10ll, x) * l)
    {
        k_pr = a[(10ll * l - i - 1) % l] * k_pr;
        ++k_len;
        if (k_pr == Quat(K, false))
            break;
    }
    if (k_pr != Quat(K, false))
        ok = false;

    if (i_len + k_len > x * l)
        ok = false;

//    cerr << i_len << ' ' << k_len << '\n';
    if (ok)
    {
        vector <Quat> b;
        forn (i, x)
            b.insert(b.end(), a.begin(), a.end());
        Quat iq, jq, kq;
        forn (i, i_len)
            iq = iq * b[i];
        forab (i, i_len, sz(b) - k_len)
            jq = jq * b[i];
        forab (i, sz(b) - k_len, sz(b))
            kq = kq * b[i];
        assert(iq == Quat(I, false));
        assert(jq == Quat(J, false));
        assert(kq == Quat(K, false));
    }

    printf("Case #%d: %s\n", test++, (ok ? "YES" : "NO"));
    return 0;
}
