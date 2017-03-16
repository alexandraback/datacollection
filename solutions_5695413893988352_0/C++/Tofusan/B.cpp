#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int t,len;
long long A[21];
long long B[21];
long long tmpA,tmpB;
long long priA[21],priB[21];
int pridig;
char aa[21];
char bb[21];
char tmp[50];
long long ansA,ansB;
long long dig[20];
long long mindiff;
long long nowA,nowB;
void solve(int pos,long long lastA,long long lastB,long long diff)
{
long long mytmp,myA,myB;
//printf("%d %I64d %I64d %I64d\n",pos,lastA,lastB,diff);
 if(pos==len)
 {
  if(diff<0){diff=-diff;}
  if(diff<mindiff)
  {
   mindiff=diff;
   ansA=nowA;
   ansB=nowB;
  }
  else if(diff==mindiff)
  {
   if(nowA<ansA)
   {
    mindiff=diff;
    ansA=nowA;
    ansB=nowB;
   }
   else if(nowA==ansA)
   {
    if(nowB<ansB)
    {
        mindiff=diff;
        ansA=nowA;
        ansB=nowB;
    }
   }
  }
 }
 else if(A[pos]!=(-1)&&B[pos]!=(-1))
 {
//  printf("C1 %d %d\n",A[pos],B[pos]);
  mytmp=A[pos]-B[pos];
  mytmp=mytmp*dig[len-pos];
  myA=A[pos]*dig[len-pos];
  myB=B[pos]*dig[len-pos];
  nowA=lastA+myA;
  nowB=lastB+myB;
  diff=diff+mytmp;
  solve(pos+1,nowA,nowB,diff);
 }
 else if(A[pos]==(-1)&&B[pos]==(-1))
 {
//  printf("C2\n");
  if(diff==0)
  {
   nowA=lastA+dig[len-pos];nowB=lastB;/*printf("C21\n");*/solve(pos+1,nowA,nowB,nowA-nowB);
   nowA=lastA;nowB=lastB+dig[len-pos];/*printf("C22\n");*/solve(pos+1,nowA,nowB,nowA-nowB);
   nowA=lastA;nowB=lastB;
  }
  else if(diff>0)
  {
   myA=0;
   myB=9*dig[len-pos];
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  else
  {
   myA=9*dig[len-pos];
   myB=0;
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  solve(pos+1,nowA,nowB,diff);
 }
 else if(A[pos]==(-1))
 {
  //printf("C3\n");
  if(diff==0)
  {
   myB=B[pos]*dig[len-pos];
   myA=myB;
   if(B[pos]!=9){nowA=lastA+myA+dig[len-pos];nowB=lastB+myB;solve(pos+1,nowA,nowB,nowA-nowB);}
   if(B[pos]!=0){nowA=lastA+myA-dig[len-pos];nowB=lastB+myB;solve(pos+1,nowA,nowB,nowA-nowB);}
   nowA=lastA+myA;nowB=lastB+myB;diff=nowA-nowB;
  }
  else if(diff>0)
  {
   myA=0;
   myB=B[pos]*dig[len-pos];
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  else
  {
   myA=9*dig[len-pos];
   myB=B[pos]*dig[len-pos];
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  solve(pos+1,nowA,nowB,diff);
 }
 else
 {
 // printf("C4\n");
   if(diff==0)
  {
   myA=A[pos]*dig[len-pos];
   myB=myA;
   if(A[pos]!=9){nowA=lastA+myA;nowB=lastB+myB+dig[len-pos];solve(pos+1,nowA,nowB,nowA-nowB);}
   if(A[pos]!=0){nowA=lastA+myA;nowB=lastB+myB-dig[len-pos];solve(pos+1,nowA,nowB,nowA-nowB);}
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  else if(diff>0)
  {
   myA=A[pos]*dig[len-pos];
   myB=9*dig[len-pos];
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  else
  {
   myB=0;
   myA=A[pos]*dig[len-pos];
   diff=diff+myA-myB;
   nowA=lastA+myA;
   nowB=lastB+myB;
  }
  solve(pos+1,nowA,nowB,diff);
 }

}
main()
{
 freopen("B-small-attempt0.in","r",stdin);
 freopen("B-small-attempt0.out","w",stdout);
 scanf("%d\n",&t);
 dig[1]=1;
 for(int i=2;i<=19;i++)
 {
  dig[i]=(long long)dig[i-1]*10;
 }
 mindiff=dig[19];
 for(int tests=1;tests<=t;tests++)
 {
  scanf("%s",aa);
  scanf("%s",bb);
  mindiff=dig[19];
  len=strlen(aa);
  for(int i=0;i<len;i++)
  {
   if(aa[i]=='?'){A[i]=(-1);}
   else{/*printf("[%c]",aa[i]);*/A[i]=aa[i]-'0';}
   if(bb[i]=='?'){B[i]=(-1);}
   else{B[i]=bb[i]-'0';}
  }
  /*for(int i=0;i<len;i++)
  {
   printf("%d|",A[i]);
  }
  printf("\n");
   for(int i=0;i<len;i++)
  {
   printf("%d|",B[i]);
  }
  printf("\n");*/
  solve(0,0,0,0);
  //printf("%d\n",mindiff);
  printf("Case #%d: ",tests);
  for(int i=len;i>=1;i--)
  {
   priA[i]=ansA%10;
   ansA=ansA/10;
   priB[i]=ansB%10;
   ansB=ansB/10;
  }
  for(int i=1;i<=len;i++)
  {
   printf("%d",priA[i]);
  }
  printf(" ");
    for(int i=1;i<=len;i++)
  {
   printf("%d",priB[i]);
  }
  printf("\n");
 }
 return 0;
}
