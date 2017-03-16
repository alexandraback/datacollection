#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOREACH(i, c) for(__typeof( (c).begin() ) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for(__typeof(n) i = (a); i<(n); ++i)
#define REP(i, a, n) for(__typeof(n) i = (a); i<=(n); ++i)
#define ROF(i, n, a) for(__typeof(n) i = (n); i>=(a); --i)
#define error(n) cout << #n << " = " << n << endl
#define all(c) c.begin(), c.end()
#define pb push_back
#define po pop_back
#define Size(n) ((int)(n).size())
#define X first
#define Y second
#define scanf _ = scanf
// #define X real()
// #define Y imag()

typedef long long   ll ;
typedef long double ld ;
typedef pair<int,int> pii ;

int T;
int n;
int num[30][4]; // ...ccc... , cc... , ...ccc , ccc
int pos[30][4];
string s[111];
int indeg[111];
int nxt[111];

void Add(string s , int id) {
    int l = Size(s);
    for (int i = 0 ; i < l ; ) {
        int j = i;
        while(j < l && s[i] == s[j])
            ++j;
        int ch = s[i]-'a';
        int x = (i==0)+(2*(j==l));
        num[ch][x]++;
        pos[ch][x] = id;
        //
        i = j;
    }
}

const ll mod = 1000 * 1000 * 1000 +7;

ll Mul(ll a , ll b) {
    return (a%mod)*(b%mod)%mod;
}

ll fact[111];

bool Cycle(int a) {
    int cur = a;
    for (int i = 0 ; i < 111 ; ++i) {
        if (cur == -1)
            break;
        if (nxt[cur] == a)
            return true;
        else
            cur = nxt[cur];
    }
    return false;
}

int main() {
    fact[0] = 1;
    FOR (i,1,111)
        fact[i] = Mul(fact[i-1],i);
    cin >> T;
    REP (lv,1,T) {
        memset (num,0,sizeof(num));
        memset (pos,0,sizeof(pos));
        memset (indeg,0,sizeof(indeg));
        memset (nxt,-1,sizeof(nxt));
        cin >> n;
        FOR (i,0,n) {
            cin >> s[i];
            Add(s[i],i);
        }
        //
        ll ans = 1;
        int component = 0;        
        FOR (i,0,30) {
            if (num[i][0] > 1 || num[i][1] > 1 ||  num[i][2] > 1)
                ans = 0;
            if (num[i][0] > 0 && num[i][1]+num[i][2]+num[i][3] > 0)
                ans = 0;
            if (num[i][2] > 0 && num[i][1] > 0) {
                nxt[pos[i][2]] = pos[i][1];
                indeg[pos[i][1]]++;
            }
            if (num[i][1]+num[i][2] == 0 && num[i][3] > 0)
                ++component;
            ans = Mul(ans,fact[num[i][3]]);
        }
        //
        FOR (i,0,n) {
            if (indeg[i] > 1 || Cycle(i))
                ans = 0;
            else if (indeg[i] == 0) {
                if (s[i] != string(Size(s[i]),s[i][0]))
                    component++;
            }
        }
        ans = Mul(ans,fact[component]);
        cout << "Case #" << lv << ": "<< ans << endl;
    }
    return 0 ;
}
