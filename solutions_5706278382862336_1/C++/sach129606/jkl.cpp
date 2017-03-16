#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include<algorithm>
#include<queue>
#include<cstring>
#include<stack>
using namespace std;
#define tr(container,it) \
  for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
typedef pair<long long,long long>ii;

long long gcd1(long long a,long long b)
{

	 if(b==0)
	 return a;
	 else
	 return gcd1(b,a%b);
	
}
int main()
{
	freopen("in1.txt","r",stdin);
freopen("1","w",stdout);
	long long t,id=1;
	cin>>t;
	while(t--)
	{
		long long a=0,b=0;
		string str;
		cin>>str;
		long long i=0;
	//	cout<<id;
		while(str[i]!='/')
		{
		 a=a*10+(str[i]-'0');
		i++;
	   }
	   i++;
	   while(str[i]!='\0')
		{
		 b=b*10+(str[i]-'0');
		i++;
	   }
	  // cout<<a<<b;
    long long k=0;
    long long l=gcd1(a,b);
    a=a/l;
    b=b/l;
	while(b%2==0)
	{
		 b=b/2;
		 k++;
	}
	
	if(b>1)
	{
			cout<<"Case #"<<id<<": "<<"impossible"<<endl;
			
	}
	else
	{
		vector<long long>V;
		while(a!=0)
		{
			long long ll=a%2;
			 V.push_back(ll);
			 ll=ll/2;
			 a=a/2;
		}
		
		long long n1=V.size();
		 for(long long j=n1;j<=k;j++)
          V.push_back(0);
          k=0;
          for(long long jj=V.size()-1;jj>=0;jj--)
          {
          	if(V[jj]==1)
          	break;
          	k++;
          }
          	cout<<"Case #"<<id<<": "<<k<<endl;
	}
	    
	/*k=find(a,b);
		
		if(k<=40)
			cout<<"Case #"<<id<<": "<<k<<endl;
			else
				cout<<"Case #"<<id<<": "<<"impossible"<<endl;
		*/
		id++;
		
	}
 

  return 0;
}
