#include <cstdio>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;
typedef long long ll;

ll get_paint(long long x, long long r){
    return 2 * x * x + x * (2 * r - 1);
}

int main(void)
{
    int T;
    cin >> T;

    for(int t_ = 0; t_ < T; ++t_){

        ll r, t;
        cin >> r >> t;

        ll ans = 1;
        while(1){
            ll paint = get_paint(ans, r);
            if (paint == t) break;
            if (paint > t){
                --ans;
                break;
            }
            ++ans;
        }

        cout << "Case #" << (t_+1) << ": " << ans << endl;
    }

    return 0;
}
