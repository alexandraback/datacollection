#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	int x,y;
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		input>>c.x>>c.y;
	}
}

std::string solve_case(const case_data& c){
	std::string moves="";
	std::string x_inc=(c.x>0)?"E":"W";
	std::string x_dec=(c.x>0)?"W":"E";
	std::string y_inc=(c.y>0)?"N":"S";
	std::string y_dec=(c.y>0)?"S":"N";
	int xf=(c.x>0)?c.x:-c.x;
	int yf=(c.y>0)?c.y:-c.y;
	for(int i=0;i<xf;i++)moves+=x_dec+x_inc;
	for(int i=0;i<yf;i++)moves+=y_dec+y_inc;
	return moves;
}

int main(){
	parse_input(std::cin);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<": "<<solve_case(cases[i])<<std::endl;
	}

	return 0;
}
