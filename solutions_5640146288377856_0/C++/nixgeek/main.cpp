#include<cstdio>

using namespace std;

int main()
{
  int T;
  scanf("%d", &T);
  for(int i=0;i<T;i++){
    int R, C, W;
    scanf("%d%d%d", &R, &C, &W);
    int res = C/W + -1 + ((C%W)?1:0) +W;
    printf("Case #%d: %d\n", i+1, res);
  }
}
