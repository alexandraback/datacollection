#include <cstdio>
#include <iostream>
using namespace std;
int ns[31],s[31];
int abs_(int a)
{
if(a<0) return -a;
return a;
}
void check(int a,int b,int c)
{
 int sum,d;
 if(abs_(a-b)>2 || abs_(b-c)>2 || (a-c)>2) return;
 sum = a+b+c;
 d = max(a,max(b,c));
 if(abs_(a-b)==2 || abs_(b-c)==2 || (a-c)==2){
 s[sum]  = d;
 }else ns[sum] = d;
}
void gen()
{
 int i,j,k;
 for(i=0;i<=10;i++)
  for(j=0;j<=10;j++)
   for(k=0;k<=10;k++)     
      check(i,j,k);
}
int T,S,N,P,ans;
int t[200];
main()
{
 int i,j,k;
 gen();
 freopen("B.in","r",stdin);
 freopen("B.out","w",stdout);
 scanf("%d",&T);
 for(j=1;j<=T;j++)
 {
  scanf("%d %d %d",&N,&S,&P);
  ans = 0;
  for(i=0;i<N;i++)
  {
   scanf("%d",&t[i]);
   if(ns[t[i]]>=P) ans+=1;
   else if(s[t[i]]>=P && S>0){ ans+=1;S-=1;}         
  }             
  printf("Case #%d: %d\n",j,ans);
 }


}
