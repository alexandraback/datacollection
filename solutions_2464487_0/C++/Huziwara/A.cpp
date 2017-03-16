#include <cstdio>
#include <cmath>

int main()
{
  int T;
  scanf("%d",&T);
  for(int C=1;C<=T;C++){
    unsigned long long R,t;
    scanf("%llu%llu!",&R,&t);
    unsigned long long l=0,r=(int)sqrt((double)t)+2;
    while(l+1<r){
      unsigned long long m=(l+r)/2;
      if((2*R+1)+(2*(R+2*(m-1))+1)<=2*t/m){
	l=m;
      }
      else{
	r=m;
      }
    }
    printf("Case #%d: %llu\n",C,l);
  }
  return 0;
}
