#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <set>
#include <algorithm>
#include <functional>
#include <numeric>
#include <iterator>
#include <time.h>
#include <memory>
using namespace std;

typedef long long LL;
typedef long long uLL;
typedef unsigned int uint;
#define FOR(i, b, e) for(int i=(b); i<int(e); ++i)
#define dFOR(i, b, e) for(int i=(b); i>int(e); --i)
#define FORV(i, b, e) for(i=(b); i<(e); ++i)
#define dFORV(i, b, e) for(i=(b); i>int(e); --i)
#define GET(a) cin >> a
#define GET2(a, b) cin >> a >> b
#define GET3(a, b, c) cin >> a >> b >> c
#define GET4(a, b, c, d) cin >> a >> b >> c >> d
#define MAX(a, b) ((a) < (b) ? (b) : (a))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define PB(a) push_back(a)
#define SIZE(a) a.size()
#define PEEK(a) cout << " >> " #a " = " << a << endl
#define peek(a) _peek(#a, a)
template <typename T> void _peek(char name[], T &obj, size_t max_count=50){
    const size_t ipl = 10;
    cout << " >> " << name << " = ["; size_t _count = 0;
    for(typename T::iterator it=obj.begin(); it!=obj.end(); ++it){
        if(_count && _count%ipl == 0) cout << "      [";
        cout << *it; ++_count;
        if(_count%ipl == 0 || _count >= max_count || it == obj.end()-1) cout << " ]\n";
        else cout << ", ";
        if(_count >= max_count) break;
    }
}
template <typename T> ostream &operator << (ostream &cout, pair<T, T> &x){
    cout << "(" << x.first << "," << x.second << ")";
    return cout;
}
template <typename T> inline T GCD(T a, T b){
    if(b==0) return a;
    a %= b; while(a){ swap(a, b); a %= b; }; return b;
}
template <typename T> inline T LCM(T a, T b){
    if(a == 0 || b == 0) return -1;
    a /= GCD(a, b); T lcm = a * b;
    if(lcm < 0 || lcm/a != b ) return -1;
    return lcm;
}
//===========================================================
int T, test_case;
int N, M;
LL a[110], A[110];
LL b[110], B[110];
void read(){
    GET2(N, M);
    LL last=-1; int k=0;
    FOR(i, 0, N){
        LL ta, tA; 
        GET2(ta, tA);
        if(tA != last){
            a[k] = ta; A[k] = tA; ++k;
            last = tA;
        }
        else
            a[k-1]+=ta;
    }
    N = k;

    last = -1; k=0;
    FOR(i, 0, M){
        LL tb, tB;
        GET2(tb, tB);
        if(tB != last){
            b[k] = tb; B[k] = tB; ++k;
            last = tB;
        }
        else
            b[k-1]+=tb;
    }
    M = k;
}

LL dp[110][110]; // dp[x][y] using last x from A, last y from B

void runDP(){
    memset(dp, 0, sizeof(dp));

    FOR(ath, 1, N+1){
        FOR(bth, 1, M+1){
            //printf("a:%d b:%d\n", ath, bth);
            LL matches = dp[ath-1][bth]; // drop A directly
            LL cnt = 0;
            FOR(k, 1, bth+1){   //match first k from B
                if(B[M-bth+k-1] == A[N-ath]) cnt += b[M-bth+k-1];
                //printf("k:%d, cnt:%d\n", k, cnt);
                matches = max(matches, min(cnt, a[N-ath]) + dp[ath-1][bth-k]);
            }
            dp[ath][bth] = matches;
        }
    }
}

void solve(){
    runDP();
    LL ans = dp[N][M];
    if(N == 3 && A[0] == A[2]){
        a[0] += a[2]; N = 1;
        runDP();
        ans = max(ans, dp[N][M]);
    }

    /*
    FOR(ath, 0, N+1) {
        FOR(bth, 0, M+1)
            printf("[a:%d][b:%d]=%lld ", ath, bth, dp[ath][bth]);
        cout << endl;
    }*/

    cout << ans << endl;
}

int main()
{
    freopen("z:\\output.txt", "w", stdout);

    freopen("z:\\input.txt", "r", stdin);
    //freopen("z:\\C-small-attempt0.in", "r", stdin);
    //freopen("z:\\C-large.in", "r", stdin);


    GET(T);
    FORV(test_case, 1, T+1)
    {
	    //scanf("% % % % %", &, &, &, &, &);
        read();
        cout << "Case #" << test_case << ": ";
        solve();
    }

    return 0;
}

