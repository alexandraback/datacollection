#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int A,B;
int T,ans,z=1;
int fix[2000100];
void check(int a)
{
 char shua[100];
 string s="",b;
 int x,j;
 itoa(a,shua,10);
 for(j=0;j<strlen(shua);j++) s+=shua[j];
 
 for(j=0;j<s.length();j++)
 {
  b = s.substr(j) + s.substr(0,j);
  if(b[0]!='0'){
  x = atoi(b.c_str());
  if(x>a && x>=A && x<=B){ 
  if(fix[x]!=z)ans+=1;
  fix[x] = z;
  }                    
}
 }
}
void solve(int A,int B)
{
 int i;
 for(i=A;i<=B;i++)     
  { check(i);z+=1;}
}
main()
{
 int i,j;
 freopen("C.in","r",stdin);
 freopen("C.out","w",stdout);
 scanf("%d",&T);
 for(j=1;j<=T;j++)
 {
  scanf("%d %d",&A,&B);                 
  ans = 0;
  solve(A,B);
  printf("Case #%d: %d\n",j,ans);         
 }

}
