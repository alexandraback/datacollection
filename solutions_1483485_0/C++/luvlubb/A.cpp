#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char A[201];
char ans[27]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
/*char B[201];
char maps[201];*/
int len;
/*
inline void findmaps()
{
 scanf("%d\n",&n);
 for(int i=1;i<=n;i++)
 {
  gets(A);
  gets(B);
  len=strlen(A);
  //printf("%s|%s\n",A,B);
  for(int j=0;j<len;j++)
  {
   if(A[j]!=' ')
   {
    //printf("%c map to %c\n",A[j],B[j]);
    maps[A[j]-'a']=B[j];
   }
  }
 }
 printf("char ans[27]={");
 for(int i=0;i<=25;i++)
 {
  printf("'%c'",maps[i]);
  if(i!=25){printf(",");}
 }
 printf("};");
}
use to find what alphabet map to what
use the data from the sample test
z = q
and one loss q is z
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities
de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up
*/
main()
{
 freopen("A-small-attempt0.in","r",stdin);
 freopen("A-small-attempt0.out","w",stdout);
 //findmaps();
 scanf("%d\n",&n);
 for(int i=1;i<=n;i++)
 {
  gets(A);
  len=strlen(A);
  printf("Case #%d: ",i);
  for(int j=0;j<len;j++)
  {
   if(A[j]!=' ')
   {
    printf("%c",ans[A[j]-'a']);
   }
   else
   {
    printf(" ");
   }
  }
  printf("\n");
 }
 return 0;
}
