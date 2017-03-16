#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
ll N;
map<ll, ll> dp;

ll rev(ll n) {
    ll res = 0;
    while(n) {
        res = res*10 + n%10;
        n/= 10;
    }
    return res;
}

ll solve(ll cur) {
    if(cur == 1)
        return 1;
    if(dp.find(cur) != dp.end())
        return dp[cur];

    ll res = 1+solve(cur-1);

    if(cur%10) {
        ll revCur = rev(cur);
        if(revCur < cur && revCur <= N)
            res = min(res, 1+solve(revCur));
    }

    dp[cur] = res;
    return res;
}

int main() {
    int tc;
    cin >> tc;
    for(int ii=1;ii<=tc;++ii) {
        dp.clear();
        cin >> N;
        cout << "Case #" << ii << ": " << solve(N) << "\n";
    }
    return 0;
}
