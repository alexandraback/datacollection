#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cstdlib>
#include <cmath>

#define foreach(i,v) for(typeof(v.end())i=v.begin();i!=v.end();++i) 

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

using namespace std;

#define MAX_N 20
#define MAX_KEYS 201

int dp[1 << MAX_N];
int N;
int init[MAX_KEYS];
int keys[MAX_N][MAX_KEYS];
int to_open[MAX_N];

static inline
void hplus(int *out, const int *a1, const int *a2)
{
    for (int i = 0; i < MAX_KEYS; i++)
        out[i] = a1[i] + a2[i];
}

int solve(int mask, const int *hint)
{
    int new_hint[MAX_KEYS];
    int& ret = dp[mask];
    if (ret != -1)
        return ret;

    for (int i = 0; i < N; i++) {
        if (mask & (1 << i))
            continue;
        if (!hint[to_open[i]])
            continue;
        hplus(new_hint, hint, keys[i]);
        new_hint[to_open[i]]--;
        if (solve(mask | (1 << i), new_hint) >= 0)
            return ret = i;
    }

    return ret = -2;
}

int main(int argc, const char* argv[])
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        int k;
        memset(dp, -1, sizeof(dp));
        memset(init, 0, sizeof(init));
        memset(keys, 0, sizeof(keys));
        cin >> k >> N;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            init[x]++;
        }
        for (int j = 0; j < N; j++) {
            int ki;
            cin >> to_open[j] >> ki;
            for (int k = 0; k < ki; k++) {
                int x;
                cin >> x;
                keys[j][x]++;
            }
        }
        dp[(1 << N) - 1] = 0;
        solve(0, init);
        cout << "Case #" << i << ": ";
        if (dp[0] == -2) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int mask = 0;
        do {
            cout << (dp[mask] + 1) << ' ';
            mask |= (1 << dp[mask]);
        } while (mask != (1 << N) - 1);
        cout << endl;
    }
    return 0;
}
