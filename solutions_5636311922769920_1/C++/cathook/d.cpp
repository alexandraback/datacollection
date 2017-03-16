#include <stdio.h>

#include <vector>


using std::vector;


typedef long long lnt;


int main(void) {
  int num_cases;
  scanf("%d", &num_cases);

  for (int case_idx = 1; case_idx <= num_cases; ++case_idx) {
    printf("Case #%d:", case_idx);

    lnt k, c, s;
    scanf("%lld %lld %lld", &k, &c, &s);

    vector<lnt> nums;
    for (lnt i = 0; i < k; ++i) {
      nums.push_back(k - i - 1);
    }

    vector<lnt> ans;

    while (!nums.empty()) {
      lnt idx = 0;
      for (lnt cc = 0; cc < c; ++cc) {
        lnt num = 0;
        if (!nums.empty()) {
          num = nums.back();
          nums.pop_back();
        }
        idx = idx * k + num;
      }
      ans.push_back(idx + 1);
    }
    
    if ((lnt)ans.size() > s) {
      printf(" IMPOSSIBLE");
    } else {
      for (int i = 0, ii = ans.size(); i < ii; ++i) {
        printf(" %lld", ans[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
