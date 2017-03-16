#include <string>
#include <cstring>
#include <vector>
#include <cmath> 
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iostream>
 
using namespace std;
 
#define REP(a,n) for(int a=0; a<(n); ++a)
#define FOR(a,b,c) for(int a=(b); a<=(c); ++a)
#define INIT(a, v) __typeof(v) a = (v)
#define FOREACH(a, v) for (INIT(a, (v).begin()); a!=(v).end(); ++a)
 
template<class T>
inline int size(const T&t){return t.size();}
 
typedef vector<string> vs;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long LL;

#define INF 1000000000
#define PB push_back
#define MP make_pair
 
//////////////////////////////////////////

vector<vi> sas;
int N, Nl;
vi byl;
vector<vi> match;

void usun(vi &vec, int val) {
    REP(a, size(vec))
        if (vec[a] == val) {
            vec[a] = vec.back();
            vec.pop_back();
            return;
        }
    assert(0);
}

bool dfs(int w) {
    if (byl[w]) 
	return false;
    byl[w] = 1;
    FOREACH(it, sas[w]) {
        int w2 = *it;
        if (byl[w2])
            continue;
        byl[w2] = 1;
	if (size(sas[w2]) > 1) {
	    usun(sas[w2], w);
	    usun(sas[w], w2);
	    match[w2].PB(w);
            match[w].PB(w2);
            return true;
	}
	FOREACH(it2, match[w2]) {
	    int w3 = *it2;
	    if (dfs(w3)) {
	        usun(match[w3], w2);
	        usun(match[w2], w3);
	        sas[w2].PB(w3);
	        sas[w3].PB(w2);
	        usun(sas[w2], w);
	        usun(sas[w], w2);
	        match[w2].PB(w);
	        match[w].PB(w2);
	        return true;
	    }
        }
    }
    return false;
}

void licz() {
    map<string, int> sl1, sl2;
    int K;
    scanf("%d", &K);
    vector<pii> kraw;
    REP(a, K) {
        char buf1[30], buf2[30];
        scanf("%s%s", buf1, buf2);
        if (!sl1[buf1])
            sl1[buf1] = size(sl1);
        if (!sl2[buf2])
            sl2[buf2] = size(sl2);
        kraw.PB(MP(sl1[buf1] - 1, sl2[buf2] - 1));
    }
    Nl = size(sl1);
    N = Nl + size(sl2);
    sas.clear();
    sas.resize(N);
    FOREACH(it, kraw) {
        sas[it->first].PB(it->second + Nl);
        sas[it->second + Nl].PB(it->first);
    }
    match.clear();
    match.resize(N);
    int ile = 0;
    REP(a, Nl) {
        int x = size(sas[a]) - 1;
        REP(b, x) {
            byl.clear();
            byl.resize(N);
            if (dfs(a))
                ++ile;
        }
    }
    printf("%d\n", ile);
}


int main() {
    int TT;
    scanf("%d", &TT);
    REP(tt, TT) {
        printf("Case #%d: ", (tt+1));
        licz();
    }
}


