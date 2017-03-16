#include <stdio.h>

int main()
{
  int ncases = 0;
  scanf("%d", &ncases);
  for(int case_ = 1; case_ <= ncases; case_++)
  {
    int first = 0;
    scanf("%d", &first);
    if(first == 0)
      printf("Case #%d: INSOMNIA\n", case_);
    else
    {
      int numbers_mask = 0;
      int multiple = first;
      while(true)
      {
        for(int a = multiple; a; a /= 10) numbers_mask |= (1 << (a % 10));
        if(numbers_mask == 0x3ff) break;
        multiple += first;
      }

      printf("Case #%d: %d\n", case_, multiple);
    }
  }

  return 0;
}
