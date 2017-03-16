#include <iostream>
using namespace std;
#include<cmath>
int main()
{
	int t,m=1;
	cin>>t;
	while(t--)
	{
		int b, c,d,v,ans=0;
		cin>>c>>d>>v;
		int a[30];
		for(int i=0;i<d;i++)
		cin>>a[i];
		A:  b=pow(2,d);
		int x[b+2];
		x[0]=0;
		int l=1,y=0;
		int q[31]={0};
		for(int i=0;i<d;i++)
		{
			y=0;
			for(int j=0;j<l;j++)
			{
				x[l+y]=a[i]+x[j];
				if(x[l+y]<=v)
				q[x[l+y]]=1;
				y++;
			}
			l=l+y;
		}
		for(int i=1;i<=v;i++)
		{
			if(q[i]==0)
			{
				ans++;
				a[d++]=i;
				goto A;
			}
		}
		cout<<"Case #"<<m<<": "<<ans<<endl;
		m++;
	}
}
