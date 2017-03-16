#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
  int T;
  scanf("%d",&T);
  printf("Case #1:\n");
  int R,m,n,k;
  scanf("%d%d%d%d",&R,&n,&m,&k);
  while(R--){
    int A[12];
    for(int i=0;i<k;i++){
      scanf("%d",A+i);
    }
    int P2=0,P3=0,P5=0;
    for(int i=0;i<k;i++){
      int p=A[i];
      int p2=0,p3=0,p5=0;
      while(p%2==0){
	p2++;
	p/=2;
      }
      while(p%3==0){
	p3++;
	p/=3;
      }
      while(p%5==0){
	p5++;
	p/=5;
      }
      P2=max(P2,p2);
      P3=max(P3,p3);
      P5=max(P5,p5);
    }
    int I=3-P3-P5;
    if(I==3){
      if(P2<=3){
	printf("222");
      }
      else if(P2==4){
	printf("224");
      }
      else if(P2==5){
	printf("244");
      }
      else{
	printf("444");
      }
    }
    else if(I==2){
      if(P2<=2){
	printf("22");
      }
      else if(P2==3){
	printf("24");
      }
      else{
	printf("44");
      }
    }
    else if(I==1){
      if(P2<=1){
	printf("2");
      }
      else{
	printf("4");
      }
    }
    if(P3==3){
      printf("333");
    }
    else if(P3==2){
      printf("33");
    }
    else if(P3==1){
      printf("3");
    }
    if(P5==3){
      printf("555");
    }
    else if(P5==2){
      printf("55");
    }
    else if(P5==1){
      printf("5");
    }
    putchar('\n');
  }
  return 0;
}
