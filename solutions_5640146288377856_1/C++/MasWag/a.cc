#include <cstdio>
#include <cstdlib>
#include <vector>

#define rep(i,n) for (int i = 0; i < n; i++)

int main(void)
{
  int T;
  scanf ("%d",&T);
  for (int t = 0;t < T;++t)
    {
      int R,C,W;
      scanf ("%d %d %d",&R,&C,&W);
      int ans = (C / W + (W - 1) + (C % W != 0)) * R;

      printf ("Case #%d: %d\n",t+1,ans);
    }
  return 0;
}
