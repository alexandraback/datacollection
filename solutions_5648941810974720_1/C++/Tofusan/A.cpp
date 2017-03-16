#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t;
char A[2005];
int cntchar[500];
int cnt[11];
int len;
void clear()
{
 for(int i='A';i<='Z';i++)
 {
  cntchar[i]=0;
 }
 for(int i=0;i<=9;i++)
 {
  cnt[i]=0;
 }
}
main()
{
 freopen("A-large.in","r",stdin);
 freopen("A-large.out","w",stdout);
 scanf("%d\n",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%s",A);
  clear();
  printf("Case #%d: ",tests);
  len=strlen(A);
  for(int i=0;i<len;i++)
  {
   cntchar[A[i]]++;
  }
  cnt[0]=cntchar['Z'];
  cnt[6]=cntchar['X'];
  cnt[8]=cntchar['G'];
  cnt[2]=cntchar['W'];
  cnt[3]=cntchar['H']-cnt[8];
  cnt[7]=cntchar['S']-cnt[6];
  cnt[5]=cntchar['V']-cnt[7];
  cnt[4]=cntchar['F']-cnt[5];
  cnt[1]=cntchar['O']-cnt[0]-cnt[2]-cnt[4];
  cnt[9]=(cntchar['N']-cnt[1]-cnt[7])/2;
  for(int i=0;i<=9;i++)
  {
   //printf("cnt %d = %d\n",i,cnt[i]);
   for(int j=1;j<=cnt[i];j++)
   {
    printf("%d",i);
   }
  }
  printf("\n");
 }
 
 return 0;
}
