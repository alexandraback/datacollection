#include <bits/stdc++.h>
#define snuke(i,x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define out(x) std::cout<<(#x)<<":"<<(x)<<std::endl
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) ((int)(v).size())
template<class T> void Read(T&ret){ret=0;bool ok=0,u=0;for(;;){int c=getchar();if(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+c-'0',ok=1;else if(c=='-')u=1;else if(ok){if(u)ret*=-1;return;}}}
long long pow_mod(long long p,int n,long long mod){long long ret=1;for(;n;n>>=1){if(n&1)ret=ret*p%mod;p=p*p%mod;}return ret;}
template <class T> bool chmin(T& a, const T &b) {return b < a? a = b, 1: 0;}
template <class T> bool chmax(T& a, const T &b) {return b > a? a = b, 1: 0;}
/****head****/
namespace small1 {
        struct oo {
                int p, t;
                bool operator<(const oo&rhm) const {
                        return t < rhm.t;
                }
                void set(int P, int T) {
                        p = P; t = T;
                }
        };
        int N; 
        oo an[20];
        int solve(int n, int *p, int *m, int *tim) {
                N = 0;
                for(int i = 0; i < n; ++i) {
                        for(int j = 0; j < m[i]; ++j) {
                                an[N++].set(p[i], tim[i] + j);
                        }
                }
                std::sort(an, an + N);
                if(N == 1 || an[0].t == an[1].t) return 0;

                long long ret = 0;
                long long use = an[1].t * (360ll - an[1].p);
                long long dif = an[1].p - an[0].p;
                if(dif < 0) {
                        if(an[0].p > an[1].p) ++ret;
                        dif += 360;
                }
                if(dif * an[0].t > use) return 0;
                if(dif * an[0].t == use) return 1;
                use -= dif * an[0].t;
                long long cnt = (double)use * (an[1].t - an[0].t) / an[0].t / an[1].t / 360;
                ret += cnt;
                chmin(ret, 1ll);
                return ret;
        }
}
const int Max_N = 1005;
int _;
int p[Max_N], m[Max_N], tim[Max_N];
int main() {
        freopen("a.out","w",stdout);
        int n;
        for(scanf("%d", &_); _--; ) {
                scanf("%d", &n);
                for(int i = 0; i < n; ++i) {
                        scanf("%d%d%d", p + i, m + i, tim + i);
                }
                long long ans = small1::solve(n, p, m, tim);
                static int cas = 0;
                printf("Case #%d: %I64d\n", ++cas, ans);
        }
        return 0;
}
