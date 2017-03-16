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
int N; LL SUM;

LL num[30];

LL cumSUM[(1<<20)+10];

int ord[(1<<20)+10];

int bit[30];

bool visited[1000000];

int msk1[1000000], msk2[1000000];
int theSum;

bool run(int ith, int s, int msk){
    if( ith == N ) {
        if(visited[s]){
            theSum = s;
            msk2[s] = msk;
            return true;
        }
        else{
            visited[s] = true;
            msk1[s] = msk;
            return false;
        }
    }

    if( run(ith+1, s, msk) ) return true;

    return run(ith+1, s+num[ith], msk|bit[ith]);
}

void solve(){
    memset(visited, false, sizeof(visited));
    if(run(0, 0, 0)){
        FOR(i, 0, N) if( (msk1[theSum] & bit[i]) && ((msk2[theSum] & bit[i]) == 0) ) {
            cout << num[i] << " ";
        }
        cout << endl;

        FOR(i, 0, N) if( (msk2[theSum] & bit[i]) && ((msk1[theSum] & bit[i]) == 0) ) {
            cout << num[i] << " ";
        }
        cout << endl;
    }
    else
        cout << "impossible\n";
    
}

int main()
{
    freopen("z:\\output.txt", "w", stdout);
    
    freopen("z:\\input.txt", "r", stdin);
    //freopen("z:\\A-small-attempt2.in", "r", stdin);
    //freopen("z:\\A-large.in", "r", stdin);

    FOR(i, 0, 21)
        bit[i] = 1<<i;

    GET(T);
    FORV(test_case, 1, T+1)
    {
        GET(N); SUM = 0;
        FOR(i, 0, N) {
            GET(num[i]);
            SUM += num[i];
        }

        cout << "Case #" << test_case << ":\n";
        solve();
    }

    return 0;
}





