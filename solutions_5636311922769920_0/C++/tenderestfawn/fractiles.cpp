#include <set>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

#define MAXN 1005
#define MAXD 30
#define MOD 1000000007

typedef long long ll;
ll T, k, c, s;

ll ipow(ll x, ll e){
    ll res = 1;
    for (int i = 0; i < e; i++){
        res *= x;
    }
    return res;
}

int main(){
    cin >> T;
    for (int cse = 1; cse <= T; cse++){
        cout << "Case #" << cse << ": ";
        cin >> k >> c >> s;
        if (s * c < k){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        ll used = 0;
        ll num = 0;
        for (int i = 0; i < k && used < s; i+= c, used++){
            if (i) cout << " ";
            ll ind = 0;
            ll before = ipow(k, c-1);
            for (int j = 0; j < c; j++){
                if (num < s)
                    ind += num * before;
                num++;
                before/=k;
            }
            cout << ind + 1;
        }
        cout << endl;

    }


    return 0;
}


