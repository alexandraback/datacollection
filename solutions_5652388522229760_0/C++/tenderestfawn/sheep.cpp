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
ll T, n;
vector<ll> zeros;

set<int> digits;

void putDigits(ll x){
    while (x){
        digits.insert(x%10);
        x/=10;
    }
}


int main(){
    cin >> T;
    for (int cse = 1; cse <= T; cse++){
        cin >> n;
        digits.clear();
        ll res = 0;
        cout << "Case #" << cse << ": ";
        if (n == 0){
            cout << "INSOMNIA" << endl;
            continue;
        }
        for (int j = 1; j < 1000; j++){
            putDigits(j*n);
            res = j*n;
            if (digits.size() >= 10){
                break;
            }
        }
        cout << res << endl;
    }


    return 0;
}


