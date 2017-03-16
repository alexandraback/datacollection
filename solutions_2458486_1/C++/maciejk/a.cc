
#include<algorithm>
#include<cassert>
#include<complex>
#include<map>
#include<iomanip>
#include<sstream>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<cstdio>
#define FOR(i, a, b) for(int i =(a); i <=(b); ++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define fup FOR
#define fdo FORD
#define REP(i, n) for(int i = 0;i <(n); ++i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define siz SZ
#define CLR(x) memset((x), 0, sizeof(x))
#define PB push_back
#define MP make_pair
#define X first
#define Y second 
#define FI X
#define SE Y
#define SQR(a) ((a)*(a))
#define DEBUG 0
#define debug(x) {if (DEBUG)cerr <<#x <<" = " <<x <<endl; }
#define debugv(x) {if (DEBUG) {cerr <<#x <<" = "; FORE(it, (x)) cerr <<*it <<", "; cout <<endl; }}
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int>P;
typedef vector<int>VI;
const int INF=1E9+7;
template<class C> void mini(C&a4, C b4){a4=min(a4, b4); }
template<class C> void maxi(C&a4, C b4){a4=max(a4, b4); }

#define maxn 405
int type[maxn];
VI G[maxn * 2];
VI keys[maxn];
int k, n;
int ile[maxn];
bool opened[maxn];
int pap[maxn];
bool done[maxn];
int st[maxn], ile2[maxn];
bool open2[maxn];
bool done3[maxn];


void dfs(int act, int kto, int len) {
    if (DEBUG) cout << "DFS " << act << " " << kto << " " << len << endl;
    if (len > 0) {
        done[act] = 1;
        pap[act] = kto; 
    }

    FORE(it, G[act]) {
        //cout << "TRY " << *it << endl;
        if (!open2[*it] && !done[*it]) dfs(*it, kto, len + 1);
    }
}

bool check_win() {
    fup(i, 1, n) open2[i] = opened[i];
    fup(i, 1, 200) ile2[i] = ile[i];
    if (DEBUG) cout << "CHECK " << endl;
    int iter = 0;
    fup(i, 1, n) if (!open2[i]) iter++;
    if (DEBUG) {
    fup(i, 1, n) {
        cout << i << " " << type[i] << " -> ";
        FORE(it, keys[i]) cout << *it << " " ;
        cout << endl;
    }
    }
    while(iter--) { 
        if (DEBUG) {
            cout << "ILE" << endl;
        fup(i, 1,5) cout << i << " " << ile2[i] << endl;
        cout << "OPENED" << endl;
        fup(i, 1, n) cout << i << " " << open2[i] << endl;
        }

        CLR(pap);
        CLR(done);
        CLR(st);
        fup(i, 1, n) if (!open2[i] && ile2[type[i]] > 0 && !done[i]) {
            if (DEBUG) cout << "GO " << i << endl;
            dfs(i, i, 0);
        }
        int to_open = -1;

        fup(i, 1, n) if (!open2[i] && ile2[type[i]] > 0) {
            if (pap[i] == 0) { 
               if (DEBUG)  cout << "TAK " << i << endl;
                to_open = i; break; } 
            else st[pap[i]]++;
        }

        if (to_open == -1) {
            queue<int> Q;
            int any = -1;
            CLR(done3);
            fup(i, 1, n) if (!open2[i] && ile2[type[i]] > 0) {
                if (DEBUG) cout << "ED " << pap[i] << " "<< i << " " << st[i] << endl;
                any = i;
                if (st[i] == 0) Q.push(i);
            }
            if (any == -1) return 0;
            while (!Q.empty()) {
                int act = Q.front();
                done3[act] = 1;
                Q.pop();
                st[pap[act]]--;
                assert(st[pap[act]] >= 0); 
                if (st[pap[act]] == 0) Q.push(pap[act]);
            }
            fup(i, 1, n) {
                if (!open2[i] && ile2[type[i]] > 0 && !done3[i]) to_open = i;
            }
        }
        if (DEBUG) cout << "OPEN " << to_open << endl;
        assert(to_open != -1);
        open2[to_open] = 1;
        FORE(it, keys[to_open]) ile2[*it]++;
        ile2[type[to_open]]--;
    }
    fup(i, 1, n) assert(open2[i]); 
    return true;
}

bool dp[(1 << 20)];
int il[maxn];
bool brut() {
    CLR(dp);
    CLR(il);
    dp[0] = 1;
    fup(mask, 0, (1 << n) - 2) {
        if (dp[mask]) {
            CLR(il);  
            fup(i, 1, 200) il[i] = ile[i];
            fup(i, 1, n) if (mask & (1 << (i - 1))) {
                il[type[i]]--;
                FORE(it, keys[i]) il[*it]++;
            }
            fup(j, 1, n) if (!(mask &(1 << (j - 1)))  &&  il[type[j]]) {
                dp[mask | (1 << (j - 1))] = 1;
            }
        }
    }
    return dp[(1 << n) - 1];
}

void solve(int cas) {
    printf("Case #%d: ", cas);
    cin >> k >> n;
    CLR(ile);
    CLR(opened);
    CLR(open2);


    fup(i, 1, k) { int key; cin >> key; ile[key]++; }
    fup(i, 0, maxn * 2 - 1) G[i].clear();
    fup(i, 0, maxn -1) keys[i].clear();

    fup(i, 1, n) {
        cin >> type[i];
        int b; cin >> b;
        fup(j, 1, b) {
            int key; cin >> key;
            keys[i].PB(key);
            G[i].PB(n + key);
        }
    }

    fup(i, 1, n) G[type[i] + n].PB(i);

    VI res;
    fup(i, 1, n) {
        if (DEBUG) {
        cout << endl;
        cout << "ILE00 " << endl;
        fup(j, 1, 3) cout << j << " " << ile[j] << endl;
        }
        bool ok = 0;
        fup(j, 1, n) if (!opened[j] && ile[type[j]] > 0) {
            opened[j] = 1;
            ile[type[j]]--;
            FORE(it, keys[j]) ile[*it]++;
            if (check_win()) { 
               if (DEBUG)  cout << "OPEN " << j << endl;
                ok = 1; res.PB(j); break; 
            }
            FORE(it, keys[j]) ile[*it]--;
            ile[type[j]]++;
            opened[j] = 0;
        }
        if (!ok) break;
    }
    if (siz(res) < n) cout << "IMPOSSIBLE" << endl;
    else {
        FORE(it, res) cout << *it << " " ;
        cout << endl;
    }

}


int main(){
    int cas;
    cin >> cas;
    fup(i, 1, cas) solve(i);

    return 0;
}

