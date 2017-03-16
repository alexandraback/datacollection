/* Michał Adamczyk, saddam */
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<map>
#include<utility>
#include<ext/numeric>
#include<tr1/unordered_map>

using namespace std;
using namespace std::tr1;
using namespace __gnu_cxx;

#define REP(i,n) for(int i=0;i<(n);++i)
#define PER(i,n) for(int i=(n)-1;i>=0;--i)
#define FORU(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define ALL(X) (X).begin(),(X).end()
#define SIZE(X) (int)(X).size()
#define VAR(V,init) __typeof(init) V=(init)
#define FOREACH(I,C) for(VAR(I,(C).begin());I!=(C).end();I++)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;

LL nwd(LL a,LL b) { return !b?a:nwd(b,a%b); }
inline int CEIL(int a,int b) { return a%b ? a/b+1 : a/b; }

const int INF = 1000000007;

LL res;
int N, M;
vector<pair<LL,LL> > nn, mm;

LL dopasuj(int b, int e, LL ile, LL typ) {
//    printf("W %d,%d szukam %lld,%lld -->", b,e,ile,typ);
    LL res = 0;
    for(int i=b; i<e; ++i)
        if(mm[i].second == typ) {
            res += min(mm[i].first, ile);
            ile -= min(mm[i].first, ile);
        }
//    printf("%lld\n", res);
    return res;
}

void solve(int caseNum) {
    res = 0;
    scanf("%d%d",&N,&M);
    nn.clear();
    mm.clear();
    LL a, b;
    REP(i,N) {
        scanf("%lld%lld",&a,&b);
        if(nn.size()>0 && nn.back().second == b)
            nn.back().first+=a;
        else
            nn.PB(MP(a,b));
    }
    REP(i,M) {
        scanf("%lld%lld",&a,&b);
        if(mm.size()>0 && mm.back().second == b)
            mm.back().first+=a;
        else
            mm.PB(MP(a,b));
    }
    N = int(nn.size());
    M = int(mm.size());
    res = 0;
//   REP(i,N) printf("(%lld,%lld) ", nn[i].first, nn[i].second); printf("\n");
//    REP(i,M) printf("(%lld,%lld) ", mm[i].first, mm[i].second); printf("\n");
    LL cur;
    if(N==1)
        res = dopasuj(0,M,nn[0].first, nn[0].second);
    else if (N==2) {
        res = 0;
        for(int i=0;i<=M;++i) {
            cur = dopasuj(0,i,nn[0].first, nn[0].second) + dopasuj(i,M,nn[1].first, nn[1].second);
            if (cur > res) res = cur;
        }
    } else {
        
        if(nn[0].second == nn[2].second) {
//            printf("sprawdzam scalenie");
            cur = dopasuj(0,M, nn[0].first+nn[2].first, nn[0].second);
            if (cur > res) res = cur;
        }

        for(int i=0;i<=M;++i)
            for(int j=i; j<=M;++j) {
                cur = dopasuj(0,i,nn[0].first, nn[0].second) 
                    + dopasuj(i,j,nn[1].first, nn[1].second)
                    + dopasuj(j,M,nn[2].first, nn[2].second);
                if(cur > res) res = cur;
            }
    }

    printf("Case #%d: %lld\n", caseNum, res);
}

int main() {
	int _T;
	scanf("%d",&_T);
	REP(i,_T) solve(i+1);
	return 0;
}

