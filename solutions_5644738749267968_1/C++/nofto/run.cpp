#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int N;
		scanf("%d",&N);
		vector <double> naomi(N);  
		vector <double> ken(N);  
		for(int i=0;i<N;i++) scanf("%lf",&naomi[i]);
		for(int i=0;i<N;i++) scanf("%lf",&ken[i]);
		sort(naomi.begin(),naomi.end());
		sort(ken.begin(),ken.end());
		
		int war=N;
		int ki=0;
		for(int ni=0;ni<N;ni++){
			while(ki<N && ken[ki]<naomi[ni]){
				ki++;
			}
			if(ki<N) war--;
			ki++; 
		}
		
		int dwar=0;
		ki=0;
		for(int ni=0;ni<N;ni++){
			if(ken[ki]<naomi[ni]){
				ki++;
				dwar++;
			}
		}
			
		
		printf("Case #%d: %d %d\n",t,dwar,war);				
	}
  return 0;
}
