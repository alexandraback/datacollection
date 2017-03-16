#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define x first
#define y second
#define PB push_back
#define REP(i,n) for (int i = 0; i < int(n); ++i)
#define FORE(i,a,b) for (int i = int(a); i <= int(b); ++i)
#define debug(x) cerr << #x << " = " << x << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
typedef vector<bool> Vb;
typedef vector<Vb> Mb;
typedef vector<char> Vc;
typedef vector<Vc> Mc;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
typedef vector<ll> Vll;
typedef vector<Vll> Mll;
typedef vector<P> Vp;
typedef vector<Vp> Mp;
typedef vector<string> Vs;
typedef vector<Vs> Ms;

typedef queue<int> Q;
typedef priority_queue<int> PQ;

template <class Ta, class Tb> inline Tb cast(Ta a) {stringstream ss; ss << a; Tb b; ss >> b; return b; };

const double EPS = 1e-9;
const ll INF = 1000000000000000000LL;
const int diri[8] = { -1, 0, 1, 0, -1, 1, 1, -1 };
const int dirj[8] = { 0, 1, 0, -1, 1, 1, -1, -1 };

ll gcd(ll a, ll b) {
    if (b==0) return a;
    return gcd(b,a%b);
}

void simp(ll& a, ll& b) {
    ll g = gcd(a,b);
    a/=g;
    b/=g;
    //if (a==0) b=1;
}

int main() {
    int t; cin >> t;
    for (int cas=1; cas<=t;++cas) {
        cout << "Case #" << cas << ": ";
        char z;
        ll a, b; cin >> a >> z >> b;
        simp(a,b);
        
        ll pt=1;
        ll e = 1;
        while(pt<b) {
            pt*=2;
            ++e;
        }
        //cerr << " # " << a << " " << b << endl;
        if (pt!=b) cout << "impossible" << endl;
        else {
            if (a*2 >= b) cout << 1 << endl; //numerator is bigger than half, can have 1/1 parent
            else {
                ll ret=1;
                while(a*2 < b) {
                    a*=2;
                    ++ret;
                }
                cout << ret << endl;
            }
        }
    }
}
