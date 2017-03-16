#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define SMALL
//#define LARGE

int T, a, b, c, k;
int nums[11][11][11];
vector <pair <int, pair <int, int> > > ans;

int main()
{
#ifdef SMALL
  freopen("C-small.in", "r", stdin);
  freopen("C-small.out", "w", stdout);
#endif
#ifdef LARGE
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
#endif

  scanf("%d", &T);
  for (int Case = 1; Case <= T; ++Case) {
    scanf("%d %d %d %d", &a, &b, &c, &k);
    memset(nums, 0, sizeof(nums));
    ans.clear();
    for (int x = 1; x <= a; ++x) {
      for (int y = 1; y <= b; ++y) {
        for (int z = 1; z <= c; ++z) {
          if (nums[x][y][z] == 1)
            continue;
          if (nums[x][y][0] == k || nums[x][0][z] == k || nums[0][y][z] == k)
            continue;
          ans.push_back(make_pair(x, make_pair(y, z)));
          ++nums[x][y][z];
          ++nums[x][y][0], ++nums[x][0][z], ++nums[0][y][z];
        }
      }
    }
    printf("Case #%d: %d\n", Case, (int)ans.size());
    for (int i = 0; i < ans.size(); ++i)
      printf("%d %d %d\n", ans[i].first, ans[i].second.first, ans[i].second.second);
  }
  return 0;
}
