/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ios>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <cassert>
#include <cmath>
#include <string>
#include <stack>


using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;


int n;
vector< pl > H;

bool isGreaterOrEqual(const pl &A, const pl &B){
    return A.first * B.second >= B.first * A.second;
}

pl _add(pl A, pl B){
    return pl(A.first * B.second + B.first * A.second, A.second * B.second);
}

pl _mul(pl A, pl B){
    return pl(A.first * B.first, A.second * B.second);
}

pl _div(pl A, pl B){
    return _mul(A, pl(B.second, B.first));
}

bool check(pl A, pl B){
    pl bSpeed = pl(360, B.second);
    pl bTimeToReach = _div(pl(360 - B.first, 1), bSpeed);

    pl aSpeed = pl(360, A.second);
    pl aDist = _mul(bTimeToReach, aSpeed);
    return isGreaterOrEqual(aDist, pl(360 + 360 - A.first, 1) );
}

int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int t, d, h, m;
    cin >> t;
    for(int T = 1; T <= t; T++){
        cin >> n;
        H.clear();
        ll trackSize = 360;
        for(int i = 0; i < n; i++){
            cin >> d >> h >> m;
            for(int j = 0; j < h; j++){
                H.push_back(pl(d, (m + j)));
            }
        }
        /*sort(H.begin(), H.end());
        pl bSpeed = pl(360, H[1].second);
        pl bTimeToReach = _mul(bSpeed, pl(360 - H[1].first, 1));

        pl aSpeed = pl(360, H[0].second);
        pl aDist = _mul(bTimeToReach, aSpeed);

        int ans;
        if(isGreaterOrEqual(aDist, pl(360 + 360 - H[0].first, 1) )){
            ans = 1;
        }else{
            ans = 0;
        }*/

        int ans;
        bool A = check(H[1], H[0]);
        bool B = check(H[0], H[1]);
        if(A || B){
            ans = 1;
        }else{
            ans = 0;
        }
        cout << "Case #" << T << ": " << ans << endl;
    }

}
