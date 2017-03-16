#include<stdio.h>
#include<string.h>

int main(void){
  int cases,t,i,x,y;
  char str[3];
  scanf("%d",&t);
  for(cases=1;cases<=t;cases++){
    scanf("%d%d",&x,&y);
    printf("Case #%d: ",cases);

    if(x<0){
      strcpy(str,"EW");
      x*=-1;
    }else{
      strcpy(str,"WE");
    }
    for(i=0;i<x;i++) printf("%s",str);

    if(y<0){
      strcpy(str,"NS");
      y*=-1;
    }else{
      strcpy(str,"SN");
    }
    for(i=0;i<y;i++) printf("%s",str);
    putchar('\n');
  }
  return 0;
}
