#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <ctime>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <math.h>
#include <queue>
#include <memory.h>
#include <iostream>
#include <stack>
#include <complex>
#include <list>

using namespace std;
 
void ASS(bool bb)
{
    if (!bb)
    {
        ++*(int*)0;
    }
}
 
#define FOR(i, x) for (int i = 0; i < (int)(x); i++)
#define CL(x) memset(x, 0, sizeof(x))
#define CLX(x, y) memset(x, y, sizeof(x))
 
#pragma comment(linker, "/STACK:106777216")
 
typedef vector<int> vi;

typedef long long LL;

const int K = 24;
LL ar[1 << 17];

int shift;

void gen(int g, int m, LL sum, vector<pair<LL, int> >& res)
{
    if (g == K) {
        res.push_back(make_pair(sum, m));
        return;
    }
    gen(g + 1, m, sum, res);
    gen(g + 1, m ^ (1 << g), sum + ar[shift + g], res);
}

vector<LL> V(int sh, int m)
{
    vector<LL> res;
    FOR(i, K)
        if ((m >> i) & 1)
            res.push_back(ar[sh + i]);
    return res;
}

vector<LL> P( vector<LL> a, vector<LL> b)
{
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void W(vector<LL> a)
{
    FOR(i, a.size())
    {
        if (i)
            cout << " ";
        cout << a[i];
    }
    cout << endl;
}

bool Do(vector<pair<LL, int> >& res, int sh)
{
    shift = sh;
    gen(0, 0, 0, res);
    sort(res.begin(), res.end());
    FOR(i, res.size() - 1)
        if (res[i].first == res[i + 1].first)
        {
            W(V(sh, res[i].second));
            W(V(sh, res[i].second));
            return 1;
        }
    return 0;
}

int rndInd(unsigned n)
{
    unsigned rndind = 0;
    FOR(i, 5)
        rndind = (rndind * 1000 + rand()) % n;
    return rndind & (n - 1);
}

void Solve()
{
    int n;
    cin >> n;
    FOR(i, n)
        cin >> ar[i];
    random_shuffle(ar, ar + n);
    vector<pair<LL, int> > a;
    vector<pair<LL, int> > b;
    if (Do(a, 0))
        return;
    if (Do(b, K))
        return;
    FOR(z, 80)
    {
        int aInd, bInd;
        LL val = a[aInd = rndInd(a.size())].first + b[bInd = rndInd(a.size())].first;
        size_t pb = 0;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (i == aInd)
                continue;
            while (pb < b.size() && a[i].first + b[pb].first < val)
                pb++;
            if (pb < b.size() && a[i].first + b[pb].first == val) {
                W(P(V(0, a[aInd].second), V(K, b[bInd].second)));
                W(P(V(0, a[i].second), V(K, b[pb].second)));
                return;
            }
        }
    }
    cout << "Fail" << endl;
    ASS(0);
}

int main()
{
    freopen("c:\\gcj\\in.txt", "r", stdin);
    freopen("c:\\gcj\\out.txt", "w", stdout);
    int t;
    cin >> t;
    FOR(i, t)
    {
        cerr << i << endl;
        printf("Case #%d:", (i + 1));
        Solve();
    }
    return 0;
}