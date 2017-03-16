#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Input
{
    vector<int> v;

    Input(istream &in)
    {
        int l;
        in >> l;
        v.resize(l);
        for (int i = 0; i < l; ++i)
            in >> v[i];
    }
};

typedef int Output;

vector<Input> ins;
vector<Output> outs;
vector<thread> cases;

void solve(Input &in, Output &out)
{
    int n = in.v.size();
    int v = *max_element(in.v.begin(), in.v.end()), ans = v;
    for (int i = 1; i <= v; ++i)
    {
        int cur = i;
        for (int j = 0; j < n; ++j)
            cur += (in.v[j] + i - 1) / i - 1;
        ans = min(ans, cur);
    }
    out = ans;
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
