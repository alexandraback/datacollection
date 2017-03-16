#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#include <vector>
#include <utility>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename T>inline string to_str(const T& v) {
    ostringstream os; os << v; return os.str();
}
template<typename T>inline T to_obj(const string& v) {
    istringstream is(v); T r; is>>r; return r;
}
template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}

#define CLR(A,v) memset(A, v, sizeof(A))
#define MP(a,b)  make_pair(a, b)
#define F0(i, n) for(int i=0; i<(n); ++i)
#define F1(i, n) for(int i=1; i<=(n); ++i)


typedef long long i64;
const int NN = 26;
const int MOD = 1000000007;
int N;
char src[128][10240], srcS[128], srcE[128];;
i64  G[32][32];
int srcTo[32], srcFrom[32];
i64  extra = 0;
i64 fact(i64 n) {
    if ( n < 0) return 0;
    if (n < 2) return 1;
    i64 ret = 1;
    for(i64 i=2; i<=n; ++i)
        ret = (ret * i) % MOD;
    return ret;
}

void initG() {
    i64 tG[32][32] = {0};
    extra = 1;
    F0(i, 26) srcFrom[i] = srcTo[i] = -1;
    F0(i, N) {
        int u = src[i][0] - 'a';
        int v = src[i][strlen(src[i]) - 1] - 'a';
        if(u != v) {
            if(srcTo[u] >= 0) {extra = 0; return;}
            srcTo[u] = v;
            if(srcFrom[v] >= 0) {extra = 0; return;}
            srcFrom[v] = u;
        }
        srcS[i] = u;
        srcE[i] = v;
        tG[u][v]++;
    }
    F0(i, 26) {
        if (tG[i][i] == 0) continue;
        tG[i][i] = fact(tG[i][i]);
        if (srcTo[i] >= 0) {
            tG[i][srcTo[i]] *= tG[i][i];
            tG[i][srcTo[i]] %= MOD;
            tG[i][i] = 0;
        }
        else if(srcFrom[i] >= 0) {
            tG[srcFrom[i]][i] *= tG[i][i];
            tG[srcFrom[i]][i] %= MOD;
            tG[i][i] = 0;
        }
        else {
            // extra = (extra * tG[i][i]) % MOD;
            // tG[i][i] = 0;
        }
    }
    bool flag = true;
    while(flag) {
        flag = false;
        F0(i, 26) F0(j, 26) if(i!=j && tG[i][j] == 0) {
            F0(k, 26) if(i!=k && j!=k && tG[i][k]>0 && tG[k][j]>0) {
                tG[i][j] = (tG[i][k] * tG[k][j]) % MOD;
                tG[i][k] = 0;
                tG[k][j] = 0;
                flag = true;
                break;
            }
            F0(k, 26) if(i!=k && j!=k && tG[i][k]>0 && tG[k][j]>0) {
                extra = 0;
                return;
            }
        }
    }
    F0(i, 26) F0(j, 26) G[i][j] = tG[i][j];
}

bool contain(char c, int idx) {
    F0(i, N) {
        if(i == idx) continue;
        char* s = src[i];
        for(int j=0; s[j]; ++j)
            if(s[j] == c)
                return true;
    }
    return false;
}

bool valid(char* s) {
    set<char> hash;
    for(int i=1; s[i]; ++i) {
        char c = s[i];
        if(c != s[i-1]) {
            if(hash.count(c)) return false;
            hash.insert(c);
        }
    }
    return true;
}

bool check() {
    int C[32][32] = {0};
    F0(g, N) {
        char* s = src[g];
        if(!valid(s)) return false;
        int L = strlen(s);
        C[s[0]-'a'][s[L-1]-'a']++;
        int ss = 0;
        while(ss<L && s[ss]==s[0]) ++ss;
        int ee = L-1;
        while(ee>=0 && s[ee]==s[L-1]) --ee;
        for(int i=ss; i<=ee; ++i) {
            if(contain(s[i], g))
                return false;
        }
    }
    F0(i, 26) F0(j, 26) {
        if(i!=j && C[i][j] > 1) return false;
        if(i!=j && C[i][j] && C[j][i])
            return false;
    }
    int  IN[32] = {0};
    int  OUT[32] = {0};
    F0(i, 26) F0(j, 26) {
        if(i != j && C[i][j]) {
            IN[j]++;
            OUT[i]++;
        }
    }
    F0(i, 26) {
        if(IN[i] > 1 || OUT[i] > 1)
            return false;
    }
    return true;
}

i64 calc() {
    scanf("%d", &N);
    F0(i, N) scanf("%s", src[i]);
    if(!check())
        return 0;
    memset(G, 0, sizeof(G));
    initG();
    int  nn = 0;
    i64  ret = 1;
    set<int>  hash;
    F0(i, 26) F0(j, 26) {
        if(i!=j && G[i][j] && G[j][i])
            ret = 0;
        if(G[i][j] > 0) {
            if(hash.count(i) || hash.count(j))
                ret = 0;
            // printf("%c -- > %c\n", 'a'+i, 'a'+j);
            ret = (ret * G[i][j]) % MOD;
            ++nn;
            hash.insert(i);
            hash.insert(j);
        }
    }
    return (extra * ret * fact(nn)) % MOD;
}


int main(int argc, char *argv[]) {
    int T;
    scanf("%d", &T);
    F1(iT, T) {
        long long ret = calc();
        printf("Case #%d: %lld\n", iT, ret);
    }
    return 0;
}
