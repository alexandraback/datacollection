#include <math.h>

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

vector<pair<ll, ll> > hikers;

vector<pair<double, int> > finish;

void put(ll start, ll m, int x)
{
    double t = (360.0 - start) / (360.0 / m);
    cerr << t << " - " << x << "\n";
    finish.push_back(make_pair(
        t, 
        x));
}

int solve()
{
    int N;
    cin >> N;
    hikers.clear();
    finish.clear();
    for(int i = 0; i < N; ++i)
    {
        long long D, H, M;
        cin >> D >> H >> M;
        for(int j = 0; j < H; ++j)
            hikers.push_back(make_pair(M + j, D));
    }
    sort(hikers.begin(), hikers.end());
    const int L = hikers.size();
    cerr << L << "\n";
    if(L <= 1)
        return 0;
    for(int i = 0; i < L; ++i)
    {
        put(hikers[i].second, hikers[i].first, -1);
        for(int j = 1; j <= 2 * L; ++j)
            put(hikers[i].second - 360 * j, hikers[i].first, 1);
    }
    sort(finish.begin(), finish.end());
    int res = L;
    int tmp = L;
    int cur = 0;
    while(cur < finish.size())
    {
        double t = finish[cur].first;
        for(; cur < finish.size() && fabs(finish[cur].first - t) < 1e-7; ++cur)
            tmp += finish[cur].second;
        if(res > tmp)
        {
            cerr << t << " " << tmp << "\n";
            res = tmp;
        }
    }
    return res;
}

int main()
{
    int T;
    cin >> T;
    for(int t = 1; t <= T; ++t)
    {
        cerr << "Solving #" << t << "\n";
        cout << "Case #" << t << ": " << solve() << "\n";
    }
    return 0;
}
