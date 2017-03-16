#include<iostream>
using namespace std;
#include<bits/stdc++.h>
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
typedef long long int lli;
typedef long int li;
#define ff first
#define ss second
#define mod 1000000007;
int has[10000001];
lli min(lli i,lli j)
 {
 	if(i>j)return i;
 	else return j;
 }
 lli gcd (lli a,lli  b)
  {
  	if(a%b==0)return b;
  	else return gcd(b,a%b);
  }

int main()
 {
 	// freopen("abc.txt","r",stdin);
 //	freopen("pqr.txt","w",stdout);
 	int t;
 	 cin>>t;
 	 lli tt=1;
 	 while(t--)
 	 {
 	 	
 	 
 	 lli  n;
 	 cin>>n;
     for(int i=0;i<=n;i++)has[i]=10000001;
 	 queue<pair<lli,lli> > q;
	   q.push(make_pair(1,1));
	    while(!q.empty())
		 {
		 	   lli no=q.front().ff;
		 	   lli val=q.front().ss;
		 	   q.pop();
		 	   if(no==n)
		 	    {
		 	    	 cout<<"Case #"<<tt++<<": "<<val<<endl;
		 	    	 break;
		 	    	 
		 	    }
		 	    else
		 	     {
		 	     	if(no+1<=n  && has[no+1]>val+1) 
					  {
					  	q.push(make_pair(no+1,val+1));
					  	has[no+1]=val;
					  }
		 	         lli rev=0;
		 	          while(no!=0)
		 	           {
		 	           	rev=rev*10+no%10;
		 	           	no/=10;
		 	           }
		 	           if(rev<=n  &&  has[rev]>val+1)
		 	            {
		 	            	q.push(make_pair(rev,val+1));
		 	            
		 	            }
		 	     }
		 	    
		 } 	 
	}
		 return 0;
 }
