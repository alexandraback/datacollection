#include <iostream>
using namespace std;
double a[1105];
int ab(int x)
{
	if (x<0) {return -x;}
	return x;
}
int main()
{
	int tt,z;
	cin>>tt;
	for (z=1;z<=tt;z++)
	{
		int n,x,y,i,j,k,l,r;
		cin>>n>>x>>y;
		l=(ab(x)+y)/2;
		if (x==0 && y==0)
		{
			printf("Case #%d: %.8lf\n",z,1.0);
			continue;
		}
		if (x==0 && n-2*l*l+l<(l*2)*2+1)
		{
			printf("Case #%d: %.8lf\n",z,0.0);
			continue;
		}
		if (x==0 && n-2*l*l+l==(l*2)*2+1)
		{
			printf("Case #%d: %.8lf\n",z,1.0);
			continue;
		}
		if (n<=2*l*l-l || n-2*l*l+l<y+1)
		{
			printf("Case #%d: %.8lf\n",z,0.0);
			continue;
		}
		if (n-2*l*l-l>=y+1)
		{
			printf("Case #%d: %.8lf\n",z,1.0);
			continue;
		}
		if (n-2*l*l-l<=l+1)
		{
			memset(a,0,sizeof(a));
			a[0]=1;
			for (i=1;i<=n-2*l*l+l;i++)
			{
				for (j=l*2;j>=1;j--)
				{
					a[j]+=a[j-1]*0.5*(1-a[j]);
				}
			}
			printf("Case #%d: %.8lf\n",z,a[y+1]);
		}
		else
		{
			memset(a,0,sizeof(a));
			a[0]=1;
			for (i=1;i<=y+1-(n-2*l*l-l);i++)
			{
				for (j=l*2;j>=1;j--)
				{
					a[j]+=a[j-1]*0.5*(1-a[j]);
				}
			}
			printf("Case #%d: %.8lf\n",z,a[y+1-(n-2*l*l-l)]);
		}
	}
}