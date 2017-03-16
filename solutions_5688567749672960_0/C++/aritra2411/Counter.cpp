#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<string.h>
#include<stdlib.h>
#include<set>
#include<map>
#include<math.h>

int gcd(int a, int b)
{
	if(a%b==0)
	return a;
	else
	return gcd(b,a%b);
}

int read_int(){
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


using namespace std;



typedef long long int john;

typedef long int petrucci;

#define fi first
#define se second
#define mod 10000000006;
int has[10000007];
john min(john i,john j)
 {
 	if(i>j)return i;
 	else return j;
 }
 john gcd (john a,john  b)
  {
  	if(a%b==0)return b;
  	else return gcd(b,a%b);
  }

int main()
 {
 	freopen("question.txt","r",stdin);
 	freopen("answer.txt","w",stdout);


 	int k;
 	 cin>>k;
 	 john ot=1;
 	 while(k--)
 	 {


 	 john  d;
 	 cin>>d;
     for(int j=0;j<=d;j++)has[j]=10000007;
 	 queue<pair<john,john> > qu;
	   qu.push(make_pair(1,1));

	    while(!qu.empty())
		 {
		 	   john number=qu.front().fi;
		 	   john value=qu.front().se;
		 	   qu.pop();
		 	   if(number==d)
		 	    {
		 	    	 cout<<"Case #"<<ot++<<": "<<value<<endl;

		 	    	 break;

		 	    }

		 	    else
		 	     {
		 	     	if(number+1<=d  && has[number+1]>value+1)
					  {
					  	qu.push(make_pair(number+1,value+1));
					  	has[number+1]=value;
					  }
		 	         john revers=0;


		 	          while(number!=0)
		 	           {
		 	           	revers=revers*10+number%10;
		 	           	number/=10;
		 	           }
		 	           if(revers<=d  &&  has[revers]>value+1)
		 	            {
		 	            	qu.push(make_pair(revers,value+1));

		 	            }
		 	     }

		 }
	}
		 return 0;
 }
