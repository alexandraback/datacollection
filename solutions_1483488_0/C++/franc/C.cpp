#include <stdio.h>
#include <string.h>

int main(){
  int T, t, len, i, j, A, B, cmp;
  long long cnt;
  char cA[10], cB[10], n[10], m[10], tmp[10];
  scanf("%d", &T);
  for(t=1; t<=T; t++){
    scanf("%d%d", &A, &B);
    len=sprintf(cA, "%d", A);
    if(len==1){ printf("Case #%d: 0\n", t); continue; }
    sprintf(cB, "%d", B);
    cnt=0;
    for(i=A; i<=B; i++){
      sprintf(n, "%d", i);
      sprintf(m, "%d", i);
      do{
	for(j=0; j<len-1; j++)
	  tmp[j+1] = m[j];
	tmp[0]=m[j];
	tmp[len]='\0';
	strcpy(m, tmp);
	cmp=strcmp(n,m);
	if(cmp<0 && strcmp(m,cA)>=0 && strcmp(m,cB)<=0) cnt++;
      }while(cmp!=0);
    }
    printf("Case #%d: %Ld\n", t, cnt);
  }
  
  return 0;
}
