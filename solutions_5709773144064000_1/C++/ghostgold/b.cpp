
#include<cstdio>
#include<cstdlib>

void work();
int main()
{
  int T;
  scanf("%d", &T);
  for(int i = 1; i <=T; i++){
    printf("Case #%d: ",i);
    work();
  }
}


void work()
{
  double C,F,X;
  scanf("%lf%lf%lf", &C,&F,&X);
  int i = 0;
  for(;;i++){
    if(X/(i*F+2) < X/((i+1)*F +2) +C/(i*F+2))
      break;
  }
  double ans = X/(i*F +2);
  for(int k = 1; k <=i; k++){
    ans+=C/((k-1)*F+2);
  }
  printf("%.7lf\n", ans);
}
