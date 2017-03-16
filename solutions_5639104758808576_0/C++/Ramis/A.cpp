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
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/A-small-attempt0.in.txt","rt",stdin);
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
#define EPS 1E-3
#define N 2000001
/* --------- END TEMPLATE CODE --------- */

int n;

void smain() {
    int T;
    cin >> T;

    string s;
    for(int t = 1; cin >> n >> s; ++t){
        int res = 0;
        int sum = 0;
        forn(i, n + 1){
            int k = s[i] - '0';
            if(sum < i) res += i - sum, sum = i;
            sum += k;
        }
        cout << "Case #" << t << ": " << res << '\n';
    }
}
