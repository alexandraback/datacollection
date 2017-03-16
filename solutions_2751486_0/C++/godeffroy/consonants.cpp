#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	std::string name;
	int n;
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		input>>c.name>>c.n;
	}
}

int solve_case(const case_data& c){
	int total=0;
	std::vector<int> count(c.name.size(),0);
	if(!(c.name[0]=='a' || c.name[0]=='e' || c.name[0]=='i' || c.name[0]=='o' || c.name[0]=='u')) count[0]=1;
	for(int i=1;i<c.name.size();i++){
		if(!(c.name[i]=='a' || c.name[i]=='e' || c.name[i]=='i' || c.name[i]=='o' || c.name[i]=='u')) count[i]=count[i-1]+1;
	}
	for(int j=0;j<c.name.size();j++)std::cerr<<count[j]<<" ";
	//for(int j=0;j<c.name.size();j++)if(count[j]>=c.n)total++;
	for(int i=0;i<c.name.size();i++){
		bool ok=false;
		for(int j=i+c.n-1;j<c.name.size();j++){
			if(ok)total++;
			else if(count[j]>=c.n){ok=true;total++;}
		}
	}
	return total;

}

int main(){
	parse_input(std::cin);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<": "<<solve_case(cases[i])<<std::endl;
	}

	return 0;
}
