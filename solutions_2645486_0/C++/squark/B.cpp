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
const int MAXN = 10004;

int v[MAXN];
int s[MAXN];
int e[MAXN];

int main()
{
    #ifdef __FIO
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T, i0;
    scanf("%d", &T);
    for(i0 = 1; i0 <= T; i0++){
        cout<<"Case #"<<i0<<": ";
        int n;
        int i, j;
        int E, R;
        scanf("%d%d%d", &E, &R, &n);
        for(i = 0; i < n; i++)
            scanf("%d", &v[i]);
        j = 0;
        s[j] = n-1;
        e[j] = E;
        for(i = n-2; i >= 0; i--){
            int et = R;
            while(j >= 0 && v[i] > v[s[j]] && et < E){
                if(et + e[j] <= E){
                    et += e[j];
                    j--;
                }
                else{
                    e[j] -= E-et;
                    et = E;
                }
            }
            ++j;
            e[j] = et;
            s[j] = i;
        }
        ll ans = 0;
        for(i = 0; i <= j; i++){
            ans += (ll)e[i] * v[s[i]];
        }
        cout<<ans<<endl;
    }
    return 0;
}
