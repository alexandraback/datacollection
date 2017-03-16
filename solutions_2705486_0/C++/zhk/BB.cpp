// Author: Zhang Kai (hapsunday@gmail.com)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <cassert>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <bitset>
#include <valarray>
#include <complex>
#include <numeric>
#include <iterator>
#include <functional>
#include <algorithm>
using namespace std;


#define ALL(A)		(A).begin(), (A).end()
#define CLR(A, v)	memset(A, v, sizeof(A));
#define FOR(i, N)	for(int i=0; i<(N); ++i)
#define MP(A, B)	make_pair(A, B)
#define TWO(i)		(i<32 ? 1U<<(i) : 1ULL<<(i))
#define CONTAIN(S,i)  (((S)&TWO(i)) != 0)
#define LEN(str)	((int)(str).length())
#define SIZE(v)		((int)(v).size())

#define VAR(v,t)	__typeof__(t) v=(t)
#define F0(i, n)	for(int i=0; i<(int)(n); ++i)
#define F1(i, n)	for(int i=1; i<=(int)(n); ++i)
#define F2(i, s, e)	for(int i=(int)(s); i<(int)(e); ++i)
#define FE(it, s)	for(VAR(it,(s).begin()); it!=(s).end(); ++it)

#define DEBUG_PRINT(x) fprintf(stderr, "%s:%d -->  %s = [%s]\n",        \
                               __FUNCTION__,__LINE__, #x, to_str(x).c_str());
// debug
#define debug(x)	DEBUG_PRINT(x)
#define trace(x)	fprintf(stderr, "%s:%d --> %s\n", __FUNCTION__,__LINE__, #x);


template<class T>inline int cMin(T& a, T b) {return b<a ? a=b,1 : 0;}
template<class T>inline int cMax(T& a, T b) {return a<b ? a=b,1 : 0;}
template<class T>inline string to_str(T v){ostringstream os;os<<v;return os.str();}


const double EPS=1e-8;
const double PI=acos(-1.0);

template<class T>inline T   isqr(T v) {return v*v;}
template<class T>inline T   iabs(T v) {return v<0 ? -v : v;}
template<class T>inline int isgn(T v) {return (v>EPS) - (v<-EPS);}


unsigned CH(char *str) {
    unsigned hash = 1381;int c;
    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    return hash;
}
unsigned CH(char *str, int n) {
    unsigned hash = 1381;int c=0;
    for(; c<n; ++c)
        hash = ((hash << 5) + hash) + str[c];
    return hash;
}

/////////////////////////////////////////////
const int NN = 4096;

int  M = 0;
char  gs[1<<23][12];
int   gp[1<<23];
int   gn[1<<23];
map<unsigned, int> gh;
char src[NN];
int  dp[6][NN];

bool isOK(char* s, int n) {
    unsigned c = CH(s, n);
    map<unsigned, int>::iterator it = gh.find(c);
    if(it == gh.end()) return false;
    int  idx = it->second;
    for(; idx; idx=gp[idx]) {
        if(gn[idx] == n && strncmp(gs[idx], s, n)==0)
            return true;
    }
    return false;
}

const int INF = 0x3f3f3f3f;

void go(int beg_idx, int end_idx) {
    int  L = end_idx - beg_idx + 1;
    int  pre_idx = beg_idx - 1;
    if(isOK(src+beg_idx, L)) {
        // cMin(dp[5][end_idx], dp[5][pre_idx]);
        for(int i=0; i<=5; ++i) {
            int  cur_rem = min(5, end_idx - (pre_idx-i));
            cMin(dp[cur_rem][end_idx], dp[i][pre_idx]);
        }
        return;
    }
    for(int i=beg_idx; i<=end_idx; ++i) {
        int  rem = max(0, 5-(i-pre_idx));
        if(dp[rem][pre_idx] >= INF) continue;
        char  ti = src[i];
        src[i] = '0';
        int  cur_rem = min(5, end_idx-i);
        if(isOK(src+beg_idx, L)) {
            cMin(dp[cur_rem][end_idx], dp[rem][pre_idx]+1);
            src[i] = ti;
            continue;
        }
        for(int j=i+5; j<=end_idx; ++j) {
            char tj = src[j];
            src[j] = '0';
            int t_rem = min(5, end_idx - j);
            if(isOK(src+beg_idx, L)) {
                cMin(dp[t_rem][end_idx], dp[rem][pre_idx]+2);
                src[j] = tj;
                break;
            }
            src[j] = tj;
        }
        src[i] = ti;
    }
}


int  calc() {
    memset(dp, 0x3f, sizeof(dp));
    int  N = strlen(src+1);
    for(int i=0; i<=5; ++i) dp[i][0] = 0;
    for(int i=1; i<=N; ++i) {
        for(int j=1; i-j>=0 && j<11; ++j) {
            go(i-j+1, i);
        }
        // for(int j=0; j<=5; ++j) {
            // printf("i=%d j=%d dp = %d\n", i, j, dp[j][i]);
        // }
        for(int j=4; j>=0; --j)
            cMin(dp[j][i], dp[j+1][i]);
    }
    // return dp[N];
    return dp[0][N];
}


void add(char* s) {
    unsigned c = CH(s); ++M;
    strcpy(gs[M], s); gn[M] = strlen(s);
    gp[M] = gh[c]; gh[c] = M;
}
void add_proc(char* s) {
    if(isOK(s, strlen(s))) return;
    add(s);
}

int main(int argc, char* argv[]) {
    memset(gp, 0, sizeof(gp));
    FILE* fp = fopen("dict.txt", "r");
    M = 0;
    while(fscanf(fp, "%s", src) == 1) {
        add_proc(src);
        int  k = strlen(src);
        for(int i=0; i<k; ++i) {
            char  tc = src[i];
            src[i] = '0';
            add_proc(src);
            for(int j=i+5; j<k; ++j) {
                char  tg = src[j];
                src[j] = '0';
                add_proc(src);
                src[j] = tg;
            }
            src[i] = tc;
        }
    }
    fclose(fp);
    int  num_case;
    scanf("%d", &num_case);
    for(int case_idx=1; case_idx<=num_case; ++case_idx) {
        scanf("%s", src+1);
        printf("Case #%d: %d\n", case_idx, calc());
    }
    return 0;
}
