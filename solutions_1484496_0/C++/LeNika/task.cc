#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

int n;
vector<int> nums;

int getsum(int mask)
{
  int sum = 0;
  for (int i = 0; i < n; ++i)
    if (mask & (1 << i))
      sum += nums[i];
  return sum;
}

void printmsk(int mask)
{
  for (int i = 0; i < n; ++i)
    if (mask & (1 << i))
      printf("%d ", nums[i]);
  printf("\n");
}

void solve()
{
  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; ++i) cin >> nums[i];
  int max_mask = 1 << n;
  map<int, int> mp;

  for (int mask = 0; mask < max_mask; ++mask) {    
    int sum =  getsum(mask);
    map<int, int>::iterator it = mp.find(sum);
    if (it == mp.end()) {
      mp.insert(make_pair(sum, mask));
    } else {
      printmsk(mask);
      printmsk(it->second);
      return;
    }
  }
  printf("Impossible\n");
}

int main()
{
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    printf("Case #%d:\n", t + 1);
    solve();
  }
  return 0;
}
