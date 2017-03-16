#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#define pii pair<int, int>
#define VI vector < int >
#define PB push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FORD(i,a,b) for(i=a;i>b;i--)
typedef long long LL;
using namespace std;
long long int  gcdr ( long long int a, LL b )
{
	if(b<a)
		gcdr(b,a);
	  if ( a==0 ) 
		  return b;
	    return gcdr ( b%a, a );
}

int main()
{
	int i,j,k,n,t;
	cin>>t;
	long long a,b;
	for(k=1;k<=t;k++)
	{
		scanf("%Ld/%Ld",&a,&b);
		long long g=gcdr(a,b);
		a=a/g;
		b=b/g;
		long long b1=b;
		int ans=1,l=0,l1=0;;
		while(b1!=0)
		{
			l++;
			if(b1%2==1 && b1!=1)
			{	
				ans=0;
			}
			b1=b1/2;
		}
		while(a!=0)
		{
			l1++;
			a=a/2;
		}
		cout<<"Case #"<<k<<": ";
		 if(ans==0)
			cout<<"impossible\n";
		else
			cout<<l-l1<<endl;
	}
	return 0;
}
