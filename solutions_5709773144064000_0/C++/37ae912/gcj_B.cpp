
#include <cstdio>
#include <iostream>
using namespace std;


int main()
{
	int T,cs=0;
	cin>>T;
	while(++cs <= T){
		double c,f,x;
		cin>>c>>f>>x;


		double res = x/c - 2.0/f - 1.0;
		int k = (res+1.0 - 1e-9);
		double ans=0;
		if(k<=0) ans = x/2.0;
		else{
			double s=2.0;
			while(k--){
				ans += c/s;	
				s += f;
			}	
			ans += x/s;
		}
		
		printf("Case #%d: %.9lf\n",cs,ans);	
	}
	
	
	
	
	return 0;	
}
