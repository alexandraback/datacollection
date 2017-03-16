#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;


int debug=0;

long long gcd(long long a, long long b)
{
	if(a==0)return b;
	if(b==0)return a;
	if(b>a)return gcd(b,a);
	return gcd(b,a%b);
}

int main()
{
int T,ti;
cin>>T;
for(ti=0;ti<T;ti++)
{
	long long p,q;
	scanf("%I64d/%I64d",&p,&q);
	
	long long g=gcd(p,q);
	p=p/g;q=q/g;
	
	int i,lea=-1;
	bool flag=true;
	if(p>q)flag=false;
	for(i=1;i<=40;i++)
	{
		if(p*2>=q)
		{
				if(lea==-1)lea=i;
				p-=q/2;
		}
		if(q==1)break;
		
		if(q%2!=0)flag=false;
		q=q/2;
			
	}
	
	cout<<"Case #"<<(ti+1)<<": ";
	if(flag==false)cout<<"impossible";
	else cout<<lea;
	cout<<endl;
}
return 0;
}