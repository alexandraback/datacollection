#ifdef SHTRIX 
#include "/Users/roman/Dev/SharedCpp/DebugOutput.h"
#endif
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <cstring>
#include <ctime>
#include <cstdio>
#include <memory>
using namespace std;
#define pb push_back
#define INF 1000000000
#define L(s) (int)((s).end()-(s).begin())
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define C(a) memset((a),0,sizeof(a))
#define ll long long
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define VI vector<int>
#define ppb pop_back
#define mp make_pair
#define pii pair<int,int>
#define pdd pair<double,double>
//#define x first
//#define y second
#define sqr(a) (a)*(a)
#define D(a,b) sqrt(((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y))
#define pi 3.1415926535897932384626433832795028841971
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())

void solve(int case_id) {
    int n, m, k;
    cin >> n >> m >> k;
    printf("Case #%d: ", case_id);
    // if (n <= 2 || m <= 2) {
    //     cout << k  + 1<< endl;
    //     return;
    // }
    if (n > m) swap(n, m);
    // n <= m
    int ans = INF;
    for (int sumL = 0; sumL <= n + m; sumL++)
        for (int sumR = sumL; sumR <= n + m; sumR++)
            for (int diffL = - m - 1; diffL <= m + 1; diffL++)
                for (int diffR = diffL; diffR <= m + 1; diffR++) {
                    int enc = 0, border = 0;
                    rept(x, n)
                        rept(y, m) {
                            if (x + y >= sumL && x + y <= sumR)
                                if (x - y >= diffL && x - y <= diffR) {
                                    enc++;
                                    if (x + y == sumL || 
                                        x + y == sumR ||
                                        x - y == diffL ||
                                        x - y == diffR ||
                                        x == 0 || 
                                        x == n - 1 ||
                                        y == 0 ||
                                        y == m - 1) {
                                        border++;
                                    }
                                }
                        }
                    if (enc >= k)
                        ans = min(ans, border);
                }
    cout << ans << endl;
}

int main()
{
    #ifdef SHTRIX 
    freopen("input.txt","rt",stdin); 
    //freopen("output.txt","wt",stdout); 
    #endif
	int TC;
    scanf("%d", &TC);
    rep(tc, TC) {
        solve(tc);
    }
    return 0;
}
