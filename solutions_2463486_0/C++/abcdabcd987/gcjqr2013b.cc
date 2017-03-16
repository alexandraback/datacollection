#include <cstdio>
#include <algorithm>

const int psize = 39;
const long long pal[psize] = {1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL, 4008004LL, 100020001LL, 102030201LL, 104060401LL, 121242121LL, 123454321LL, 125686521LL, 400080004LL, 404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL};

int T;
long long L, R;
int main()
{
  scanf("%d", &T);
  for (int testcase = 1; testcase <= T; ++testcase)
  {
    scanf("%lld%lld", &L, &R);
    const int lef = std::lower_bound(pal, pal+psize, L) - pal;
    const int rig = std::upper_bound(pal, pal+psize, R) - pal - 1;
    printf("Case #%d: %d\n", testcase, std::max(0, rig-lef+1));
  }
}
