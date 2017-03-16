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

int main(void){
	int casenum;
	scanf("%d",&casenum);
	for(int casecnt=1;casecnt<=casenum;casecnt++){

		int a,b,l;
		scanf("%d %d",&a,&b);
		l=b-a;

		vector<double> p(a);
		for(int i=0;i<a;i++){
			scanf("%lf",&p[i]);
		}

		double ans=(b+2);
		double prod=1;
		for(int i=1;i<=a;i++){
			prod*=p[i-1];

			double val=(prod)*(l+2*a+1-2*i)+(1-prod)*(l+2*a+1-2*i+b+1);

			ans=min(ans,val);
		}

		printf("Case #%d: %.10f\n",casecnt,ans);
		fflush(stdout);
	}
	return 0;
}
