#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <cassert>
#include <cstring>
#include <cmath>
#include <fstream>
#include <algorithm>
#include <climits>
#include <iomanip> 
using namespace std;
typedef long long ll;
ll rev(ll n) {
    ll res = 0;
    while(n > 0) {
        ll x = n % 10;
        n /= 10;
        res = res * 10 + x;
    }
    return res;
}
int main()
{
    int T;
    
    ifstream fp ("/Users/aviral.gupta/Downloads/in.txt");
    ofstream ofp ("/Users/aviral.gupta/Downloads/out.txt");

    fp >> T;
    ll res[1000005] = {0};
    for (int i = 0; i < 1000001; i++) {
        if (i <= 11) {
            res[i] = i;
        } else {
            if (res[i] == 0) res[i] = res[i - 1] + 1;
            else res[i] = min (res[i], res[i - 1] + 1);
            ll x = rev(i);
            if (x > i && x <= 1000001) {
                //cout << x << endl;
                if (res[x] == 0) res[x] = res[i] + 1;
                else res[x] = min (res[x], res[i] + 1);
            }
        }
    }
    for(int k = 1; k <= T; k++) {
        long long n;
        fp >> n;
        ofp << "Case #" << k << ": " << res[n] << endl;
    }
    fp.close();
    ofp.close();
    cout << "done" << endl;
    return 0;
}
