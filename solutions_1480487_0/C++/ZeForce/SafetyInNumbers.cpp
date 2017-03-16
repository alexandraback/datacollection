/* * * * * * * * * * * * * * * * * * * * * * * * * * *
   Author       : Nishant R. Krishan  
   File Name    : SafetyInNumbers.cpp
   Last Modified: Sat 05 May 2012 10:58:16 PM IST 
 * * * * * * * * * * * * * * * * * * * * * * * * * * */

/** Standard Libraries **/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<climits>
#define SI ({int x;scanf("%d",&x);x;})

using namespace std;
int main()
{
	int T=SI,k;
	for(k=1;k<=T;k++){
		int N=SI;
		int S[N];
		int i;
		double Sum=0;
		for(i=0;i<N;i++){
			S[i]=SI;
			Sum += S[i];
		}
		double Average = (Sum+Sum)/N;
		double NewAverage=0;
		double P[N];
		int Count=0;
		for(i=0;i<N;i++){
			if( S[i]<Average ){
				NewAverage += S[i];
				Count++;
			}
		}
		NewAverage = (NewAverage+Sum)/Count;
		while( Average!=NewAverage )
		{
			Average = NewAverage;
			NewAverage = 0;
			Count=0;
			for(i=0;i<N;i++){
				if( S[i]<Average ){
					NewAverage += S[i];
					Count++;
				}
			}
			NewAverage = (NewAverage + Sum)/Count;
		}
		for(i=0;i<N;i++){
			if( S[i]>=Average )
				P[i]=0.0;
			else
				P[i] = (Average - S[i])/Sum;
				P[i] = P[i]*(100.0);
		}
		printf("Case #%d: ",k);
		for(i=0;i<N-1;i++)
			printf("%lf ",P[i]);
		if( k==T )
			printf("%lf",P[N-1]);
		else
			printf("%lf\n",P[N-1]);
	}
	return 0;
}
