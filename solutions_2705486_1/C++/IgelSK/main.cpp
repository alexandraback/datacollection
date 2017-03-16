#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <numeric>
#include <complex>
#include <string>
#include <ctime>
#include <unordered_set>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pnt;


#define FI(i,a) for (int i=0; i<(a); ++i)
#define FOR(i,s,e) for (LL i=(s); i<(e); ++i)
#define MEMS(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define ALL(a) a.begin(),a.end()
#define V(t) vector < t >
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):(-(a)))
#define ALL(a) a.begin(),a.end()

#define dout(a) cerr << a << endl
#define sout(a) cerr << a << "  "

const double pi = 3.14159265358979323846264338327950288419716939937511;
const double eps = 1e-9;

//*
char ch_ch_ch[1<<20];
inline string gs() {scanf("%s",ch_ch_ch); return string(ch_ch_ch);}
inline string gl() {gets(ch_ch_ch); return string(ch_ch_ch);}
inline int gi() {int x; scanf("%d",&x); return x;}
//*/

//const int inf = 1000000000;

// code starts here


V(string) str;
string s;

vector <unordered_set <ULL> > hashes2;
vector <unordered_set <ULL> > hashes;

V(ULL) pw;

inline ULL ghash(string &s, int pos, int lgth) {
    ULL res = 0;
    FOR(i,pos,pos+lgth) {
        int cur = s[i] - 'a' + 1;
        res = res + cur * pw[i-pos];
    }
    return res;
}

const int mod = 1000000103;
inline ULL ghash2(string &s, int pos, int lgth) {
    ULL res = 0;
    FOR(i,pos,pos+lgth) {
        int cur = s[i] - 'a' + 1;
        res = (res + cur * pw[i-pos]) % mod;
    }
    return res;
}


V(V(int)) dp;

const int inf = 1000000000;

int R(int pos, int predist) {
    if (pos == s.size()) return 0;
    int &r = dp[pos][predist];
    if (r!=-1) return r;

    ULL curhash[10];
    FI(i,10) curhash[i] = 0;
    ULL curhash2[10];
    FI(i,10) curhash2[i] = 0;
    r = inf;
    int start = 5 - predist;

    // raw
    for (int di = 0; di < 10 && pos + di < s.size(); ++di) {
        curhash[di] = pw[di] * (s[pos + di] - 'a' + 1) + (di>0?curhash[di-1]:0);
        curhash2[di] = (pw[di] * (s[pos + di] - 'a' + 1) + (di>0?curhash[di-1]:0)) % mod;
        if (hashes[di].count(curhash[di]) && hashes2[di].count(curhash2[di]))
            r = min(r, R(pos + di + 1,min(5,predist+di+1)));
    }

    // 1 sym
    for (int di = start; di < 10 && pos + di < s.size(); ++di) {
        char old = s[pos + di];
        for (char c = 'a'; c <= 'z'; ++ c) if (c!=old) {
            for (int ind = di; ind < 10 && pos + ind < s.size(); ++ind) {
                ULL h = curhash[ind];
                h -= pw[di] * (old - 'a' + 1);
                h += pw[di] * (c - 'a' + 1);
                ULL h2 = curhash2[ind];
                h2 -= (pw[di] * (old - 'a' + 1))%mod;
                h2 += pw[di] * (c - 'a' + 1);
                h2 = (h2 + mod)%mod;
                if (hashes[ind].count(h) && hashes2[ind].count(h2))
                    r = min(r, 1 + R(pos + ind + 1, min(5,ind - di + 1)));
            }
        }
    }

    // 2 sym
    for (int di = start; di < 10 && pos + di < s.size(); ++di)
        for (int dj = di+5; dj < 10 && pos + dj < s.size(); ++dj) {
            char oldi = s[pos + di];
            char oldj = s[pos + dj];
            for (char ci = 'a'; ci <= 'z'; ++ci) if (ci != oldi)
                for (char cj = 'a'; cj <= 'z'; ++cj) if (cj != oldj) {
                    for (int ind = dj; ind < 10 && pos + ind < s.size(); ++ind) {
                        ULL h = curhash[ind];
                        h -= pw[di] * (oldi - 'a' + 1);
                        h -= pw[dj] * (oldj - 'a' + 1);
                        h += pw[di] * (ci - 'a' + 1);
                        h += pw[dj] * (cj - 'a' + 1);
                        ULL h2 = curhash[ind];
                        h2 -= (pw[di] * (oldi - 'a' + 1))%mod;
                        h2 -= (pw[dj] * (oldj - 'a' + 1))%mod;
                        h2 += pw[di] * (ci - 'a' + 1);
                        h2 += pw[dj] * (cj - 'a' + 1);
                        h2 = (h2 + mod + mod)%mod;
                        if (hashes[ind].count(h) && hashes2[ind].count(h2))
                            r = min(r, 2 + R(pos + ind + 1, min(5, ind - dj + 1)));
                    }
                }
        }


    return r;

}

char sss[100];

void solution() {
    FILE* dict = fopen("dict.txt","r");
    FI(it,521196) {fscanf(dict,"%s",sss); str.pb(string(sss)); }
    fclose(dict);
    hashes.resize(10);
    hashes2.resize(10);

    pw.resize(20);
    pw[0] = 1;
    FOR(i,1,20) pw[i] = pw[i-1] * 31;
    FI(i,str.size()) hashes[str[i].size()-1].insert(ghash(str[i],0,str[i].size()));
    FI(i,str.size()) hashes2[str[i].size()-1].insert(ghash2(str[i],0,str[i].size()));

    int tn = gi();

    FI(it,tn) {
        cin >> s;
        dp.clear();
        dp.resize(s.size()+1,V(int)(6,-1));
        printf("Case #%d: ",it + 1);
        printf("%d\n",R(0,5));


    }

}



// code endds here

int main(int argc, char** argv) {

#ifdef IGEL_ACM
    freopen("in.txt","r",stdin);
    freopen("out.txt", "w", stdout);
    clock_t beg_time = clock();
#else
    //freopen(argv[1],"r",stdin);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

#endif

    solution();

#ifdef IGEL_ACM
    fprintf(stderr,"*** Time: %.3lf ***\n",1.0*(clock()-beg_time)/CLOCKS_PER_SEC);
#endif

    return 0;
}
















