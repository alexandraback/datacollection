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

bool valid(string &s) {
    char c = s[0];
    vector<int> f(26,0);
    int r = int(s.size());
    f[c-'a']=1;
    for (int i=1;i<r;++i) {
        if (f[s[i]-'a'] == -1) return 0;
        if (s[i]!=c) {
            f[c-'a'] = -1;
            c = s[i];
            f[c-'a'] = 1;
        }
    }
    return true;
}

int main() {
    int t; cin >> t;
    for (int cas=1; cas<=t;++cas) {
        cout << "Case #" << cas << ": ";
        int n;
        cin >> n;
        vector<pair<string,int> > v(n);
        REP(i,n) {
            cin >> v[i].x;
            char c = v[i].x[0];
            bool eq=1;
            for (int i=0;eq and i<int(v[i].x.size());++i) {
                if (v[i].x[i]!=c) eq=0;
            }
            if (eq) v[i].x=string(1,c);
            v[i].y=i;
        }
        sort(v.begin(),v.end());
        ll ans=0;
        do{
            string s = "";
            REP(i,n) s+=v[i].x;
            if (valid(s)) ++ans;
        }while(next_permutation(v.begin(),v.end()));
        cout << ans << endl;
    }
}
