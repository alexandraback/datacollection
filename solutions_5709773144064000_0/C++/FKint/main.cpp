/**
	Author: Floris Kint
  **/


#include <cstdio>
#include <bitset>
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	//cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
		double C, F, X;
		scanf("%lf%lf%lf", &C, &F, &X);
		//process

		double best_time = X/2.0;
		double current_production = 2.0;
		double last_farm_time = 0.0;
		while(last_farm_time < best_time){
			last_farm_time += C/current_production;
//			printf("time to make new farm: %.7lf\n", C/current_production);
			current_production += F;
			double new_time = last_farm_time + X/current_production;
			best_time = min(best_time, new_time);
		}




		printf("Case #%d:", current_case);
		//cout << "Case #" << current_case << ":";
		//output answer

		printf(" %.7lf", best_time);

		printf("\n");
		//cout << endl;
	}
    return 0;
}
