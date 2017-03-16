#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define eprintf(...) fprintf(stderr, __VA_ARGS__)

typedef long long llong;

vector<pair<llong, int> > E;

int hum;

void add_human(int d, llong m)
{
    E.push_back(make_pair((360 - d) * m, -1));
    for (int i = 1; i <= hum; i++)
        E.push_back(make_pair((360 - d) * m + i * 360 * m, 1)); 
}

void solve(int cs)
{
    hum = 0;
    int n;
    scanf("%d", &n);    
    vector<tuple<int, int, int> > input;
    for (int i = 0; i < n; i++)
    {
        int d, h, m;
        scanf("%d %d %d", &d, &h, &m);
        input.push_back(make_tuple(d, h, m));
        hum += h;
    }
    E.clear();
    E.push_back(make_pair(0, hum)); 
    for (int i = 0; i < n; i++)
    {
        int d = get<0>(input[i]), h = get<1>(input[i]);
        llong m = get<2>(input[i]);
        for (int j = 0; j < h; j++)
            add_human(d, m + j);
    }
    sort(E.begin(), E.end());
    int pt = 0;
    int bal = 0;
    int ans = hum;
    while (pt < E.size())
    {
        int rpt = pt;
        while (rpt != E.size() && E[rpt].first == E[pt].first)
            rpt++;
        for (int i = pt; i < rpt; i++)
            bal += E[i].second;
        ans = min(ans, bal);
        eprintf("at %lld -> %d\n", E[pt].first, bal);
        pt = rpt;

    }
    printf("Case #%d: %d\n", cs, ans);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        solve(i + 1);
    }
}

