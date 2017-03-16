#include<cstdio>
#include<cstring>
#include<cstdlib>
int count[2505];
int main()
{
  int T, test, N, i, j, num;
  scanf("%d",&T);
  for (test=1; test<=T; test++) {
    scanf("%d", &N);
    memset(count, 0, sizeof(int)*2501);
    for (i=0; i<2*N-1; i++) {
      for (j=0; j<N; j++) {
	scanf("%d", &num);
	count[num]++;
      }
    }
    printf("Case #%d: ", test);
    for (i=1; i<=2500; i++) {
      if (count[i]%2==1)
	printf("%d ",i);
    }
    printf("\n");
  }
  return 0;
}
