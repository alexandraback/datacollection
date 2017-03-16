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
		int Smax;
		scanf("%d ",&Smax);
		//cerr << "-----" << endl << Smax << endl << "-----" << endl;
		int friends=0;
		int standing=0;
        for(int i=0; i<=Smax; i++){
		    char c;
			scanf("%c",&c);
			if(standing<i){
				friends+=i-standing;
				standing=i;
			}
			standing+=c-48;
			//cerr << shy[i] << endl;
			scanf("\n");
		}
		printf("Case #%d: %d\n",t,friends);
	}
  return 0;
}
