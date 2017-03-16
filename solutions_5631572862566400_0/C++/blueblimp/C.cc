#include <algorithm>
#include <cassert>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <vector>
using namespace std;

#define FR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,n) FR(i,0,n)
#define CLR(x,a) memset(x,a,sizeof(x))
#define setmin(a,b) a = min(a,b)
#define PB push_back
#define FORALL(i,v) for(typeof((v).end())i=(v).begin();i!=(v).end();++i)
#define MP make_pair
#define A first
#define B second
#define RF(i,a,b) for(int i=(a)-1;i>=(b);--i)
#define BEND(v) (v).begin(),(v).end()
#define SZ(v) int((v).size())
#define FORI(i,v) FOR(i,SZ(v))
typedef long double ld;
typedef long long ll;

int N;
int head[1024];
int indeg[1024];
int taillen[1024];
bool mark[1024];
void doit(int cas)
{
    scanf(" %d", &N);
    assert(3 <= N && N <= 1000);

    memset(indeg, 0, sizeof(indeg));
    FOR(i,N) {
        scanf(" %d", &head[i]);
        --head[i];

        ++indeg[head[i]];
    }

    memset(taillen, 0, sizeof(taillen));
    memset(mark, 0, sizeof(mark));

    vector<int> pool;
    FOR(i,N) {
        if (indeg[i] == 0) {
            pool.push_back(i);
        }
    }

    while (pool.size()) {
        int i = pool.back();
        pool.pop_back();

        int j = head[i];

        if (1 + taillen[i] > taillen[j]) {
            taillen[j] = 1 + taillen[i];
        }

        assert(indeg[j] >= 1);
        --indeg[j];
        if (indeg[j] == 0) pool.push_back(j);
    }

    int ans = 0;
    int accum = 0;

    FOR(i,N) if (indeg[i] != 0) {
        assert(indeg[i] == 1);

        if (head[head[i]] == i) {
            // cycle of two guys
            accum += 2 + taillen[i] + taillen[head[i]];
        } else if (!mark[i]) {
            // cycle of more than two guys
            int len = 0;
            int j = i;
            while (true) {
                ++len;
                mark[j] = 1;
                j = head[j];
                if (j == i) break;
            }

            ans = max(ans, len);
        }
    }

    accum /= 2;
    ans = max(ans, accum);

    printf("Case #%d: %d\n", cas, ans);
}

int T;
int main() {
    scanf(" %d", &T);
    assert(1 <= T && T <= 100);
    FOR(cas,T) doit(cas+1);
    return 0;
}
