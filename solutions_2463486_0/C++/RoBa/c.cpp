#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long LL;

int tmp[128];

bool check_pali(LL x) {
  int p = 0;
  while (x) {
    tmp[p++] = x % 10;
    x /= 10;
  }
  for (int i = 0 ; i < p / 2 ; ++i)
    if (tmp[i] != tmp[p-1-i]) return 0;
  return 1;
}

int main() {
  vector<LL> lt;
  for (int i = 1 ; i <= 10000000 ; ++i) {
    if (check_pali(i) && check_pali((LL)i * i))
      lt.push_back((LL)i*i);
  }
  int T;
  scanf("%d",&T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    int a, b;
    scanf("%d%d",&a,&b);
    int ans = upper_bound(lt.begin(), lt.end(), b) - 
      lower_bound(lt.begin(), lt.end(), a);
    printf("Case #%d: %d\n", ca, ans);
  }
  return 0;
}

