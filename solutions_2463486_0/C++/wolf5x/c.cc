#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<(h);++i)
#define FORD(i,h,l) for(int i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;


LL tbl[] = {
    1LL,
    4LL,
    9LL,
    121LL,
    484LL,
    10201LL,
    12321LL,
    14641LL,
    40804LL,
    44944LL,
    1002001LL,
    1234321LL,
    4008004LL,
    100020001LL,
    102030201LL,
    104060401LL,
    121242121LL,
    123454321LL,
    125686521LL,
    400080004LL,
    404090404LL,
    10000200001LL,
    10221412201LL,
    12102420121LL,
    12345654321LL,
    40000800004LL,
    1000002000001LL,
    1002003002001LL,
    1004006004001LL,
    1020304030201LL,
    1022325232201LL,
    1024348434201LL,
    1210024200121LL,
    1212225222121LL,
    1214428244121LL,
    1232346432321LL,
    1234567654321LL,
    4000008000004LL,
    4004009004004LL,
    100000020000001LL,
    100220141022001LL,
    102012040210201LL,
    102234363432201LL,
    121000242000121LL,
    121242363242121LL,
    123212464212321LL,
    123456787654321LL,
    400000080000004LL,
    10000000200000001LL,
    10002000300020001LL,
    10004000600040001LL,
    10020210401202001LL,
    10022212521222001LL,
    10024214841242001LL,
    10201020402010201LL,
    10203040504030201LL,
    10205060806050201LL,
    10221432623412201LL,
    10223454745432201LL,
    12100002420000121LL,
    12102202520220121LL,
    12104402820440121LL,
    12122232623222121LL,
    12124434743442121LL,
    12321024642012321LL,
    12323244744232321LL,
    12343456865434321LL,
    12345678987654321LL,
    40000000800000004LL,
    40004000900040004LL
};
LL tot = sizeof(tbl)/sizeof(tbl[0]);

int T;
LL A, B;

LL solve(LL x) {
    return lower_bound(tbl, tbl+tot, x+1)-tbl;
}

int main() {
    cin >> T;
    FOR(cas, 1, T+1) {
        cin >> A >> B; 
        cout << "Case #" << cas << ": " << solve(B)-solve(A-1) << endl;
    }
    return 0;
}

