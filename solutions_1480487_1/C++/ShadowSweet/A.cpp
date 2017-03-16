#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <functional>
#include <map>
#include <set>
#include <fstream>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define SZ(a) (int)(a).size()
#define ALL(a) (a).begin(), (a).end()
#define ZERO(a) memset(a, 0, sizeof(a))
#define PB push_back
#define MP make_pair

#define LEN(a) (int)(sizeof(a) / sizeof(a[0]))

int s[205];
double r[205];

int main()
{
	int T,N;
	scanf("%d",&T);
	FOR(tt,1,T+1){
		int sum = 0;
		scanf("%d",&N);
		REP(i,N){
			scanf("%d",&s[i]);
			sum += s[i];
		}
		int dsum = sum*2;
		double lim = 1.0*dsum/N;
		//cout<<tN<<endl;
		printf("Case #%d:",tt);
		int tn = 0;
		double tc = 0;
		REP(i,N){
			double cc = 100.0*(lim-s[i])/sum;
			if (cc < 0){
				tc += -1*cc;
				tn++;
				r[i] = 0;
			} else {
				r[i] = cc;
			}
			//cout<<lim<<" "<<s[i]<<" "<<sum<<" "<<cc<<endl;
			//cout<<lim<<" "<<s[i]<<" "<<dsum<<" "<<cc<<endl;
			//printf(" %.6lf",cc);
		}
		REP(i,N)
			if (r[i]!=0){
				r[i] -= tc/(N-tn);
			}
		REP(i,N)
			printf(" %.6lf",r[i]);
		printf("\n");
	}
	return 0;
}
