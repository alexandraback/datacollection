#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <iostream>
#include <ctime>
#include <cassert>
#include <sstream>
//~ #include <unordered_map>
//~ #include <unordered_set>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long
#define SZ(x) (int)((x).size())

int ans,t;
set<ll> myset;

bool solve(ll p, ll q) {
    myset.clear();
    while (true) {
        if (ans > 50) return false;
        if (p == q) {t = min(t,ans); break; }
        if (myset.find(p) != myset.end()) return false;
        myset.insert(p);
        ans++;
        p *= 2LL;
        if (p > q) { t = min(t,ans); p -= q; }
    }
    return true;
}

int main() {
    //~ cin.sync_with_stdio(false);
    int nt,nteste=1;
    ll p,q;
    scanf("%d",&nt);
    while (nt--) {
        scanf("%lld/%lld",&p,&q);
        printf("Case #%d: ",nteste++);
        ans = 0; t = INF;
        if (!solve(p,q)) printf("impossible\n");
        else printf("%d\n",t);
    }
    
    return 0;
}
