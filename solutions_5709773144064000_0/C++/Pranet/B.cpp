#include <cstdio>
#include <iostream>
#include <iomanip>
using namespace std;
main(void)
{
	int t;
	scanf("%d",&t);
	long double C,F,X;
	long double timeToFarm;
	long double timeToTarget;
	long double bestTime;
	long double elapsed; 
	for(int tt=1;tt<=t;++tt)
	{
		int n=1;
		elapsed=0; //number of farms;
		printf("Case #%d: ",tt);
		// scanf("%lf%lf%lf",&C,&F,&X);
		cin>>C>>F>>X;
		bestTime=X/2.0;
		timeToFarm=C/2.0;
		// bestTime=-1324.32;
		while( timeToFarm + X/(2.0+n*F) < bestTime)
		{
			// cout<<bestTime<<" "<<timeToFarm<<endl;
			bestTime= (timeToFarm + X/(2.0+n*F) );
			
			timeToFarm+=C/(2.0+n*F);	
			n++;
		}
		// printf("%f\n",bestTime);
		std::cout << std::fixed;
		cout<<setprecision(7)<<bestTime<<endl;
	}
}
// Case #1: 1.0000000
// Case #2: 39.1666667
// Case #3: 63.9680013
// Case #4: 526.1904762