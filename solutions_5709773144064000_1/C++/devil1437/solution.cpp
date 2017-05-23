#include <stdio.h>
#include <stdlib.h>

int main(){
	int numTestCase = 0;
	double costCookie = 0., extraCookie = 0., targetCookie = 0.;
	double staticTime = 0., dynamicTime = 0., smallestTime = 0., largestStaticTime = 0.;
	int buyCount = 0;
	int i, j, temp;
	int testCase;
	
	scanf("%d", &numTestCase);
	
	for(testCase = 0; testCase < numTestCase; testCase++){

		scanf("%lf %lf %lf", &costCookie, &extraCookie, &targetCookie);
		largestStaticTime = targetCookie/2.;
		smallestTime = largestStaticTime;
		buyCount = 1;
		
		while(1){
			staticTime = 0.;
			
			for(i = 0; i < buyCount; i++){
				staticTime += costCookie/(2.+(double)i*extraCookie);
			}
			
			dynamicTime = targetCookie/(2.+(double)buyCount*extraCookie);
			
			if(staticTime + dynamicTime < smallestTime){
				smallestTime = staticTime + dynamicTime;
			}
			else{
				break;
			}
			
			buyCount++;
		}
		
		printf("Case #%d: %.7f\n", testCase+1, smallestTime);
	}
	
	return 0;
}
