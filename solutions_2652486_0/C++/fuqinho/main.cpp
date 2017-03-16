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
#define mp make_pair
#define dump(x) cerr << #x << " = " << (x) << endl;

template<class T1,class T2> ostream& operator<<(ostream& o,const pair<T1,T2>& p){return o<<"("<<p.first<<","<<p.second<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T>& v){o<<"[";for(typename vector<T>::const_iterator i=v.begin();i!=v.end();++i){if (i != v.begin()) o << ", ";o<<(*i);}o<<"]";return o;}
template<class T> ostream& operator<<(ostream& o,const set<T>& s){o<<"{";for(typename set<T>::const_iterator i=s.begin();i!=s.end();++i){if(i!=s.begin())o<<", ";o<<(*i);}o<<"}";return o;}
template<class K,class V> ostream& operator<<(ostream& o,const map<K,V>& m){o<<"{";for(typename map<K,V>::const_iterator i=m.begin();i!=m.end();++i){if(i!=m.begin())o<<", ";o<<i->first<<":"<<i->second;}o<<"}";return o;}
template<class T> ostream& operator<<(ostream& o,const vector<vector<T> >& m){o<<"[\n";for(typename vector<vector<T> >::const_iterator i=m.begin();i!=m.end();++i){o<<"  "<<(*i);o<<(i+1!=m.end()?",\n":"\n");}o<<"]\n";return o;}
string bitstr(int n,int d=0){string r;for(int i=0;i<d||n>0;++i,n>>=1){r+=(n&1)?"1":"0";}reverse(r.begin(),r.end());return r;}


bool check(vector<int>& v, vector<int>& p) {
    int N = v.size();
    set<int> cands;
    REP(s, 1<<N) {
        int prod = 1;
        REP(i, N) if (s & (1<<i)) prod *= v[i];
        cands.insert(prod);
    }
    REP(i, p.size())
        if (cands.find(p[i]) == cands.end()) return false;
    return true;
}

void bt(int cur, int N, int M, int K, vector<int>& v, vector<int>& p, vector<int>& ans) {
    if (cur == N) {
        if (check(v, p)) {
            ans = v;
        }
        return;
    }
    for (int i = 2; i <= M; i++) {
        v.push_back(i);
        bt(cur+1, N, M, K, v, p, ans);
        v.pop_back();
    }
}

vector<int> solve(int N, int M, int K, vector<int>& p) {
    /*
    dump(N);
    dump(M);
    dump(K);
    dump(p);
    */
    vector<int> v;
    vector<int> ans;
    bt(0, N, M, K, v, p, ans);
    if (ans.size() != N) {
        ans = vector<int>(N, 2);
    }
    return ans;
}

int main() {
    int T; cin >> T;
    REP(t, T) {
        int R, N, M, K; cin >> R >> N >> M >> K;
        cout << "Case #" << (t+1) << ":" << endl;
        REP(i, R) {
            vector<int> p(K);
            REP(j, K) cin >> p[j];
            vector<int> ans = solve(N, M, K, p);
            REP(j, ans.size()) cout << ans[j];
            cout << endl;
        }
    }
}
