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
    cin.tie(0);
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/A-small-attempt1.in.txt","rt",stdin);
    freopen("output.txt","wt",stdout);
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
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2000000000//2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-8
#define N 20000000
/* --------- END TEMPLATE CODE --------- */


int d[N];
int a[20];
inline int rev(int n){
    int m = 0;
    for(int x = n; x; x /= 10) a[m++] = x % 10;
    reverse(a, a + m);
    int t = 1, res = 0;
    forn(i, m) {
        res += a[i] * t;
        t *= 10;
    }
    return res;
}

void smain() {
    int T, n;
    cin >> T;
    memset(d, 255, sizeof(d));
    d[1] = 1;
    for(int i=1; i < N - 1; ++i) {
        int r = rev(i);
        if(d[i+1] < 0 || d[i] + 1 < d[i+1]) d[i+1] = d[i] + 1;
        if(r < N && (d[r] < 0 || d[i] + 1 < d[r])) d[r] = d[i] + 1;
    }
    for(int cas = 1; cin >> n; ++cas){
        cout << "Case #" << cas << ": " << d[n] << '\n';
        cerr << cas << endl;
    }
}
