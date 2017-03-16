#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

bool fless(double a,double b){ return b-a>1e-6; }
bool fequal(double a,double b){ return fabs(b-a)<=1e-6; }

int main(){
	int tt; scanf("%d",&tt);
	for (int ti=1;ti<=tt;ti++){
		double ans = 1e20;
		int n,m; scanf("%d%d", &n, &m);
		int a=n, b=m;
		double p[n], P[n];
		for (int i=0;i<n;i++){
			scanf("%lf", &p[i]);
		}
		P[0] = p[0];
		for (int i=1;i<n;i++){
			P[i] = P[i-1]*p[i];
		}

		double exp, p_wrong, p_correct;
	  //continue
		p_wrong = 1; p_correct = 1;
		exp = (b-a+1) * P[n-1];
		for (int i=0;i<n;i++){
			if (i>0){
				exp += (b-a+1+b+1)*(P[i-1]*(1-p[i]));
			}else{
				exp += (b-a+1+b+1)*(1-p[i]);
			}
		}

		if (exp <= ans){
			ans = exp;
		}

		//x back
		for (int back=1; back<=a; back++){
			double pp;
			if (a-back==0){
			  pp = 1;
			}else{
			  pp = P[a-back-1];
			}
			exp = pp*(back+back+1+b-a) + (1-pp)*(back+back+1+b-a+b+1);
			if (exp <= ans){
				ans = exp;
			}
		}

		//retype
		exp = b+2;
		if (exp <= ans){
			ans = exp;
		}

		printf("Case #%d: %lf\n",ti,ans);
	}
	return 0;
}

