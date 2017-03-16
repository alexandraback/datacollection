#include <stdio.h>
#include <stdlib.h>
int t,n;
int chooses[501];
int sums[10];
int cnt[10];
int A[501];
bool chk;
inline void gen(int a)
{
 if(a!=n+1)
 {
  for(int i=0;i<=2;i++)
  {
   chooses[a]=i;
   cnt[chooses[a]]++;
   sums[chooses[a]]+=A[a];
   if(chk==true){return;}
   gen(a+1);
   sums[chooses[a]]-=A[a];
   cnt[chooses[a]]--;
  }
 }
 else
 {
  if(sums[1]==sums[2]&&cnt[0]!=n)
  {
   //printf("cnt %d %d\n",cnt[1],cnt[2]);
   for(int i=1;i<=n;i++)
   {
    if(chooses[i]==1)
    {
     printf("%d",A[i]);
     if(cnt[1]!=1){printf(" ");}
    }
    cnt[1]--;
   }
   printf("\n");
    for(int i=1;i<=n;i++)
   {
    if(chooses[i]==2)
    {
     printf("%d",A[i]);
     if(cnt[2]!=1){printf(" ");}
    }
    
    cnt[2]--;
   }
   printf("\n");
   chk=true;
  }
 }
}
main()
{
 freopen("C-small-attempt0.in","r",stdin);
 freopen("C-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&A[i]);
  }
  chk=false;
  printf("Case #%d:\n",tests);
  for(int j=0;j<=2;j++)
  {
   sums[j]=0;
   cnt[j]=0;
  }
  gen(1);
  if(chk==false)
  {
   printf("Impossible\n");
  }
 }
 return 0;
}
