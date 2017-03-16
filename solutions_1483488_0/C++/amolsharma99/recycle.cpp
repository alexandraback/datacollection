#include<iostream>	
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<cassert>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int UINT;
int gcd( int a, int b ) {  if( !b ) return a;  return gcd( b, a % b ); }


int mov(int n,int k,int l)
{
	int t=k;
	k=pow(10,k);
	int x=n%k;
	n=n/k;
//	cout<<n<<"  "<<k<<"  "<<x<<endl;
	x=x*(int)pow(10,l-t);
//	cout<<x<<endl;
	return (x+n);
}



int main()
{
	int tc,i,n,j,k,l,count,a,b,res;
	scanf("%d",&tc);
	set< pair<int,int> > s;
	for(i=0;i<tc;i++)
	{
		scanf("%d%d",&a,&b);
		count=0;
		for(j=a;j<=b;j++)
		{
			n=j;
			l=log10(n)+1;
			for(k=1;k<l;k++)
			{
			//	cout<<n<<"  "<<k<<"  "<<l<<endl;
				res=mov(n,k,l);
			//	cout<<res<<endl;
				if(res>=a && res<=b && res!=n && res>n)
				{
					if(s.find(make_pair(n,res))==s.end())
					{	
						count++;
						s.insert(make_pair(n,res));
					}
				}
			}
		}
		printf("Case #%d: %d\n",i+1,count);
		s.clear();
	}
	return 0;
}
