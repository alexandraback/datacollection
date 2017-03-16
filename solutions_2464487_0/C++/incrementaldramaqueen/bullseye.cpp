#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <math.h>
#include <queue>
#include <string.h>
#include <sstream>
#define fo(i,n) for(i=0;i<n;i++)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define mset(a,v) memset(a, v, sizeof(a))
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;

ll r, v;

bool check(ll m) {
    ll d = v / m;
    if (d <= 2 * (m - 1))
        return false;
    d -= 2 * (m-1);
    if ((d - 1) / 2 >= r)
        return true;
    return false;
}

int main(void) {
    int t, tt;
    cin >> t;
    fo(tt, t) {

        cin >> r >> v;
        ll l = 0, rr = 100000000000;
        while (l < rr) {
            ll m = (l + rr + 1) / 2;
            if (check(m))
                l = m;
            else
                rr = m - 1;
        }

        cout << "Case #" << tt + 1 << ": " << l << endl;
    }
}
