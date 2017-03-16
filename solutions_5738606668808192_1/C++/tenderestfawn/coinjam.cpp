#include <set>
#include <iostream>
#include <cmath>
#include <vector>
#include <limits>
#include <utility>

using namespace std;

#define MAXN 1005
#define MAXD 50
#define MOD 1000000007

typedef long long ll;
ll T, n, j;

ll num[MAXD];
ll val[11][MAXD][MAXD];

bool sieve[MAXN];
vector<ll> prime;

void genVal(){
    memset(val, 0, sizeof(val));
    for (int i = 2; i <= 10; i++){
        val[i][0][0] = 1;
        for (int j = 1; j < MAXD; j++){
            for (int k = 0; k < MAXD; k++){
                val[i][j][k] = val[i][j-1][k]*i;
            }
            for (int k = 0; k < MAXD; k++){
                if (val[i][j][k] >= 10){
                    val[i][j][k+1] += val[i][j][k]/10;
                    val[i][j][k] %= 10;
                }
            }
        }
    }
}

void sumVal(ll x[MAXD]){
    for (int i = 0; i < MAXD; i++){
        num[i] += x[i];
        if (num[i] >= 10){
            num[i+1] += 1;
            num[i] -= 10;
        }
    }
}

bool divs(ll div){
    ll rem = 0;
    for (int i = MAXD-1; i >= 0; i--){
        rem = rem*10 + num[i];
        if (rem >= div){
            rem %= div;
        }
    }
    return rem == 0;
}

void genNum(ll bmp, ll base){
    memset(num, 0, sizeof(num));
}

void genPrime(){
    memset(sieve, true, sizeof(sieve));
    sieve[0] = sieve[1] = false;
    for (int p=2; p*p<MAXN; p++)
    {
        if (sieve[p] == true)
        {
            for (int i=p*2; i<MAXN; i += p)
                sieve[i] = false;
        }
    }
    for (int i = 0;i < MAXN; i++){
        if (sieve[i]){
            prime.push_back(i);
        }
    }
}

void getNum(ll btmp, ll base){
    memset(num, 0, sizeof(num));
    ll c = 0;
    while (btmp){
        if (btmp & 1LL){
            sumVal(val[base][c]);
        }
        c++;
        btmp >>= 1LL;
    }

}

int main(){
    genVal();
    genPrime();

    cin >> T;
    for (int cse = 1; cse <= T; cse++){
        cout << "Case #" << cse << ":" << endl;
        cin >> n >> j;
        ll found = 0;
        for (ll i = 0; i < (1LL << (n-2)) && found < j; i++){
            ll btmp = (1LL << (n-1)) + (i << 1) + 1;
            bool isOne = true;
            vector<ll> divisors;
            for (ll a = 2; a <= 10; a++){
                getNum(btmp, a);
                bool isComposite = false;
                for (auto b : prime){
                    if (divs(b)){
                        isComposite = true;
                        divisors.push_back(b);
                        break;
                    }
                }
                if (!isComposite){
                    isOne = false;
                    break;
                }
            }
            if (isOne){
                found++;
                vector<int> btset;
                while (btmp){
                    btset.push_back(btmp&1);
                    btmp >>= 1LL;
                }
                for (auto it = btset.rbegin(); it != btset.rend(); it++){
                    cout << *it;
                }
                for (int k = 0; k < divisors.size(); k++){
                    cout << " ";
                    cout << divisors[k];
                }
                cout << endl;

            }
        }


    }


    return 0;
}


