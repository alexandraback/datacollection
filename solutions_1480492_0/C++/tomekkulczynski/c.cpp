
//Tomasz Kulczyński
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <numeric>
#include <cmath>
#include <cstdlib>
using namespace std;

#define X first
#define Y second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }

ld brut(VI c, VI v, VI p, int n) {
    vector<ld> tt;
    REP(i, n) REP(j, n) if(v[i] > v[j]) {
        if(p[i] + 5 < p[j])
            tt.PB((p[j] - p[i] - 5.l) / (v[i] - v[j]));
        if(p[i] < p[j] + 5)
            tt.PB((p[j] + 5.l - p[i]) / (v[i] - v[j]));
    }
    sort(ALL(tt));
    tt.PB(tt.back() + 1);
    vector<ld> tmp;
    tmp.PB(0.);
    FORE(it, tt) if(*it > tmp.back() + 1e-12l) tmp.PB(*it);
    swap(tmp, tt);
    set<int> st;
    {
        VI cc(n);
        int m = 0, zm = 0;
        REP(i, n) if(c[i]) m += 1<<i;
        REP(i, n) REP(j, i) if(p[i] > p[j] - 5 && p[j] > p[i] - 5)
            cc[i] = cc[j] = 1;
        REP(i, n) if(!cc[i]) zm += 1<<i;
        for(int z = zm; ; z = (z-1) & zm) {
            st.insert(m ^ z);
            if(!z) break;
        }
    }
    REP(cz, SIZE(tt)-1) {
        ld e = (tt[cz] + tt[cz+1]) / 2;
        vector<ld> q(n);
        vector<int> cc(n);
        REP(i, n) q[i] = p[i] + v[i] * e;
    //       printf("%.3lf :: \n",(D)tt[cz]);
        REP(i, n) REP(j, i) if(q[i] > q[j] - 5 && q[j] > q[i] - 5) {
   //         printf("%d %d\n",j,i);
            cc[i] = cc[j] = 1;
        }
        int zm = 0;
        REP(i, n) if(!cc[i]) zm += 1<<i;
        set<int> nst;
        FORE(it, st) {
            int mask = *it, ok = 1;
            REP(i, n) REP(j, i) 
                if(q[i] > q[j] - 5 && q[j] > q[i] - 5 
                        && (mask >> i) % 2 == (mask >> j) % 2)
                    ok = 0;
            if(!ok) continue;
            for(int z = zm; ; z = (z-1) & zm) {
                nst.insert(mask ^ z);
                if(!z) break;
            }
        }
        swap(st, nst);
        if(st.empty())
            return tt[cz];
    }
    return -1;
}

int main()
{
    int tt;
    scanf("%d",&tt);
    FOR(cas, 1, tt) {
        int n;
        scanf("%d",&n);
        VI v(n), p(n), c(n);
        REP(i, n) {
            char buf[13];
            scanf("%s %d %d",buf, &v[i], &p[i]);
            if(buf[0] == 'R')
                c[i] = 1;
        }
        printf("Case #%d: ",cas);
        double res = brut(c, v, p, n);
        if(res < 0)
            puts("Possible");
        else
            printf("%.6lf\n", res);
    }
    return 0;
}
