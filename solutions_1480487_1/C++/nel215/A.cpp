#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

void solve(){
	int T;
	scanf("%d",&T);
	for(int cc=1 ; cc<=T ; cc++){
		int N;
		scanf("%d",&N);
		vector<int> S(N);
		REP(i,N)scanf("%d",&S[i]);
		int X = 0;
		REP(i,N)X += S[i];

		vector<double> res(N);
		REP(i,N){
			double lb = 0,ub = 100000;
			REP(j,50){
				double mid = (lb+ub)/2;
				double Y = 0;
				REP(k,N){
					double y = mid-S[k];
					y /= (double)X;
					Y += max(0.0,y);
				}
				if(Y>1)ub = mid;
				else lb = mid;
			}
			res[i] = ((lb+ub)/2-S[i])/(double)X*100;
		}
		printf("Case #%d: ",cc);
		REP(i,N)printf("%.6f%c",max(0.0,res[i]),(i==N-1?'\n':' '));
	}
}

int main(){
	solve();
	return 0;
}
