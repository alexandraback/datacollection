#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t;
char A[105];
int len;
int seg;
main()
{
 freopen("B-small-attempt0.in","r",stdin);
 freopen("B-small-attempt0.out","w",stdout);
 scanf("%d\n",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%s",A);
  len=strlen(A);
  seg=1;
  for(int i=0;i<len-1;i++)
  {
   if(A[i]!=A[i+1]){seg++;}
  }
  printf("Case #%d: ",tests);
  if(A[len-1]=='+'){printf("%d\n",seg-1);}
  else{printf("%d\n",seg);}
 }
 
 return 0;
}
