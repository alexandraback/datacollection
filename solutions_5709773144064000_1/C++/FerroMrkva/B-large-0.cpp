#include <algorithm>

using namespace std;

double C,F,X;

double solve(double v,double goal){
	double res=goal/v;
	double next=C/v;
	if (C<goal){
		double v2=v+F;
		if (next+goal/v2<res)
			return next+solve(v2,goal);
	}
	return res;
}

void solve_case(){
	scanf("%lf %lf %lf",&C,&F,&X);
	double res=solve(2,X);
	printf("%.9lf\n",res);
}

int main(){
	int cases;
	scanf("%d",&cases);
	for(int t=1;t<=cases;++t){
		printf("Case #%d: ",t);
		solve_case();
	}
	return 0;
}

