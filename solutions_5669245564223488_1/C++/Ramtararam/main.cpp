#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#define _USE_MATH_DEFINES
#include <math.h>
#include <assert.h>
#include <cstdlib>
#include <algorithm>
#include <list>

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
#define mp(a,b) make_pair(a,b)
#define LL long long
#define S(n) scanf("%d", &n)
#define Sa(n,i) scanf("%d", n+i)
#define N 100001
#define MOD 1000000007

using namespace std;
bool used[26];
LL fact[120];

bool is_ok(const string &s){
    memset(used, 0, sizeof(bool) * 26);
    char cur = s[0];
    for(int i = 1, m = s.length(); i < m; ++i){
        used[cur - 'a'] = true;
        if(s[i] != cur){
            cur = s[i];
            if(used[cur - 'a']) return false;
        }
    }
    return true;
}

set<char> inner(const string &s){
    char cur = s[0];
    int i = 1, m = s.length(), j = m - 1;
    for(; i < m && s[i] == cur; ++i);
    for(cur = s[j]; j >= i && s[j] == cur; --j);
    set<char> res;
    for(; i <= j; ++i) res.insert(s[i]);
    return res;
}

LL solve(int n, vector<string> d){
    bool ok = true;
    forn(i, n) if(!is_ok(d[i])) ok = false;
    for(int i=0; ok && i<n; ++i) {
        set<char> vals = inner(d[i]);
        for(int j=i+1; ok && j<n; ++j){
            if(d[i][0] != d[i][d[i].size() - 1] && d[j][0] != d[j][d[j].size() - 1] && (
               d[i][0] == d[j][0] || d[i][d[i].size() - 1] == d[j][d[j].size() - 1] ||
               (d[i][0] == d[j][d[j].size() - 1] && d[j][0] == d[i][d[i].size() - 1])
               )) ok = false;
            for(int k=0; k<d[j].length(); ++k) if(vals.count(d[j][k])) ok = false;
        }
    }
    if(!ok) return 0;
    
    vector< pair<int, LL> > next(n, mp(-1, 1));
    vector<int> prev(n, -1);
    vector<int> singles(26);
    vector< vector< pair<string, int> > > doubles(26);
    forn(i, n){
        if(d[i][0] == d[i][d[i].length() - 1]) singles[d[i][0] - 'a'] += 1, prev[i] = -2;
        else doubles[d[i][0] - 'a'].push_back(mp(d[i], i));
    }
    
    forn(k, 26){
        fori(it, doubles[k]){
            string cur = it->first;
            int end = cur[cur.size() - 1] - 'a';
            size_t cnt = doubles[end].size();
            if(cnt > 1) ok = false;
            if(cnt == 1){
                next[it->second] = mp(doubles[end][0].second, fact[singles[end]]);
                singles[end] = 0;
                prev[doubles[end][0].second] = it->second;
            } else if(cnt == 0 && singles[end]){
                next[it->second] = mp(-2, fact[singles[end]]);
                singles[end] = 0;
            }
        }
    }
    
    vector<LL> chains;
    for(int i=0; i<n; ++i){
        if(prev[i] == -1){
            LL r = fact[singles[d[i][0] - 'a']];
            singles[d[i][0] - 'a'] = 0;
            for(int v=i; v != -1; ){ r = r * next[v].second % MOD; v=next[v].first; if(v == -2) break;}
            chains.push_back(r);
        }
    }
    
    LL cnt = chains.size();
    for(int i=0; i<26; ++i) if(singles[i]) cnt += 1;
    
    LL res = fact[cnt];
    fori(it, chains) res = res * *it % MOD;
    for(int i=0; i<26; ++i) res = res * fact[singles[i]] % MOD;
    
    if(!ok) res = 0;
    return res;
}


LL solve_small(int n, vector<string> d){
    vector<int> perm(n);
    forn(i, n) perm[i] = i;
    LL res = 0;
    do{
        memset(used, 0, sizeof(bool) * 26);
        int k = 0;
        char cur = d[perm[k]][0];
        bool ok = true;
        for(; ok && k < n; ++k){
            string &s = d[perm[k]];
            for(int i = 0, m = s.length(); i < m; ++i){
                used[cur - 'a'] = true;
                if(s[i] != cur){
                    cur = s[i];
                    if(used[cur - 'a']){ ok = false; break; }
                }
            }
        }
        if(ok) res += 1;
    }while(next_permutation(perm.begin(), perm.end()));
    return res;
}


int main(){
#ifndef ONLINE_JUDGE
    //freopen("input.txt","rt",stdin);
    freopen("/Users/ramis/Downloads/B-large.in","rt",stdin);
    freopen("output.txt","wt",stdout);
#endif
    
    fact[0] = fact[1] = 1;
    for(int i=2; i < 120; ++i) fact[i] = fact[i - 1] * i % MOD;
    
    
    int T;
    S(T);
    forn(_t, T){
        int n;
        cin >> n;
        vector<string> d(n);
        forn(i, n) cin >> d[i];
        LL r2 = solve(n, d);
        LL r1 = n < 7 ? solve_small(n, d) : r2;
        assert(r1 == r2);
        if(r1 != r2){
            printf("Found Error at test #%d, expected %lld, found %lld\n", _t + 1, r1, r2);
            return 0;
        }
        printf("Case #%d: %lld\n", _t + 1, r1);
    }
    
    
    
    return 0;
}

