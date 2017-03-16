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
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef complex<ll> pt;

int T, N, F[1000], d[1000];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
        memset(d, 0, sizeof d);
        cin >> N;
        for (int i = 0; i < N; ++i)
            cin >> F[i], --F[i];
        int cyclen = 0, ans = 0;
        for (int i = 0; i < N; ++i)
        {
            int st = i;
            for (int j = 0; j < N; ++j)
            {
                if (F[F[st]] == st)
                {
                    d[st] = max(d[st], j+1);
                    break;
                }
                st = F[st];
            }
            int fi = F[st], len = 1;
            while (fi != st)
                fi = F[fi], ++len;
            cyclen = max(cyclen, len);
        }
        for (int i = 0; i < N; ++i)
        {
            ans += d[i];
        }
        cout << "Case #" << z << ": " << max(cyclen, ans) << endl;
    }
}
