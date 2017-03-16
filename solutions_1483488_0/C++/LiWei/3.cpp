#include <iostream>
using namespace std;
#define CHANGE(n,e) ((n)/10+(e)*((n)%10))
int main()
{
	int c,t,a,b,i,k,r,e,j=i;
	cin>>t;
	for(c=0;c<t;c++)
	{
		r=0;e=1;
		cin>>a>>b;
		while(e<=a)
		{
			e*=10;
		}
		if(e>1) e/=10;
		for(i=e+1;i<=b;i++)
		{
			k=(i>=a)?1:0;j=i;
			if(e*10<=i)
			{
				e*=10;
				continue;
			}
			do
			{
				j=CHANGE(j,e);
				if(j>i && j>e && j<=b && j>=a)
					k++;
			}while(j>i || j<e);
			if(j<i && j>e)
				continue;
			r+=(k-1)*k/2;
			//if(k>1)
			//	cout<<"i="<<i<<" k="<<k<<endl;
		}
		cout<<"Case #"<<c+1<<": "<<r<<endl;
	}
}
