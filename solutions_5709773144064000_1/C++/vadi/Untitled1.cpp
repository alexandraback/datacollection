#include <iostream>
#include <stdio.h>
#include <iomanip>
using namespace std;

int main() {
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		long double c,f,x,cr=2,ans=0;
		scanf("%llf %llf %llf",&c,&f,&x);
		long double a=x/cr;
		long double b=c/cr+x/(cr+f);
		while(b<a)
		{
			ans+=c/cr;
			cr+=f;
			a=x/cr;
			b=c/cr+x/(cr+f);
		}
		ans+=x/cr;
		
		printf("Case #%d: ",j);
		cout<<fixed<<setprecision(7)<<ans<<endl;
	}
	return 0;
}
