#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	int n_diamonds;
	int x,y;
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		input>>c.n_diamonds>>c.x>>c.y;
	}
}

double solve_case(const case_data& c){
	if((c.x+c.y)%2)return 0;
	int small_pyramid_h=(c.x+c.y)/2;
	int small_pyramid_N=small_pyramid_h*(2*small_pyramid_h-1);

	int remaining=c.n_diamonds-small_pyramid_N;

	if(remaining<c.y+1) return 0;
	if(remaining>=4*small_pyramid_h+1) return 1;
	if(c.x==0) return 0;

	double p=0;
	if(remaining<=2*small_pyramid_h){
		std::vector<double> proba(remaining+1,0); proba[remaining]=1;
		for(int j=0;j<remaining;j++){
			for(int i=remaining-1-j;i<remaining;i++)proba[i]=proba[i]/2+proba[i+1]/2;
			proba[remaining]/=2;
		}
		for(double d:proba)std::cerr<<d<<" "; std::cerr<<std::endl;
		for(int i=0;i<remaining-c.y;i++)p+=proba[i];
	}else if(remaining-2*small_pyramid_h>c.y){
		return 1;
	}else{
		std::vector<double> proba(remaining+1,0); proba[remaining]=1;
		int j;for(j=0;j<2*small_pyramid_h;j++){
			for(int i=remaining-1-j;i<remaining;i++)proba[i]=proba[i]/2+proba[i+1]/2;
			proba[remaining]/=2;
		}
		int k=1;for(;j<remaining;j++,k++){
			int i;for(i=remaining-1-j;i<remaining-k;i++)proba[i]=proba[i]/2+proba[i+1]/2;
			proba[i]=proba[i]/2+proba[i+1];i++;
			for(;i<remaining+1;i++)proba[i]=0;
		}
		for(double d:proba)std::cerr<<d<<" "; std::cerr<<std::endl;
		for(int i=0;i<remaining-c.y;i++)p+=proba[i];
	}

	return p;
}

int main(){
	parse_input(std::cin);
	std::cout.precision(10);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<": "<<solve_case(cases[i])<<std::endl;
	}

	return 0;
}
