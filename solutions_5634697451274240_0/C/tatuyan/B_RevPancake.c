#include<stdio.h>
#include<string.h>

int solve(void);

int main(void){
  int t,i;
  scanf("%d%*c",&t);
  for(i=1;i<=t;i++)
    printf("Case #%d: %d\n",i,solve());
  return 0;
}

int solve(void){
  char input[128]="",now='+';
  int num=0;
  int i,j,k=0,l;

  scanf("%s%*c",input);
  
  l=strlen(input);
  for(k=0;input[k]=='+';k++);
  while(k!=l){
    if(k!=0){
      num++;
      for(i=0;i<k;i++) input[i]='-';
    }
    num++;
    for(i=0;input[i]=='-';i++) input[i]='+';
    for(k=0;input[k]=='+';k++);
  }
  return num;
}

