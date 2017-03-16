#include<iostream>
using namespace std;
#include<math.h>
#include<stdio.h>
#include<string.h>
#include<vector>

long long hcf(long long a,long long b)
  {
  	if(b==0)
  	  return a;
  	return hcf(b,a%b);
  }
  
  int recur(double a)
    {
    	if(2*a>=1)
    	  return 1;
    	return (1+recur(2*a));
    }
int main()
 {freopen("in2.cpp","r",stdin);
 freopen("out.txt","w",stdout);
 	int t;
 	cin>>t;
 	long long n,d;
	 char ch;
	 double a;
 	for(int l=1;l<=t;l++)
 	  {
 	   cin>>n>>ch>>d;
 	   long long h=hcf(n,d);
 	   n/=h;
 	   d/=h;
 	   int flag=1;
 	   a=n*1.0/d;
 	   int x=(int)(ceil(log2(d)));
 	  // cout<<x<<" "<<d<<" "<<(pow(2,x))<<endl;
 	   if((long long)(pow(2,x))!=d)
 	     {
 	     flag=0;
 	     //cout<<d<<" "<<x<<endl;
 	     }
 	    //cout<<x<<endl;
	  
 	   int i=recur(a);
 	   
 	  
 	    if(flag)
 	    { a=n*1.0/d;
 	    cout<<"Case #"<<l<<": "<<i<<endl;
 	   } 
 	  else
 	    cout<<"Case #"<<l<<": impossible"<<endl;
 	  }
 	
 }
