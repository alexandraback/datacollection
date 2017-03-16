#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <algorithm>
#include <list>

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
#define mp(a,b) make_pair(a,b)
#define LL long long
#define S(n) scanf("%d", &n)
#define Sa(n,i) scanf("%d", n+i)
#define N 100001
#define MOD 1000000007

using namespace std;

LL gcd(LL p, LL q){
    while(q){
        p %= q;
        swap(p, q);
    }
    return p;
}

LL solve(LL p, LL q){
    set< pair<LL, LL> > ds;
    ds.insert(mp(1, 1));
    ds.insert(mp(0, 0));
    forn(i, 5){
        set< pair<LL, LL> > ng;
        fori(it, ds) fori(jt, ds){
            LL a, b;
            if(it->second == 0){
                a = jt->first, b = jt->second * 2;
            }else if(jt->second == 0){
                a = it->first, b = it->second * 2;
            }else{
                a = it->first * jt->second + it->second * jt->first, b = 2 * it->second * jt->second;
            }
            LL g = gcd(a, b);
            if(g > 1) a /= g, b /= g;
            ng.insert(mp(a, b));
        }
        cout << ng.size() << endl;
        ds = ng;
        fori(it, ds) cout << it->first << '/' << it->second << ' ';
        cout << endl;
    }
    return 0;
}

inline int log(LL v){
    int res = 0;
    for(; v; v >>= 1) res += 1;
    return res;
}

inline int f(LL p, LL q){
    int res = 1;
    for(;;){
        if(p < q/2){
            q /= 2;
            res += 1;
        }else
            break;
    }
    return res;
}

int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt","rt",stdin);
    freopen("/Users/ramis/Downloads/A-small-attempt0.in","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    
    
    int T;
    S(T);
    forn(_t, T){
        LL p, q;
        scanf("%lld/%lld", &p, &q);
        LL g = gcd(p, q);
        if(g > 1) p /= g, q /= g;
        int l = 0;
        for(LL t=1; l<=40; ++l, t <<= 1) if(q == t) break;
        if(l > 40) printf("Case #%d: impossible\n", _t + 1);
        else printf("Case #%d: %d\n", _t + 1, min(l, f(p, q)));
    }
    
    
    
    return 0;
}

