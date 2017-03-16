/* Written by Filip Hlasek 2013 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

vector<long long> v;

bool is_palindrom(long long p) {
  int L = 0, a[22];
  while(p) { a[L++] = p % 10; p /= 10; }
  REP(i, L) if(a[i] != a[L-i-1]) return false;
  return true;
}

long long create_palindrom(long long n) {
  long long ans = n;
  while(n) { ans = 10 * ans + n % 10; n /= 10; }
  return ans;
}

long long create_middle_palindrom(long long n) {
  long long ans = n;
  n /= 10;
  while(n) { ans = 10 * ans + n % 10; n /= 10; }
  return ans;
}

int main(int argc, char *argv[]){
  REP(i, 10000) {
    long long p = create_middle_palindrom(i);
    p *= p;
    if(is_palindrom(p)) v.push_back(p);
    p = create_palindrom(i);
    p *= p;
    if (p > 100000000000000LL) continue;
    if(is_palindrom(p)) v.push_back(p);
  }
//  printf("palindromes: %d\n", (int)v.size());
  sort(v.begin(), v.end());
//  REP(i, v.size()) printf("%lld %lf\n", v[i], sqrt(v[i]));
  int T;
  scanf("%d", &T);
  REP(t, T) {
    printf("Case #%d: ", t + 1);
    long long A, B;
    scanf("%lld%lld", &A, &B);
    int ans = 0;
    REP(i, v.size()) ans += (A <= v[i] && v[i] <= B);
    printf("%d\n", ans);
  }
  return 0;
}
