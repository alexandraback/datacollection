#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
    ios_base::sync_with_stdio(0);
#ifdef TASK
    freopen(TASK".in","rt",stdin);
    //freopen("output.txt","rt",stdin);
    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
//#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2000000000//2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-9
#define N 200
/* --------- END TEMPLATE CODE --------- */

int a[N], n, k;
int p[N], res[N], np[N];

int brute() {
    int mm = 1 << n;
    int ans = 0;
    //forn(i, n) a[i] -= 1;
    forn(mask, mm){
        vector<bool> pp(n, 0), npp(n);
        forn(i, n) if((mask >> i) & 1) pp[i] = 1;
        bool ok = true;
        forn(_j, k) {
            forn(i, n) npp[i] = 0;
            forn(i, n) if(pp[i]){
                if(npp[a[i]]){
                    ok = false;
                    break;
                }
                npp[a[i]] = 1;
            }
            if(!ok) break;
            forn(i, n) pp[i] = npp[i];
        }
        ans += ok;
    }
    return ans;
}

int get_p(int v, int *pp){
    return pp[v] == v ? v : pp[v] = get_p(pp[v], pp);
}

int solve(){
    //vector<int> p(n), np(n), res(n);
    forn(i, n) a[i] -= 1;
    forn(i, n) p[i] = i, res[i] = i;
    int m = min(k, 10000);
    forn(_ii, m){
        forn(i, n) np[i] = -1;
        forn(i, n) if(p[i] >= 0) {
            int j = a[i];
            if(np[j] == -1) np[j] = p[i];
            else{
                int x = min(get_p(p[i], res), get_p(np[j], res));
                res[p[i]] = res[np[j]] = x;
                np[j] = x;
            }
        }
        forn(i, n) p[i] = np[i];
    }
    int ans = 1;
    vector<int> cnt(n, 0);
    forn(i, n) cnt[get_p(res[i], res)] += 1;
    forn(i, n) {
        ans = ans * (cnt[i] + 1) % MOD;
    }
    return ans;
}


void smain() {
    for(int t = 0;  cin >> n >> k; ++t){
        forn(i, n) cin >> a[i];
        
        /*
        n = 10;
        forn(i, n) a[i] = rand() % n + 1;
        k = rand() % 105 + 1;
        */
        int r1 = solve();
        int r2 = brute();
        if(r1 != r2){
            cout << "Expected " << r2 << " Found " << r1 << " at " << n << ' ' << k <<  endl;
            forn(i, n) cout << a[i] << ' ';
            return;
        }
        cout << r1 << endl;
    }
}

