#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 1123;

R a[MAXN], b[MAXN];
int n;

set<R> iset;

int f(R *a, R *b){
    int i, j;
    
    iset.clear();
    for(i = 0; i < n; i++)
        iset.insert(a[i]);
    
    sort(b, b+n);
    int ret = 0;
    for(i = 0; i < n; i++){
        if(iset.lower_bound(b[i]) != iset.end()){
            iset.erase(iset.lower_bound(b[i]));
            ret++;
        }
    }
        
    return ret;
}

int main()
{
    #ifdef __FIO
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int i0 = 1;
    int T;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        int i, j;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
            scanf("%lf", &a[i]);
        for(i = 0; i < n; i++)
            scanf("%lf", &b[i]);
        
        printf("Case #%d: ", i0);
        printf("%d %d\n", f(a, b), n-f(b, a));
    }
    return 0;
}
