//gskhirtladze

#include <iostream>
#include <stdio.h>

using namespace std;

int t,t1,A,B,K;
long long x[32];

long long norm_sol(int a,int b,int k)
 {
  long long res=0;
    for (int j=0;j<=b;j++)
   {
  for (int i=0;i<=a;i++)
     if ((i&j)<=k) res++;
   }
  return res;
 }

long long solve(int a,int b,int kk)
 {
  if (a > b) return solve(b,a,kk);
  if (a < 0 || kk < 0) return 0;
  if (kk == 0) return 1;
  if (a == 0) return b+1;
  int a1[31],a2[31];
  int i,j;
  for (i=0;i<=30;i++) a1[i]=a2[i]=0;
  x[0]=1;
  for (i=1;i<=30;i++)
   x[i]=x[i-1]*2;
  int k=0; int c=a;
  while (c > 0)
   { a1[k]=c%2; k++; c/=2;}
  k=0; c=b;
  while (c > 0)
   { a2[k]=c%2; k++; c/=2; }
  for (i=30;i>=0;i--)
   if (a1[i] > 0 || a2[i] > 0)
    {
     if (a1[i] == 0)
      {
       long long rest=0;
       for (k=i-1;k>=0;k--) rest=rest*2+a2[k];
       return (solve(a,rest,kk)+solve(a,x[i]-1,kk));
      } else
      {
       return norm_sol(a,b,kk);/*
       long long rest1=0,rest2=0;
       for (k=i-1;k>=0;k--) rest1=rest1*2+a1[k];
       for (k=i-1;k>=0;k--) rest2=rest2*2+a2[k];
       if (a == 6 && b == 7) {
       cout<<solve(rest1,x[i]-1,kk)<<" "<<solve(x[i]-1,rest2,kk)<<" "<<solve(x[i]-1,x[i]-1,kk)<<" "<<solve(rest1,rest2,kk-x[i])<<endl;
       system("pause"); }
       return (solve(rest1,x[i]-1,kk)+solve(x[i]-1,rest2,kk)+solve(x[i]-1,x[i]-1,kk)+solve(rest1,rest2,kk-x[i]));*/
      }
    } 
 }

main()
 {
  freopen("in.in","r",stdin);
  freopen("out.out","w",stdout);
  cin>>t;
  for (t1=1;t1<=t;t1++)
   {
    cin>>A>>B>>K;
    cout<<"Case #"<<t1<<": "<<norm_sol(A-1,B-1,K-1)<<endl;
   }
 }
