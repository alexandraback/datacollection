#include <cstdio>
#include <cstdint>
#include <algorithm>

int main()
{
  int ncases = 0;
  scanf("%d", &ncases);
  for(int case_ = 1; case_ <= ncases; case_++)
  {
    int64_t k, c, s;
    scanf("%lld %lld %lld", &k, &c, &s);
    printf("Case #%d:", case_);

    if(s * c < k) 
      printf(" IMPOSSIBLE");
    else
      for(int64_t i = 0; i < k; i+= c)
      {
        int64_t stride = 1;
        int64_t idx = 0;
        for(int64_t j = i; j < i + c; j++)
        {
          idx += stride * (j < k ? j : 0);
          stride *= k;
        }

        printf(" %lld", idx + 1);
      }

    printf("\n");
  }
}
