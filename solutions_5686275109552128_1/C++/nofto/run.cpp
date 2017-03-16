#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <set>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);  
	for(int t=1; t<=T; t++)
	{		
		int D;
		scanf("%d",&D);
        vector <int> time(1001);
        for(int i=0;i<1001;i++) time[i]=i;
		for(int i=0; i<D; i++){
		    int P;
			scanf("%d",&P);
			for(int j=1;j<P;j++) time[j]+=(P-1)/j;
		}
		int bestTime=1000;
		for(int i=1;i<1001;i++) bestTime=min(bestTime,time[i]); 
		printf("Case #%d: %d\n",t,bestTime);
	}
  return 0;
}
