#define DEBUG 0
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
typedef vector<int> VI;
const int INF = 2000000001;
#define FOR(x,b,e) for(int x=(b);x<=(e);++x)
#define FORD(x,b,e) for(int x=(b);x>=(e);--x)
#define REP(x,n) for(int x=0;x<(n);++x)
#define ALL(c) c.begin(),c.end()
#define VAR(x,c) __typeof(c) x=(c)
#define FOREACH(x,c) for(VAR(x,(c).begin());x!=(c).end();++x)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
#define dbg(...) \
  do { if (DEBUG) fprintf(stderr, __VA_ARGS__); } while (0)

typedef pair<LL,PII> TI;
#define MT(a,b,c) MP((a),MP((b),(c)))

const int MAXN = 100;
int N, M;
PII A[MAXN+1];
PII B[MAXN+1];

LL left[MAXN+1];

LL calculate(int k1, int k2) {
  LL result = 0;
  LL tmp;
  FOR (k,0,100) { left[k] = 0; }
  
  if (k1 > 1) {
    left[A[1].ND] += A[1].ST;
    FOR (i,1,k1-1) {
      if (B[i].ND == A[1].ND) {
        tmp = min(B[i].ST, left[A[1].ND]);
        result += tmp;
        left[A[1].ND] -= tmp;
      }
    }
  }
  
  if (k2-k1 > 0) {
    if (A[2].ND != A[1].ND) { left[A[1].ND] = 0; }
    left[A[2].ND] += A[2].ST;
    FOR (i,k1,k2-1) {
      if (B[i].ND == A[2].ND) {
        tmp = min(B[i].ST, left[A[2].ND]);
        result += tmp;
        left[A[2].ND] -= tmp;
      }
    }
  }
  
  if (k2 <= M) {
    if (A[3].ND != A[2].ND) { left[A[2].ND] = 0; }
    left[A[3].ND] += A[3].ST;
    FOR (i,k2,M) {
      if (B[i].ND == A[3].ND) {
        tmp = min(B[i].ST, left[A[3].ND]);
        result += tmp;
        left[A[3].ND] -= tmp;
      }
    }
  }
  return result;
}

int main() {
  int Z;
  scanf("%d", &Z);
  for (int T = 1; T <= Z; T++) {
    scanf("%d%d", &N, &M);
    LL a, b;
    FOR (i,1,N) {
      scanf("%lld%lld", &a, &b);
      A[i] = MP(a,b);
    }
    FOR (i,1,M) {
      scanf("%lld%lld", &a, &b);
      B[i] = MP(a,b);
    }
    
    LL result = -10;
    
    if (N == 1 || (N == 2 && A[1].ND == A[2].ND)) {
      LL sum = 0;
      FOR (i,1,M) {
        if (B[i].ND == A[1].ND) { sum += B[i].ST; }
      }
      result = min(A[1].ST, sum);
    } else if (N == 2) {
      LL sum = 0;
      LL tmp1, tmp2;
      FOR (k,1,M+1) {
        tmp1 = 0;
        FOR (i,1,k-1) { if (B[i].ND == A[1].ND) { tmp1 += B[i].ST; } }
        tmp1 = min(A[1].ST, tmp1);
        
        tmp2 = 0;
        FOR (i,k,M) { if (B[i].ND == A[2].ND) { tmp2 += B[i].ST; } }
        tmp2 = min(A[2].ST, tmp2);
        
        sum = max(sum, tmp1+tmp2);
      }
    } else if (N == 3) {
      FOR (k1,1,M+1) {
        FOR (k2,k1,M+1) {
          result = max(result, calculate(k1, k2));
        }
      }
    }
    
    printf("Case #%d: %lld\n", T, result);
  }
  return 0;
}
