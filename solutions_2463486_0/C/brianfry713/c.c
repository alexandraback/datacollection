#define DEBUG 0
#define LIMIT 10000000

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int is_palin(long long n) {
  int i, j;
  char s[102];
  sprintf(s, "%lld", n);
  for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    if(s[i] != s[j])
      return 0;
  return 1;
}

int main() {
  int tc, cn;
  long long a, b;
  vector<long long> ans;
ans.push_back(1LL);
ans.push_back(4LL);
ans.push_back(9LL);
ans.push_back(121LL);
ans.push_back(484LL);
ans.push_back(10201LL);
ans.push_back(12321LL);
ans.push_back(14641LL);
ans.push_back(40804LL);
ans.push_back(44944LL);
ans.push_back(1002001LL);
ans.push_back(1234321LL);
ans.push_back(4008004LL);
ans.push_back(100020001LL);
ans.push_back(102030201LL);
ans.push_back(104060401LL);
ans.push_back(121242121LL);
ans.push_back(123454321LL);
ans.push_back(125686521LL);
ans.push_back(400080004LL);
ans.push_back(404090404LL);
ans.push_back(10000200001LL);
ans.push_back(10221412201LL);
ans.push_back(12102420121LL);
ans.push_back(12345654321LL);
ans.push_back(40000800004LL);
ans.push_back(1000002000001LL);
ans.push_back(1002003002001LL);
ans.push_back(1004006004001LL);
ans.push_back(1020304030201LL);
ans.push_back(1022325232201LL);
ans.push_back(1024348434201LL);
ans.push_back(1210024200121LL);
ans.push_back(1212225222121LL);
ans.push_back(1214428244121LL);
ans.push_back(1232346432321LL);
ans.push_back(1234567654321LL);
ans.push_back(4000008000004LL);
ans.push_back(4004009004004LL);
/*
  for(a = 1; a <= LIMIT; a++)
    if(is_palin(a) && is_palin(a * a)) {
      if(DEBUG)
        printf("%lld\n", a * a);
      ans.push_back(a * a);
    }
*/
  scanf("%d", &tc);
  for(cn = 1; cn <= tc; cn++) {
    scanf("%lld%lld", &a, &b);
    printf("Case #%d: %d\n", cn, upper_bound(ans.begin(), ans.end(), b) - upper_bound(ans.begin(), ans.end(), a - 1));
  }

  return 0;
}
