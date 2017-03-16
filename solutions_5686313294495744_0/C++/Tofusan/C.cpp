#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int t;
int n;
char A[2005][25];
char B[2005][25];
int iA[2005];
int iB[2005];
bool tck[2005];
bool st;
int cntA;
int cntB;
int ans;
main()
{
 freopen("C-small-attempt0.in","r",stdin);
 freopen("C-small-attempt0.out","w",stdout);
 scanf("%d",&t);
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%d\n",&n);
  //printf("n = %d\n",n);
  cntA=0;cntB=0;
  for(int i=1;i<=n;i++)
  {
   iA[i]=0;
   iB[i]=0;
  }
  for(int i=1;i<=n;i++)
  {
   scanf("%s",A[i]);
   scanf("%s",B[i]);
   for(int j=1;j<i;j++)
   {
    if(strcmp(A[i],A[j])==0){iA[i]=iA[j];break;}
   }
   for(int j=1;j<i;j++)
   {
    if(strcmp(B[i],B[j])==0){iB[i]=iB[j];break;}
   }
   if(iA[i]==0){cntA++;iA[i]=cntA;}
   if(iB[i]==0){cntB++;iB[i]=cntB;}
   //printf("%d %d\n",iA[i],iB[i]);
  }
  //printf(">> %d %d\n",cntA,cntB);
  for(int i=1;i<=cntB;i++)
  {
   tck[i]=false;
  }
  for(int i=1;i<=cntA;i++)
  {
   st=false;
   for(int j=1;j<=n;j++)
   {
    if(!st)
    {
     if(iA[j]==i)
     {
      if(tck[iB[j]]==false){cntB--;tck[iB[j]]=true;st=true;}
     }
    }
    else{break;}
   }
  }
 // printf(">>> %d %d\n",cntA,cntB);
  printf("Case #%d: %d\n",tests,n-(cntA+cntB));
 }
 
 return 0;
}
