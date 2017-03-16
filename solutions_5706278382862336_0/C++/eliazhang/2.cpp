#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdio>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;


long long int gcd(long long int a, long long int b) {
   long long int t;
    if (a < b) {
        t = a;
        a = b;
        b = t;
    }
    while (t = a % b) {
        a = b;
        b = t;
    }
    return b;
}
void main()
{
	freopen("A00.in", "r", stdin);
	freopen("A00.out", "w", stdout);
	int t;cin>>t;
  for(int i=1;i<=t;i++){
	  string a;
	  cin>>a;
	  long long int b=0;
	  long long int c=0;
	  int j=0;
	  while(a[j]!='/')
	  {
		  b*=10;
		  b=b+a[j]-48;
		  j++;
	  }
	  j++;
	  while(j<a.size())
	  {
		  c*=10;
		  c=c+a[j]-48;
		  j++;
	  }
	  long long int gc=gcd(b,c);
	  b=b/gc;
	  c=c/gc;
	  int pos=0;
	  //cout<<b<<"¡¡¡¡¡¡"<<c<<endl;
	  while(c>=2)
	  {
		  if(c%2==0){
			  
			  c=c/2;
			  pos++;
		  }
		  else
		  { pos=-1;break;}

	  }
	  if(pos==-1)
	  {
		  cout<<"Case #"<<i<<": impossible"<<endl;
	  }
	  else
	  {
		  int m=1;
		  int mm=0;
		  while(m<=b)
		  {
			  m*=2;
			  mm++;
		  }
		  int res=pos-mm+1;
		  cout<<"Case #"<<i<<": "<<res<<endl;
	  }


	 








		
	}
	

	
}
