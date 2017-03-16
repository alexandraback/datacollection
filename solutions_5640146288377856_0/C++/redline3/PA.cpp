#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

int tt;
int r, c, w;
int cnt;

int main(void)
{
  int i, j;
  scanf("%d", &tt);
  for(int tc=1; tc<=tt; ++tc){
    scanf("%d%d%d", &r, &c, &w);
    cnt = r * (c/w);
    if(c%w == 0){
      cnt += w-1;
    }else{
      cnt += w;
    }
    printf("Case #%d: %d\n", tc, cnt);
  }
  return 0;
}
