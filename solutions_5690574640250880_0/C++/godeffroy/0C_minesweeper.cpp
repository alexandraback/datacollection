#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	int rows,cols,n_mines;
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		input>>c.rows>>c.cols>>c.n_mines;
	}
}

std::string solve_case(const case_data& c){
	std::stringstream r; int n_mines=c.n_mines; int n_free=c.rows*c.cols-c.n_mines;
	if(n_free==1){
		for(int i=0;i<c.rows-1;i++){for(int j=0;j<c.cols;j++)r<<"*"; r<<std::endl;}
		for(int j=0;j<c.cols-1;j++)r<<"*"; r<<"c"<<std::endl;
		return r.str();
	}

	if(c.cols==1){for(int j=0;j<c.rows-1;j++){r<<(n_mines-- >0?"*":"."); r<<std::endl;} r<<"c"<<std::endl; return r.str();}
	if(c.rows==1){for(int j=0;j<c.cols-1;j++) r<<(n_mines-- >0?"*":".");                r<<"c"<<std::endl; return r.str();}

	if(n_free==5 || n_free==7 || n_free<4) return "Impossible\n";

	if(c.rows==2 || c.cols==2){
		if(n_mines%2) return "Impossible\n";
		n_mines/=2;
		if(c.cols==2){for(int j=0;j<c.rows-1;j++){r<<(n_mines-- >0?"**":".."); r<<std::endl;} r<<".c"<<std::endl; return r.str();}
		if(c.rows==2){
			for(int j=0;j<c.cols-1;j++) r<<(n_mines-- >0?"*":".");                
			std::string s=r.str(); 
			r<<"."<<std::endl<<s<<"c"<<std::endl; return r.str();
		}
	}

	for(int i=0;i<c.rows-3;i++){
		for(int j=0;j<c.cols-2;j++)r<<(n_mines-- >0?"*":"."); 
		if(n_mines>=2){r<<"**"; n_mines-=2;} else r<<"..";
		r<<std::endl;
	}
	for(int j=0;j<c.cols-3;j++)r<<(n_mines-- >0?"*":"."); 
	bool odd=n_mines%2;
	if(odd && n_mines>0){r<<"*"; n_mines--;} else r<<".";
	if(odd && n_mines>2){r<<"**"; n_mines-=2;} else r<<"..";
	r<<std::endl;

	n_mines/=2; std::stringstream r2; 
	for(int j=0;j<c.cols-1;j++) r2<<(n_mines-- >0?"*":".");                
	r<<r2.str()<<"."<<std::endl<<r2.str()<<"c"<<std::endl; return r.str();
}

int main(){
	parse_input(std::cin);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<":\n"<<solve_case(cases[i]);
	}

	return 0;
}
