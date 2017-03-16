// Problem Problem A. Counter Culture
// Para mi esposa Susana <3
#include <iostream>
#include <sstream>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <functional>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <stdio.h>
#include <string.h>
using namespace std;

#define FOR(i,a,b)  for(int i=(a),_##i=(b);i<_##i;++i)
#define F(i,a)      FOR(i,0,a)
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define MP          make_pair
#define S           size()
typedef long long   LL;

LL N;

LL reverseInt(LL x) {
    LL r = 0;
    while(x) {
        LL a = x%10LL;
        r = r*10LL + a;
        x /= 10LL;
    }
    return r;
}

map<LL, LL> mapa;

LL getMod(LL x){
    string s = to_string(x);
    int p = s.S;
    if(p&1) p = p/2LL + 1LL;
    else p = p/2LL;
    LL r = 1LL;
    F(i, p) r *= 10LL;
    return r;
}

LL getJumps(LL x) {
    if(x == 1LL) return 1LL;
    if(mapa.find(x) != mapa.end())
        return mapa[x];
    LL xr = -1LL;
    if(x > 10LL && (x % 10LL != 0LL) ) {
        LL a = reverseInt(x);
        if(a < x) {
            LL aux = getJumps(a);
            xr = getJumps(x-1LL);
            if(aux < xr) {
                mapa[a] = aux;
                cout << "jump " << x << endl;
                return aux + 1LL;
            }
        }
    }
    if(xr == -1LL) xr = getJumps(x-1LL);
    mapa[x] = xr + 1LL;
    return xr + 1LL;
}

int solve(){
    LL r = 0;
    while(N) {
        if(N <= 10) {
            N--;
        }
        else{
            LL mod = getMod(N);
            if(N % mod == 1LL) {
                LL a = reverseInt(N);
                if(a < N) N = a;
                else N--;
            }
            else{
                N--;
            }
        }
        r++;
    }
    return r;
}

int main(){
	// freopen("a.in.txt", "r", stdin);
	// freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-large.in", "r", stdin);
	freopen("a.out.txt", "w", stdout);
	int T;
    scanf("%d", &T);
    F(cas, T) {
        cin >> N;
        printf("Case #%d: %d\n", cas+1, solve());
    }
    //cout << mapa.size() << endl;
}
