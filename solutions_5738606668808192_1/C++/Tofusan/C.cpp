#include <stdio.h>
#include <stdlib.h>

int t,len,n;
//int lcd;
int cnt;
int prime[1000001];
int ans[50];
int ans2[50];
int lim;
/*
int gcd(int a,int b)
{
 if(b==0){return a;}
 else{return gcd(b,a%b);}
}
void getlcd(int a)
{
int g;
int mul;
lcd=2;
 for(int i=3;i<=a;i++)
 {
  g=gcd(i,lcd);
  mul=lcd*i;
  lcd=mul/g;
  printf("lcd %d : %d\n",i,lcd);
 }
}*/
void genprime(int a)
{
bool isprime;
 prime[1]=2;
 cnt=1;
 for(int i=3;i<=a;i++)
 {
  isprime=true;
  for(int j=1;j<=cnt&&prime[j]*prime[j]<=i;j++)
  {
   if(i%prime[j]==0){isprime=false;break;}
  }
  if(isprime==true){cnt++;prime[cnt]=i;}
 }
 //printf("%d : %d\n",cnt,prime[cnt]);
}
bool chk(int bases)
{
int dig;
int tdig;
int tr;
int remainders;
 for(int i=1;i<=cnt;i++)
 {
  remainders=1;
  dig=1;
  tdig=1;
  tr=1;
  for(int j=1;j<len;j++)
  {
   dig=dig*bases;
   dig=dig%prime[i];
   if(tdig>lim){tr=(-1);}
   else{tdig=tdig*bases;if(ans[j]==1){tr+=tdig;}}
   if(ans[j]==1){remainders+=dig;remainders=remainders%prime[i];}
  // printf("%d : dig = %d, remainders = %d\n",j,dig,remainders);
  }
  //if(i<=1){printf("remainders from %d = %d\n",prime[i],remainders);}
  if(remainders==0&&(tr!=prime[i])){/*printf("%d : %d\n",bases,tr);*/ans2[bases]=prime[i];return false;}
 }
 //printf("chk base %d = prime\n",bases);
 return true;
//return true if prime
}
void solve()
{
printf("Case #%d:\n",1);
 while(n>0)
 {
   /*for(int i=len-1;i>=0;i--)
    {
     printf("%d",ans[i]);
    }
    printf("|\n");*/
  for(int i=2;i<=10;i++)
  {
   if(chk(i)){break;}
   else if(i==10)
   {
    for(int i=len-1;i>=0;i--)
    {
     printf("%d",ans[i]);
    }
    printf(" ");
    for(int i=2;i<=10;i++)
    {
     printf("%d",ans2[i]);
     if(i!=10){printf(" ");}
     else{printf("\n");}
    }
    n--;
   }
  }
  for(int i=1;i<len;i++)
  {
   if(ans[i]==0)
   {
    ans[i]=1;
    for(int j=i-1;j>=1;j--)
    {
     ans[j]=0;
    }
    break;
   }
  }
 }
}
main()
{
 freopen("C-large.in","r",stdin);
 freopen("C-large.out","w",stdout);
 scanf("%d",&t);
 scanf("%d%d",&len,&n);
 /*getlcd(len);
 printf("%d\n",lcd);*/
 lim=1000000;
 genprime(lim);
 ans[len-1]=1;
 ans[0]=1;
 solve();
 return 0;
}
