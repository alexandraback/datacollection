#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <complex>
#define MINF 0xc0c0c0c0
#define INF 0x3f3f3f3f
#define MOD 1000000007

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,int> pii;
typedef complex<ll> pt;

int T;
ll E, R, N, v[10000];

int main()
{
    ios::sync_with_stdio(0);
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
        cin >> E >> R >> N;
        R = min(E, R);
        vector<pii> events;
        for (int i = 0; i < N; ++i)
        {
            cin >> v[i];
            events.push_back(pii(R*i, -i));
            events.push_back(pii(R*i+E, i));
        }
        sort(events.begin(), events.end());
        ll ans = 0;
        set<pii> s;
        s.insert(pii(v[0], 0));
        for (int i = 1; i < events.size(); ++i)
        {
            int energy = events[i].first - events[i-1].first;
            set<pii>::iterator itr = s.end(); --itr;
            ans += energy * itr->first;
            int idx = abs(events[i].second);
            if (events[i].second < 0)
                s.insert(pii(v[idx], idx));
            else
                s.erase(pii(v[idx], idx));
        }
        cout << "Case #" << z << ": " << ans << endl;
    }
}
