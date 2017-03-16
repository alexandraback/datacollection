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
    vector<ll> min_e(N, 0);
    vector<ll> max_e(N, E);
    vector<pair<ll,int> > pv(N);
    REP(i, N) pv[i] = make_pair(v[i], i);
    sort(pv.rbegin(), pv.rend());

    ll res = 0;
    REP(i, pv.size()) {
        int id = pv[i].second;
        // max -> min
        res += pv[i].first * (max_e[id] - min_e[id]);
        for (int j = id + 1; j < N; j++) {
            max_e[j] = min(max_e[j], min_e[id] + (ll)(j-id) * R);
        }
        for (int j = 0; j < id; j++) {
            min_e[j] = max(min_e[j], max_e[id] - (ll)(id-j) * R);
        }
    }
    return res;
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
