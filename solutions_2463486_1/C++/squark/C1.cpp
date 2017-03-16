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
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 1000004;

ll ans[MAXN];
char buf[15];
int cnt;

bool pal(ll a){
    int i, n;
    n = sprintf(buf, "%lld", a);
    for(i = 0; i < n-1-i; i++)
        if(buf[i] != buf[n-1-i])
            return false;
    return true;
}

/*ll complete(int a, bool tag){
    
}*/

bool pal(int a){
    int i, n;
    n = sprintf(buf, "%d", a);
    for(i = 0; i < n-1-i; i++)
        if(buf[i] != buf[n-1-i])
            return false;
    return true;
}

int main()
{
    #ifdef __FIO
    freopen("C-large-1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <= 10000000; i0++){
        if(pal(i0) && pal((ll)i0*i0))
            ans[cnt++] = (ll)i0*i0;
    }
    //cout<<cnt<<endl;
    for(i0 = 1; i0 <= T; i0++){
        printf("Case #%d: ", i0);
        ll A, B;
        cin>>A>>B;
        cout<<upper_bound(ans, ans+cnt, B)-lower_bound(ans, ans+cnt, A)<<endl;
    }
    return 0;
}
