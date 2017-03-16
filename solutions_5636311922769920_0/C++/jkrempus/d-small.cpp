#include <cstdio>
#include <cstdint>

int main()
{
  int ncases = 0;
  scanf("%d", &ncases);
  for(int case_ = 1; case_ <= ncases; case_++)
  {
    int k, c, s;
    scanf("%d %d %d", &k, &c, &s);
    printf("Case #%d:", case_);
    int64_t stride = 1;
    for(int i = 0; i < c - 1; i++) stride *= k;
    for(int i = 0; i < k; i++)
      printf(" %lld", 1 + i * stride);

    printf("\n");
  }
}
