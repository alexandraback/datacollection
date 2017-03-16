#include<bits/stdc++.h>
#define MAX   11111
#define FOR(i,a,b) for (int i=(a);i<=(b);i=i+1)
#define REP(i,n) for (int i=0;i<(n);i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const int mod=(int)1e9+7;
int frac[MAX];
vector<int> prev[MAX],next[MAX];
vector<int> val;
int n,m;
int bet[MAX];
int cnt[MAX];
string a[MAX];
void precount(void) {
    frac[0]=1;
    FOR(i,1,MAX-7) frac[i]=1LL*frac[i-1]*i%mod;
}
void init(void) {
    scanf("%d",&n);
    val.clear();
    REP(i,26) prev[i].clear();
    REP(i,26) next[i].clear();
    memset(bet,-1,sizeof bet);
    memset(cnt,0,sizeof cnt);
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n) FORE(it,a[i]) val.push_back(*it);
    sort(val.begin(),val.end());
    val.resize(unique(val.begin(),val.end())-val.begin());
    m=val.size();
}
void single(const string &s) {
    FORE(it,s) if (*it!=s[0]) return;
    cnt[s[0]]++;
}
bool checkcon(const string &s) {
    vector<int> pos[30];
    REP(i,s.size()) pos[s[i]].push_back(i);
    REP(i,m) sort(pos[i].begin(),pos[i].end());
    REP(i,m) if (pos[i].size()>1)
        REP(j,pos[i].size()-1) if (pos[i][j+1]-pos[i][j]!=1) return (false);
    return (true);
}
void checkbet(int id) {
    vector<int> next[30],prev[30];
    string &s=a[id];
    REP(i,s.size()-1) if (s[i]!=s[i+1]) {
        next[s[i]].push_back(s[i+1]);
        prev[s[i+1]].push_back(s[i]);
    }
    REP(i,m) if (!next[i].empty() && !prev[i].empty()) bet[i]=id;
}
bool iscircle(int x) {
    REP(zz,m+7) {
        if (next[x].empty()) return (false);
        x=next[x][0];
    }
    return (true);
}
void process(int tc) {
    FOR(i,1,n) FORE(it,a[i]) *it=lower_bound(val.begin(),val.end(),*it)-val.begin();
    printf("Case #%d: ",tc);
    FOR(i,1,n) REP(j,a[i].size()-1) if (a[i][j]!=a[i][j+1]) {
        if (!prev[a[i][j+1]].empty() || !next[a[i][j]].empty()) {
            printf("0\n");
            return;
        }
        prev[a[i][j+1]].push_back(a[i][j]);
        next[a[i][j]].push_back(a[i][j+1]);
    }
    REP(i,m) if (iscircle(i)) {
        printf("0\n");
        return;
    }
    FOR(i,1,n) single(a[i]);
    FOR(i,1,n) checkbet(i);
    FOR(i,1,n) if (!checkcon(a[i])) {
        printf("0\n");
        return;
    }
    FOR(i,1,n) FORE(it,a[i]) if (bet[*it]>0 && bet[*it]!=i) {
        printf("0\n");
        return;
    }
    REP(i,m) if (prev[i].size()>1 || next[i].size()>1) {
        printf("0\n");
        return;
    }
    int res=1;
    int tmp=0;
    REP(i,m) if (next[i].empty()) tmp++;
    res=1LL*res*frac[tmp]%mod;
    REP(i,m) res=1LL*res*frac[cnt[i]]%mod;
    assert(0<=res && res<mod);
    printf("%d\n",res);
}
int main(void) {
    precount();
    int tc;
    scanf("%d",&tc);
    REP(zz,tc) {
        init();
        process(zz+1);
    }
    return 0;
}
