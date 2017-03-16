#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<ctype.h>
#include<iostream>
#include<iomanip>
#include<sstream>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<complex>
#define EPS (1e-10)
#define PI (3.141592653589793238)
#define MP make_pair
typedef long long ll;
using namespace std;

int n;
double val[1000];

bool check(int p,double mid){
	double sum=0;
	for(int i=0;i<n;i++){
		sum+=val[i];
	}
	double target=val[p]+sum*mid;
	double vsum=0;
	for(int i=0;i<n;i++){
		if(i==p)continue;
		if(target<val[i])continue;
		double left=target-val[i];
		vsum+=(left/sum);
	}
	//printf("%d %f   %f     %f\n",p,mid,target,vsum);
	if(mid+vsum>1)return true;
	return false;
}

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%lf",&val[i]);

		printf("Case #%d:",casecnt);
		for(int p=0;p<n;p++){
			double ub=1,lb=0;
			for(int t=0;t<200;t++){
				double mid=(ub+lb)/2;
				if(check(p,mid)){
					ub=mid;
				}else{
					lb=mid;
				}
			}
			printf(" %.10f",ub*100);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}
