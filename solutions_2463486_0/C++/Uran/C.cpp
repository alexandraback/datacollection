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


inline bool ispalindrom(ll x) {
    ll y = x;
    ll z = 0;
    while (y) {
        z = z * 10;
        z += y % 10;
        y /= 10;
    }
    return z == x;
}

ll d[] = {
1LL
, 4LL
, 9LL
, 121LL
, 484LL
, 10201LL
, 12321LL
, 14641LL
, 40804LL
, 44944LL
, 1002001LL
, 1234321LL
, 4008004LL
, 100020001LL
, 102030201LL
, 104060401LL
, 121242121LL
, 123454321LL
, 125686521LL
, 400080004LL
, 404090404LL
, 10000200001LL
, 10221412201LL
, 12102420121LL
, 12345654321LL
, 40000800004LL
, 1000002000001LL
, 1002003002001LL
, 1004006004001LL
, 1020304030201LL
, 1022325232201LL
, 1024348434201LL
, 1210024200121LL
, 1212225222121LL
, 1214428244121LL
, 1232346432321LL
, 1234567654321LL
, 4000008000004LL
, 4004009004004LL
, 100000020000001LL
, 100220141022001LL
, 102012040210201LL
, 102234363432201LL
, 121000242000121LL
, 121242363242121LL
, 123212464212321LL
, 123456787654321LL
, 400000080000004LL
, 10000000200000001LL
, 10002000300020001LL
, 10004000600040001LL
, 10020210401202001LL
, 10022212521222001LL
, 10024214841242001LL
, 10201020402010201LL
, 10203040504030201LL
, 10205060806050201LL
, 10221432623412201LL
, 10223454745432201LL
, 12100002420000121LL
, 12102202520220121LL
, 12104402820440121LL
, 12122232623222121LL
, 12124434743442121LL
, 12321024642012321LL
, 12323244744232321LL
, 12343456865434321LL
, 12345678987654321LL
, 40000000800000004LL
, 40004000900040004LL
, 1000000002000000001LL
, 1000220014100220001LL
, 1002003004003002001LL
, 1002223236323222001LL
, 1020100204020010201LL
, 1020322416142230201LL
, 1022123226223212201LL
, 1022345658565432201LL
, 1210000024200000121LL
, 1210242036302420121LL
, 1212203226223022121LL
, 1212445458545442121LL
, 1232100246420012321LL
, 1232344458544432321LL
, 1234323468643234321LL
, 4000000008000000004LL, 
-1
};

void solve(int case_id) {
    int L, R; 
    cin >> L >> R;
    int i = 0, res = 0;
    while (d[i] >= 0) {
        if (L <= d[i] && d[i] <= R) res++;
        i++;
    }
    printf("Case #%d: %d\n", case_id, res);
}


int main()
{
    // cout << "ll d[] = {";
    // rep(i, 2000000002) {
    //     if (!ispalindrom(i)) continue;
    //     if (!ispalindrom((ll)i * i)) continue;
    //     cout << ", " << (ll)i * i << "LL" << endl;
    // }
    // cout << "}";
    // return 0;
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
