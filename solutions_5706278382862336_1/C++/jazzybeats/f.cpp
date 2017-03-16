#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
long long gcd(long long a,long long b)
{ if ( a==0 ) return b; return gcd ( b%a, a ); }

 int main()
  {
      freopen("A-large.in","r",stdin);
      freopen("output.txt","w",stdout);
       long long r,T,t,i,j,k,cnt,l,m,g,b,n,x,sm,f,num,den;
   char a;
  //cin.open("input.txt",ios::in);
  //freopen("output.txt","w",stdout);
  cin>>t; for(k=1;k<=t;k++) { cout<<"Case #"<<k<<": "; cin>>num>>a>>den; n=gcd(num,den); num/=n; den/=n; i=0; sm=40; while(i<41) { if(num==den)break; i++; if(num*2>den) { num*=2; num-=den; n=gcd(num,den); num/=n; den/=n; if(sm>i)sm=i; } else if(num*2==den) { if(sm>i)sm=i; break; } else { num*=2; if(den%2==0) { den/=2; num/=2; } } } if(i>40)cout<<"impossible"<<endl; else cout<<sm<<endl; } return 0; }
