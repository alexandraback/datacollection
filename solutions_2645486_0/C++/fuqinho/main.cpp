#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <cstdio> 
#include <cstdlib> 
#include <cmath> 
#include <ctime> 
#include <cstring>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0; i<(int)(n); i++)
#define FOR(i,b,e) for(int i=(b); i<(int)(e); i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++) 
#define ALL(c) (c).begin(), (c).end()
#define EXIST(c,e) (find(ALL(c), (e)) != (c).end())
typedef long long ll;

template<class T1,class T2> ostream& operator<<(ostream& o,const pair<T1,T2>& p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T>& v){o<<"[";for(typename vector<T>::const_iterator i=v.begin();i!=v.end();++i){if (i != v.begin()) o << ", ";o<<(*i);}o<<"]";return o;}
template<class T> ostream& operator<<(ostream& o,const set<T>& s){o<<"{";for(typename set<T>::const_iterator i=s.begin();i!=s.end();++i){if(i!=s.begin())o<<", ";o<<(*i);}o<<"}";return o;}
template<class K,class V> ostream& operator<<(ostream& o,const map<K,V>& m){o<<"{";for(typename map<K,V>::const_iterator i=m.begin();i!=m.end();++i){if(i!=m.begin())o<<", ";o<<i->first<<":"<<i->second;}o<<"}";return o;}
template<class T> ostream& operator<<(ostream& o,const vector<vector<T> >& m){o<<"[\n";for(typename vector<vector<T> >::const_iterator i=m.begin();i!=m.end();++i){o<<"  "<<(*i);o<<(i+1!=m.end()?",\n":"\n");}o<<"]\n";return o;}
string bitstr(int n,int d=0){string r;for(int i=0;i<d||n>0;++i,n>>=1){r+=(n&1)?"1":"0";}reverse(r.begin(),r.end());return r;}

ll solve(int E, int R, int N, const vector<int>& v) {
    vector<vector<int> > dp(N+1, vector<int>(501, -1));
    dp[0][E] = 0;
    REP(i, N) {
        REP(j, 501) {
            if (dp[i][j] < 0) continue;
            REP(k, j+1) {
                dp[i+1][min(E,j-k+R)] = max(dp[i+1][min(E,j-k+R)],
                        dp[i][j] + v[i] * k);
            }
        }
    }
    return *max_element(dp[N].begin(), dp[N].end());
}

int main() {
    int T; cin >> T;
    REP(t, T) {
        int E, R, N; cin >> E >> R >> N;
        vector<int> v(N);
        REP(i, N) cin >> v[i];
        ll ans = solve(E, R, N, v);
        cout << "Case #" << (t+1) << ": " << ans << endl;
    }
}
