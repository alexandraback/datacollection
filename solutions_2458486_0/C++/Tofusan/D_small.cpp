#include <stdio.h>
#include <stdlib.h>
int t,n,k;
bool fin;
int pred[2000000];
int lasts[2000000];
bool cols[2000000];
int keys[201];
bool states[25];
int mul[25];
int A[41];
int op[41];
int cnt[41];
int nums[41][41];
int ans[41];
int rr;
void init()
{
 mul[0]=1;
 for(int i=1;i<=25;i++)
 {
  mul[i]=mul[i-1]*2;
 }
}
void ret()
{
 for(int i=1;i<=200;i++)
 {
  keys[i]=0;
 }
 for(int i=0;i<=mul[n];i++)
 {
  pred[i]=0;
  lasts[i]=0;
  cols[i]=0;
 }
 for(int i=0;i<=n;i++)
 {
  states[i]=0;
 }
}
void dfs(int a)
{
/*if(rr==2)
{printf("this state %d : ",a);
for(int i=1;i<=n;i++)
{
 printf("%d ",states[i]);
}
printf("\n");
}*/
 for(int i=1;i<=n;i++)
 {
  if(keys[op[i]]>0&&states[i]==false)
  {
   if(cols[a+mul[i-1]]==false)
   {
    cols[a+mul[i-1]]=true;
    states[i]=true;
    keys[op[i]]--;
    pred[a+mul[i-1]]=a;
    lasts[a+mul[i-1]]=i;
    for(int j=1;j<=cnt[i];j++)
    {
     keys[nums[i][j]]++;
    }
  /*  if(rr==2)
{printf("go %d\n",a+mul[i-1]);}*/
    dfs(a+mul[i-1]);
   /* if(rr==2)
{printf("back %d\n",a);}*/
       for(int j=1;j<=cnt[i];j++)
    {
     keys[nums[i][j]]--;
    }
    keys[op[i]]++;
    states[i]=false;
   }
  }
 }
}
void solve()
{
int tmp;
int nn;
 dfs(0);
 tmp=mul[n]-1;
 if(cols[tmp]!=0)
 {
  nn=n;
  while(tmp!=0)
  {
  // printf("states %d last %d pred %d\n",tmp,lasts[tmp],pred[tmp]);
   ans[nn]=lasts[tmp];
   tmp=pred[tmp];
   nn--;
  }
  for(int i=1;i<=n;i++)
  {
   printf("%d",ans[i]);
   if(i!=n){printf(" ");}
   else{printf("\n");}
  }
 }
 else
 {
 printf("IMPOSSIBLE\n");
 }
}
main()
{
 freopen("D-small-attempt1.in","r",stdin);
 freopen("D-small.out","w",stdout);
 scanf("%d",&t);
 init();
 for(int tests=1;tests<=t;tests++)
 {
  rr=tests;
  scanf("%d%d",&k,&n);
  ret();
  for(int i=1;i<=k;i++)
  {
   scanf("%d",&A[i]);
   keys[A[i]]++;
  }
  for(int i=1;i<=n;i++)
  {
   scanf("%d",&op[i]);
   scanf("%d",&cnt[i]);
   for(int j=1;j<=cnt[i];j++)
   {
    scanf("%d",&nums[i][j]);
   }
  }
   printf("Case #%d: ",tests);
  solve();
 }
 return 0;
}
