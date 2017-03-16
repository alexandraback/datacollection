/*
   Google Code Jam
   Author: FLD 
   Date: 2014/04/12
*/

#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;


#define FOR(loop,first,end) for(int loop=(int)(first);loop<(int)(end);loop++)
#define FORD(loop,first,end) for(int loop=(int)(first);loop<(int)(end);loop--)
#define REP(loop,times) FOR(loop,0,times)



double cost(int farms, double C, double F, double X) {
	double tm = X / (2.+farms*F);
	REP(f,farms) {
		tm += C/(2. + f*F);
	}
	return tm;
}

int main(int argc, char const *argv[])
{
	int T;
	double C, F, X;


	// adjust stding and stdout
	#ifdef DEFAULT
	freopen("stdin.txt","rt",stdin);
	#endif
	#ifdef SMALL
	freopen("stdin_small.txt","rt",stdin);
	freopen("stdout_small.txt","wt",stdout);
	#endif
	#ifdef LARGE
	freopen("stdin_large.txt","rt",stdin);
	freopen("stdout_large.txt","wt",stdout);
	#endif

	cin >> T;
	REP(t,T) {
		cin >> C >> F >> X;
		if (X < C) {
			printf("Case #%d: %.7f\n", t+1, X/2.0);
		} else {
			double best=INFINITY, current=INFINITY;
			int nbFarms = 0;
			do {
				best = current;
				current = cost(nbFarms++, C, F, X);
			} while (current < best);
			printf("Case #%d: %.7f\n", t+1, best);
		}
	}
	
	return 0;
}