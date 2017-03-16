#include<iostream>
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<list>
#include<queue>
#include<vector>
#include<set>
#include<stdlib.h>
#include<queue>
#include<stack>
#define ff first
#define ss second
#define mod 1000000007
int hasherarray[1000010];
using namespace std;
long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}
 int main()
 {

  freopen("abc.txt","r",stdin);
 	freopen("ans.txt","w",stdout);
 	int t;
 	// cin>>t;
 	 t=read_int();
	  long long int  testcasenumber=1;
 	 while(t--)
 	 {
 	 	
 	 
 	 long long int   n;
 	 n=read_int();
     for(int i=0;i<=n;i++)hasherarray[i]=10000001;
 	 queue<pair<long long int ,long long int > > q;
	   q.push(make_pair(1,1));
	    while(!q.empty())
		 {
		 	   long long int  number=q.front().ff;
		 	   long long int  val=q.front().ss;
		 	   q.pop();
		 	   if(number==n)
		 	    {
		 	    	 cout<<"Case #"<<testcasenumber++<<": "<<val<<endl;
		 	    	 break;
		 	    	 
		 	    }
		 	    else
		 	     {
		 	     	if(number+1<=n  && hasherarray[number+1]>val+1) 
					  {
					  	q.push(make_pair(number+1,val+1));
					  	hasherarray[number+1]=val;
					  }
		 	         long long int  reversedval=0;
		 	          while(number!=0)
		 	           {
		 	           	reversedval=reversedval*10+number%10;
		 	           	number/=10;
		 	           }
		 	           if(reversedval<=n  &&  hasherarray[reversedval]>val+1)
		 	            {
		 	            	q.push(make_pair(reversedval,val+1));
		 	            
		 	            }
		 	     }
		 	    
		 } 	 
	}
		 return 0;
 }
