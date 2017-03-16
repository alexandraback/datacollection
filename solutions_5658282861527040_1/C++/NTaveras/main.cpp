#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long llong;

int bitsa[55];
int bitsb[55];
int bitsk[55];
llong memo[50][3][3][3];
bool getA(bool aOnLimit, int bit, int newbit){
    if(!aOnLimit) return false;
    int prev = bitsa[bit];
    if(prev == 1 && newbit == 0) return false;
    return true;
}
bool getB(bool bOnLimit, int bit, int newbit){
    if(!bOnLimit) return false;
    int prev = bitsb[bit];
    if(prev == 1 && newbit == 0) return false;
    return true;
}
bool getK(bool kOnLimit, int bit, int newbit){
    if(!kOnLimit) return false;
    int prev = bitsk[bit];
    if(prev == 1 && newbit == 0) return false;
    return true;
}


llong dp(int bit, bool aOnLimit, bool bOnLimit, bool kOnLimit){
    if(bit < 0) return 1;
    if(memo[bit][aOnLimit][bOnLimit][kOnLimit] != -1) return memo[bit][aOnLimit][bOnLimit][kOnLimit];
    llong res = 0;
    // first a, then b

    // 0, 0
    res += dp(bit - 1, getA(aOnLimit, bit, 0), getB(bOnLimit, bit, 0), getK(kOnLimit, bit, 0));
    // 1, 0

    // Solo puedo poner un 1 en A si va un 1 o no esta en limite
    if(bitsa[bit] == 1 || !aOnLimit)
        res += dp(bit - 1, getA(aOnLimit, bit, 1), getB(bOnLimit, bit, 0), getK(kOnLimit, bit, 0));

    // 0, 1

    // Solo puedo poner un 1 en B si va un 1 o no esta en limite
    if(bitsb[bit] == 1 || !bOnLimit)
        res += dp(bit - 1, getA(aOnLimit, bit, 0), getB(bOnLimit, bit, 1), getK(kOnLimit, bit, 0));

    // 1,1

    // A tiene que tener 1 o no estar en limite
    if(bitsa[bit] == 1 || !aOnLimit){
        // B tiene que tener 1 o no estar en limite
        if(bitsb[bit] == 1 || !bOnLimit){
            // K tiene que tener 1 o no esta en limite
            if(bitsk[bit] == 1 || !kOnLimit){
                res += dp(bit - 1, getA(aOnLimit, bit, 1), getB(bOnLimit, bit, 1), getK(kOnLimit, bit, 1));
            }
        }
    }
    return memo[bit][aOnLimit][bOnLimit][kOnLimit] = res;
}
int main(int argc, char* argv[]) {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int tc;
    cin >> tc;
    int t = 1;
    while(tc--){
        llong a, b, k;
        cin >> a >> b >> k;
        --a, --b, --k;
        for(int i = 0; i <= 35; ++i) bitsa[i] = ( (a & (1LL<<i)) ? 1 : 0 );
        for(int i = 0; i <= 35; ++i) bitsb[i] = ( (b & (1LL<<i)) ? 1 : 0 );
        for(int i = 0; i <= 35; ++i) bitsk[i] = ( (k & (1LL<<i)) ? 1 : 0 );
        int bit = 0;
        for(int i = 0; i < 50; ++i) 
            if(bitsa[i] || bitsb[i] || bitsk[i])
                bit = i;
        memset(memo, -1, sizeof(memo));
        cout << "Case #" << t << ": " << dp(bit, true, true, true) << endl;
        t++;
    }
    return 0;
}
