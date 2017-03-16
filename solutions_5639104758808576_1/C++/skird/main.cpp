#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Input
{
    vector<int> v;

    Input(istream &in)
    {
        int l;
        string s;
        in >> l >> s;
        for (int i = 0; i <= l; ++i)
            v.push_back(s[i] - '0');
    }
};

typedef int Output;

vector<Input> ins;
vector<Output> outs;
vector<thread> cases;

void solve(Input &in, Output &out)
{
    int n = in.v.size();
    for (int i = 0; i <= n; ++i)
    {
        bool ok = 1;
        for (int j = 0, s = 0; j < n; ++j)
        {
            if (in.v[j] > 0 && s < j)
                ok = 0;
            s += in.v[j];
        }
        if (ok)
        {
            out = i;
            return;
        }
        in.v[0]++;
    }
    assert(false);
}

void print(const Output &o)
{
    printf("%d", o);
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
