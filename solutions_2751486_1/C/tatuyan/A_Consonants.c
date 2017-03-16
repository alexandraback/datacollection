#include<stdio.h>
#include<string.h>

int chkvalues(char *str,int n);

int main(void){
  char str[(int)(1E+6)+1];
  int t,n,l,i,j,k,cases;
  int mae,ato,now;
  unsigned long long ans;

  scanf("%d%*c",&t);
  for(cases=1;cases<=t;cases++){
    scanf("%s %d%*c",str,&n);
    l=strlen(str);
    mae=ato=ans=0;
    now=-1;
    
    for(i=0;i<=l-n;i++){
      if(!(chkvalues(str+i,n))) continue;
      mae=i-now-1;
      now=i;
      ato=l-(now+n);
      ans+=(mae+1)*(ato+1);
    }
 
    printf("Case #%d: %llu\n",cases,ans);
  }
  return 0;
}

int chkvalues(char *str,int n){
  int i;
  for(i=0;i<n;i++){
    switch(str[i]){
    case 'a':
    case 'i':
    case 'u':
    case 'e':
    case 'o':
      return 0;
    }
  }
  return 1;
}
