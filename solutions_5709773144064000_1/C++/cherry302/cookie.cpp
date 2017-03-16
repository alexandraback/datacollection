#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t,i;
	cin>>t;
	for(i=1;i<=t;i++)
	{
		double c,f,x,rate=2;
		long long int j=0;
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
			while((x/(2+f*j))>(x/(2+f*(j+1)))+(c/(2+f*j)))
			{
				tot=tot+(c/(2+f*j));
				j++;
			}
			tot=tot+(x/(2+f*(j)));
			printf("Case #%d: %.7lf\n",i,tot);
			cout<<endl;
		}
	}
	return 0;
}