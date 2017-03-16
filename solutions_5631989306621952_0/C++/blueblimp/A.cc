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
char S[1024];
int posmax[1024];
bool used[1024];
void doit(int cas)
{
    scanf(" %s", S);
    N = strlen(S);
    assert(1 <= N && N <= 1000);

    posmax[0] = 0;
    FOR(i,N-1) {
        posmax[i+1] = posmax[i];

        if (S[i+1] >= S[posmax[i+1]]) posmax[i+1] = i+1;
    }

    string ans;
    memset(used, 0, sizeof(used));
    int i = posmax[N-1];
    while (true) {
        ans.push_back(S[i]);
        used[i] = true;

        if (i == 0) break;
        i = posmax[i-1];
    }

    FOR(i,N) {
        if (!used[i]) ans.push_back(S[i]);
    }

    assert(ans.size() == N);

    printf("Case #%d: %s\n", cas, ans.c_str());
}

int T;
int main() {
    scanf(" %d", &T);
    assert(1 <= T && T <= 100);
    FOR(cas,T) doit(cas+1);
    return 0;
}
