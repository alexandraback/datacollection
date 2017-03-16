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

double small(int A,int B,vector<double> P){
	double res = 1+B+1;//right away
	for(int back=0 ; back<=A ; back++){
		double exp = 0;
		for(int bit=0 ; bit<(1<<A) ; bit++){
			double p = 1;
			REP(i,A){
				if(bit>>i&1)p *= 1.0-P[i];
				else p *= P[i];
			}
			// check wrong letters
			bool isWrong = false;
			REP(i,A-back){
				if(bit>>i&1)isWrong = true;
			}
			int cnt = 2*back+B-A+1;
			if(isWrong){
				//cout << cnt+B+1 << " ";
				exp += p*(cnt+B+1);
			}else{
				//cout << cnt << " ";
				exp += p*(cnt);
			}
		}
		res = min(res,exp);
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int c=1 ; c<=T ; c++){
		int A,B;
		scanf("%d%d",&A,&B);
		vector<double> P(A);
		REP(i,A)scanf("%lf",&P[i]);
		double ans = small(A,B,P);
		printf("Case #%d: %.6f\n",c,ans);
	}
	return 0;
}
