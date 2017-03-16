#include <cstdio>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#define For(i, n) for (int i = 0; i < (int) n; ++i)
#define SIZE(x) ((int) (x).size())
#define mp(a, b) make_pair(a, b)
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#ifndef DG
#define DG 0
#endif
#define LOG(...) (DG ? fprintf(stderr, __VA_ARGS__) : 0)

ll digits(ll what) {
    ll res = 0;
    while (what > 0){
        res ++;
        what /= 10;
    }
    return res;
}

ll myexp(ll what) {
    ll res = 1;
    For(i, what) res *= 10;
    return res;
}

ll reverse(ll what) {
    ll res = 0;
    while (what > 0) {
        res *= 10;
        res += what % 10;
        what /= 10;
    }
    return res;
}

int main(){
    int T;
    scanf("%d", &T);
    For(cases, T) {
        ll n;
        scanf("%lld", &n);
        if (n < 10) {
            printf("Case #%d: %lld\n", cases+1, n);
            continue;
        }
        ll steps = 0, mydigits = 1;
        while (mydigits < digits(n)) {
            steps += myexp((mydigits+1) / 2) - 1;
            steps += myexp(mydigits / 2);
            mydigits ++;
        }
        ll ihave = myexp(mydigits - 1);
        if (ihave == n) {
            printf("Case #%d: %lld\n", cases+1, steps);
            continue;
        }
        bool increment = false;
        if (n % myexp((mydigits + 1) / 2) == 0) {
            increment = true;
            n --;
        }
        steps += reverse(n) % myexp(mydigits / 2);
        if (reverse(n) % myexp(mydigits / 2) == 1) steps --;
        steps += n % myexp((mydigits + 1) / 2);
        if (increment) steps ++;
        

        printf("Case #%d: %lld\n", cases+1, steps);
    }

}
