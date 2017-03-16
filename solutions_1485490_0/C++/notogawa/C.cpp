#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdint.h>
using namespace std;

int n = 0, m = 0;

uint64_t f(const vector< pair< uint64_t, uint64_t > >& as,
           const vector< pair< uint64_t, uint64_t > >& bs,
           size_t i, size_t j)
{
    if (i == n || j == m) return 0;
    if (as[i].second == bs[j].second)
    {
        if (as[i].first > bs[j].first)
        {
            vector< pair< uint64_t, uint64_t > > _as(as);
            _as[i].first -= bs[j].first;
            return bs[j].first + f(_as, bs, i, j+1);
        }
        else if (as[i].first < bs[j].first)
        {
            vector< pair< uint64_t, uint64_t > > _bs(bs);
            _bs[j].first -= as[i].first;
            return as[i].first + f(as, _bs, i+1, j);
        }
        else
        {
            return as[i].first + f(as, bs, i+1, j+1);
        }
    }
    return max(f(as,bs,i+1,j),f(as,bs,i,j+1));
}

uint64_t solve()
{
    cin >> n >> m;
    vector< pair< uint64_t, uint64_t > > lineB(n);
    vector< pair< uint64_t, uint64_t > > lineT(m);
    for (int i = 0; i < n; ++i)
        cin >> lineB[i].first >> lineB[i].second;
    for (int i = 0; i < m; ++i)
        cin >> lineT[i].first >> lineT[i].second;

    return f(lineB, lineT, 0, 0);
}

int main()
{
    int t = 0;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        cout << "Case #" << (i+1) << ": " << solve() << endl;
    }
}
