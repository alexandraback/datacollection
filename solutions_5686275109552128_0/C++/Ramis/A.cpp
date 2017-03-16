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
    freopen("/Users/ramis/Downloads/B-small-attempt1.in.txt","rt",stdin);
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
#define N 1001
/* --------- END TEMPLATE CODE --------- */

int n;
int a[N];

int solve(){
    int res = a[0];
    forn(i, a[0]) {
        vector<int> cnt(a[0] + 1, 0);
        forn(j, n) cnt[a[j]] += 1;
        int pos = a[0];
        forn(j, i) {
            for(; pos >= 0 && cnt[pos] == 0; --pos);
            cnt[pos/2] += 1;
            cnt[(pos+1)/2] += 1;
            cnt[pos] -= 1;
        }
        pos = a[0];
        for(; pos >= 0 && cnt[pos] == 0; --pos);
        res = min(res, i + pos);
    }
    return res;
}

int solve_naive(){
    int mm = (a[0] + a[0]);
    int res = a[0];
    multiset<int, greater<int> > b, tb;
    forn(mask, mm){
        b.clear();
        forn(i, n) b.insert(a[i]);
        int steps = 0;
        for(int t = mask; b.size() > 0; t >>= 1){
            if(t & 1){
                auto it = b.begin();
                int x = *it;
                b.erase(it);
                if(x > 1) b.insert(x/2), b.insert((x+1)/2);
            }else{
                tb.clear();
                for(auto j : b){
                    if(j > 1) tb.insert(j - 1);
                }
                b.clear();
                for(auto j : tb) b.insert(j);
            }
            steps += 1;
        }
        res = min(res, steps);
    }
    return res;
}

void smain() {
    int T;
    cin >> T;

    for(int t = 1; cin >> n; ++t){
        forn(i, n) cin >> a[i];
        sort(a, a + n, greater<int>());
        assert(solve() == solve_naive());
        cout << "Case #" << t << ": " << solve() << '\n';
    }
}
