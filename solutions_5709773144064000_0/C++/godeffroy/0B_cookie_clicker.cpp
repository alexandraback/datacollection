#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	double farm_cost, farm_prod, goal;
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		input>>c.farm_cost>>c.farm_prod>>c.goal;
	}
}

std::string solve_case(const case_data& c){
	double prod=2;
	double cookies=0,time=0;
	double next_farm_time=c.farm_cost/prod;
	double goal_time=(c.goal-cookies)/prod;
	if(goal_time<next_farm_time){char r[40]; sprintf(r,"%.7f",time+goal_time);return r;}
	cookies=c.farm_cost; time+=next_farm_time; goal_time=(c.goal-cookies)/prod;

	while(goal_time>c.goal/(prod+c.farm_prod)){
		cookies=0; prod+=c.farm_prod; next_farm_time=c.farm_cost/prod; goal_time=(c.goal-cookies)/prod;
		if(goal_time<next_farm_time){char r[40]; sprintf(r,"%.7f",time+goal_time);return r;}
		cookies=c.farm_cost; time+=next_farm_time; goal_time=(c.goal-cookies)/prod;
	}
	char r[40]; sprintf(r,"%.7f",time+goal_time);
	return r;
}

int main(){
	parse_input(std::cin);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<": "<<solve_case(cases[i])<<std::endl;
	}

	return 0;
}
