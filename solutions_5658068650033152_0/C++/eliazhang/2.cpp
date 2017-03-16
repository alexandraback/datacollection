#include<iostream>
#include<stdio.h>
#include<string>
#include<cstdio>
#include <sstream>
#include <cmath>
#include <algorithm>
using namespace std;



void main()
{
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("C-small-attempt3.out", "w", stdout);
	int t;cin>>t;
  for(int i=1;i<=t;i++){
	  int n,m,k;
	  
	  cin>>n;
	  cin>>m;
	  cin>>k;
	  int res;
	  int u;
	  int lenth;
	  if(n>m)
	  {
		  u=n;
		  n=m;
		  m=k;
	  }
	  if(n<=2||k<=4)
	  {
		  res=k;
	  }
	  else if(n==3||k<12)
	  {
		  lenth=k/3;
		  if(k%3==0)
			  res=2*lenth-1;
		  else if(k%3==1)
			  res=2*lenth+3;
		  else 
			  res=2*lenth-1;
	  }
	  else if(n==4||k<21)
	  {
		  lenth=k/4;
			  res=2*lenth+2+k%4;
	  }
	
	  
		  cout<<"Case #"<<i<<": "<<res<<endl;
	
		
	}
	


}
