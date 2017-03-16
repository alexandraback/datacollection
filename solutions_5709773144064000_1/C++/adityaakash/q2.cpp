#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
	//std::ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	
	for (int i = 1; i <=t ; i++)
	{
		long double c, f, x;
		cin>>c>>f>>x;
		
		long double val = x/2.0;
		
		long double anss[100001];
		long double ans1=0;
		anss[0]=0;
		anss[1]=c/2.0;
		for(int j=2; j<=100001; j++)
		{
			anss[j]=anss[j-1] + c/(2.0+(j-1)*f);
		}
		
		
		for(int j=1; j<=100001; j++)
		{
			long double temp = anss[j] + x/(2.0 + j * f);
			if(temp<val)
				val = temp;
		}
		
		//cout<<"Case #"<<i<<": "<<val<<endl;
		printf("Case #%d: %Lf\n",i,val);
	}
}
