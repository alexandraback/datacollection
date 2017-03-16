#include<bits/stdc++.h>
using namespace std;

#define LET(x, a)  __typeof(a) x(a)
#define TR(v, it) for(LET(it, v.begin()); it != v.end(); it++)
#define si(x) scanf("%d",&x)
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define INF 1000000000
#define MOD 1000000007
#define SET(x,y) memset(x,y,sizeof(x));
#define LL long long int
#define ULL unsigned LL
#define PII pair<int, int>
LL rev(LL x) {
    char num[20];
    sprintf(num, "%Ld", x);
    reverse(num, num + strlen(num));
    sscanf(num, "%Ld", &x);
    return x;
}

LL getpow(LL a, LL b) {
    LL ret = 1;
    while (b--) {
        ret *= a;
    }
    return ret;
}
int main() {
    int t;
    LL  num;
    string inp;
    cin >> t;
    int cs = 0;
    while (t--) {
        cin >> inp;
        sscanf(inp.c_str(), "%Ld", &num);
        int len = inp.size();
        LL cans = 0;
        int x;
        for (int clen = 1; clen < len; clen++) {
            x = clen / 2;
            cans += getpow(10, x) + getpow(10, clen - x) - 1;
        }
        LL cval = getpow(10, len - 1);
        if (len == 1)
            cval = 0;
        LL nval = num - cval;
        x = len / 2;
        LL tadd = 0;
        for (int i = len - 1; i >= x; i--) {
            for (int j = 9; j >= 0; j--) {
                if (rev(cval + j * getpow(10, len - 1 - i) + tadd) <= num) {
                    tadd += j * getpow(10, len - 1 - i);
                    break;
                }
            }
        }
        nval = min(nval, tadd + (num - rev(cval + tadd)) + 1);
        printf("Case #%d: %Ld\n", ++cs, cans + nval);
    }
    return 0;
}

