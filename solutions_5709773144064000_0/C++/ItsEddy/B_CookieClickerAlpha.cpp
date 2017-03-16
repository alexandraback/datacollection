#include<cstdio>

int main(){

	int TestCase,Case = 1;
	scanf("%d",&TestCase);
	while(TestCase--){
		double Cost,Farm,Goal,ResultTime,Result,Add,NextFarmTime;
		scanf("%lf%lf%lf",&Cost,&Farm,&Goal);
		Result = 0.0,ResultTime = 0.0,Add = 2.0;
		while(1){
			NextFarmTime = Cost / Add + Cost / Farm;
			if( (Goal - Result) / Add < NextFarmTime )break;
			ResultTime += Cost / Add;
			Add += Farm;
		}
		ResultTime = ResultTime + (Goal - Result) / Add;
		printf("Case #%d: %.7f\n",Case++,ResultTime);
	}
	return 0;
}
