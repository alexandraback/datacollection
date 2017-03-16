#line 2 "GuessCard.cpp"
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
#include <assert.h>
using namespace std;

#define PB push_back
#define MP make_pair

#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,l,h) for(int i=(l);i<=(h);++i)
#define FORD(i,h,l) for(int i=(h);i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).end()) i=(c).end(); i!=(c).begin(); --i)

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int A, B;
int _;
const int X[] = {1,10,100,1000,10000,100000,1000000,10000000,100000000};

LL solve()
{
    LL ans = 0;
    char s[10];
    FOR(n,A,B){
        set<int> has;
        sprintf(s, "%d", n);
        int l = strlen(s);
        REP(i,l-1){
            if(s[l-1-i] == '0') continue;
            int m = (n%X[i+1])*X[l-1-i] + n/X[i+1];
            if(n < m && m <= B && has.find(m) == has.end()){
                ans++;
                has.insert(m);
            }
        }
    }
    return ans;
}

int main()
{
    freopen("C-large.in","r",stdin); freopen("c-l.out","w",stdout);
    cin >> _;
    FOR(CAS, 1, _){
        cin >> A >> B;
        cout << "Case #" << CAS << ": " << solve() << "\n";
    }
    return 0;
}
