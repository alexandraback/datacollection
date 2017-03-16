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

vector<double> ken;
vector<double> naomi;

int main(){
	int T;
	scanf("%d", &T);
	//cin >> T;
	for(int current_case = 1; current_case <= T; ++current_case){
		//read input
		int N;
		scanf("%d", &N);
		ken.clear();
		naomi.clear();
		for(int i = 0; i < N; ++i){
			double t;
			scanf("%lf", &t);
			naomi.push_back(t);
		}
		sort(naomi.begin(), naomi.end());
		for(int i = 0; i < N; ++i){
			double t;
			scanf("%lf", &t);
			ken.push_back(t);
		}
		sort(ken.begin(), ken.end());
		//process
		int war_points = 0;
		int current_ken_index = 0;
		for(int i = 0; i < N; ++i){
			while(current_ken_index < N){
				if(naomi[i]<ken[current_ken_index]){
					++war_points;
					++current_ken_index;
					break;
				}
				++current_ken_index;
			}
		}
		war_points = N-war_points;
		int naomi_points = 0;
		current_ken_index = 0;
		for(int i = 0; i < N; ++i){
			if(naomi[i]>ken[current_ken_index]){
				++naomi_points;
				++current_ken_index;
			}
		}

		printf("Case #%d:", current_case);
		//cout << "Case #" << current_case << ":";


		printf(" %d %d", naomi_points, war_points);

		//output answer
		printf("\n");
		//cout << endl;
	}
    return 0;
}
