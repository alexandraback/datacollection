#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Input
{
    ll x;
    string s;

    Input(istream &in)
    {
        int l;
        in >> l >> x >> s;
    }
};

typedef int Output;

vector<Input> ins;
vector<Output> outs;
vector<thread> cases;

const int table[4][4] =
{
    {0, 1, 2, 3},
    {1, 0, 3, 2},
    {2, 3, 0, 1},
    {3, 2, 1, 0},
};

const int sign[4][4] =
{
    {0, 0, 0, 0},
    {0, 1, 0, 1},
    {0, 1, 1, 0},
    {0, 0, 1, 1},
};

struct quat
{
    int t, s;

    quat(char c): s(0)
    {
        if (c == '1') t = 0;
        if (c == 'i') t = 1;
        if (c == 'j') t = 2;
        if (c == 'k') t = 3;
    }
    quat(): t(0), s(0) {}
    quat(int _t, int _s): t(_t), s(_s) {}

    quat operator * (const quat &q) const
    {
        return quat(table[t][q.t], s ^ q.s ^ sign[t][q.t]);
    }
};

quat power(quat a, ll p)
{
    if (!p) return quat();
    quat x = power(a, p / 2);
    x = x * x;
    if (p & 1) x = x * a;
    return x;
}

void solve(Input &in, Output &out)
{
    quat res;
    for (size_t i = 0; i < in.s.length(); ++i)
        res = res * quat(in.s[i]);
    res = power(res, in.x);
    if (res.t != 0 || res.s != 1)
    {
        out = false;
        return;
    }

    in.x = min(in.x, 16LL);
    string s;
    for (int i = 0; i < in.x; ++i)
        s += in.s;
    res = quat();
    int first = s.length(), second = -1;
    for (size_t i = 0; i < s.length(); ++i)
    {
        if (res.t == 1 && res.s == 0)
        {
            first = i;
            break;
        }
        res = res * quat(s[i]);
    }
    res = quat();
    for (int i = s.length() - 1; i >= 0; --i)
    {
        if (res.t == 3 && res.s == 0)
        {
            second = i;
            break;
        }
        res = quat(s[i]) * res;
    }
    out = (first <= second);
}

void print(const Output &o)
{
    printf("%s", o ? "YES" : "NO");
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ins.emplace_back(cin);
        outs.push_back(Output());
    }
    for (int i = 0; i < t; ++i)
        cases.emplace_back(solve, ref(ins[i]), ref(outs[i]));
    for (int i = 0; i < t; ++i)
        cases[i].join();
    for (int i = 0; i < t; ++i)
    {
        printf("Case #%d: ", i + 1);
        print(outs[i]);
        printf("\n");
    }
    return 0;
}
