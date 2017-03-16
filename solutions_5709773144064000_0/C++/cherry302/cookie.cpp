#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		double c,f,x,j,rate=2;
		cin>>c>>f>>x;
		double tot=0;
		if(x<c)
		{
			tot=tot+x/2;
			printf("Case #%d: %.7lf\n",i,tot);
			cout<<endl;
		}
		else
		{
			for(j=0;j<2500;j++)
			{
				if((x/(2+f*j))>(x/(2+f*(j+1)))+(c/(2+f*j)))
				{
					tot=tot+(c/(2+f*j));
				}
				else 
				{
					break;
				}

			}
			tot=tot+(x/(2+f*(j)));
			printf("Case #%d: %.7lf\n",i,tot);
			cout<<endl;
		}
	}
	return 0;
}