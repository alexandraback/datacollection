#ifndef STDAFX_H
#define STDAFX_H

#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <cassert>
#include <climits>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define F first
#define S second
#define PB push_back
#define PF push front
#define MP make_pair
#define REP(x, n) for(int x=0; x<(n); ++x)
#define FOR(x, b, e) for(int x=b; x<=(e); ++x)
#define FORD(x, b, e) for(int x=b; x>=(e); --x)
#define VAR(v,n) __typeof(n) v=(n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();++i)
#define MOD(x, n) ((x)%(n)+(n))%(n)
#define SZ(x) (int((x).size()))
#define ALL(x) ((x).begin()),((x).end())
#define SORT(v) sort((v).begin(),(v).end())
#define REVERSE(v) reverse((v).begin(),(v).end())
#define UNIQUE(v) SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
LL GCD( LL a , LL b ) { while( b ) b ^= a ^= b ^= a %= b ; return a ; }
LL LCM( LL a , LL b ) { return a * ( b / GCD( a , b ) ) ; }

typedef vector<int>    VI;
typedef vector<string> VS;
typedef vector<VI>     VVI;
typedef vector<LL>     VLL;
typedef vector<bool>   VB;
typedef vector<double> VD;
typedef vector<VD>     VVD;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef vector<PII>    VPII;
typedef pair<LL, LL>   PLL;
typedef vector<PLL>    VPLL;

const double EPS = 10e-9;
const double PI = acos(-1.0);
const LL INF = (1LL << 30);

using namespace std;

template<typename T>
string toString(T t) {
    stringstream ss;
    ss << t;
    return ss.str();
}

const set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
bool is_cons(char c) {
    return vowel.find(c) == vowel.end();
}

bool is_vowel(char c ){
    return vowel.find(c) != vowel.end();
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    const int MAXN = 1000000;

    int T;
    scanf("%d", &T);
    REP(t, T) {
        char str[MAXN+1];
        scanf("%s", str);

        int n;
        scanf("%d", &n);

        VI blocks;
        int L = strlen(str), curr = 0;
        for(int i = 0; i < L; i++) {
            if(curr == n)
                blocks.push_back(i-1);
            if(is_cons(str[i])) {
                curr++;
            }
            if(i >= n && is_cons(str[i-n]))
                curr--;
        }
        if(curr == n)
            blocks.push_back(L-1);

        LL total = 0;
        for(int i = 0; i < L; i++) {
            int bl = lower_bound(ALL(blocks), i+n-1)-blocks.begin();
            if(bl < blocks.size())
                total += L-blocks[bl];
        }

        printf("Case #%d: %lld\n", (t+1), total);
    }

    return 0;
}

#endif // STDAFX_H

