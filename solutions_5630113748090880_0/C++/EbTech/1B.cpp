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

int T, N, v, f[2501];

int main()
{
    ios::sync_with_stdio(0);
    cin >> T;
    for (int z = 1; z <= T; ++z)
    {
        memset(f, 0, sizeof f);
        cin >> N;
        int lines = 2*N - 1;
        for (int i = 0; i < N*lines; ++i)
            cin >> v, ++f[v];
        cout << "Case #" << z << ":";
        for (v = 1; v <= 2500; ++v)
            if (f[v] & 1)
                cout << ' ' << v;
        cout << endl;
    }
}
