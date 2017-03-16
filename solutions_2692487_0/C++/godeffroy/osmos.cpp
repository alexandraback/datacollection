#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
//#include<cmath>
//#include<gmpxx.h>

struct case_data{
	int init_size;
	std::vector<int> motes_sizes;
};

std::vector<case_data> cases;

void parse_input(std::istream& input){
	int cases_n; input>>cases_n; cases.resize(cases_n);
	for(auto& c:cases){
		int n;
		input>>c.init_size>>n; c.motes_sizes.resize(n);
		for(auto& s:c.motes_sizes) input>>s;
	}
}

int solve_case(const case_data& c){
	if(c.init_size==1)return c.motes_sizes.size();

	std::vector<int> sorted_sizes=c.motes_sizes;
	std::sort(sorted_sizes.begin(), sorted_sizes.end());

	int curr_size=c.init_size;
	int sorted_i=0;
	while(sorted_i<sorted_sizes.size() && curr_size>sorted_sizes[sorted_i]){curr_size+=sorted_sizes[sorted_i]; sorted_i++;}
	
	int min_op=sorted_sizes.size()-sorted_i;
	int curr_op=0;
	while(sorted_i<sorted_sizes.size()){
		while(curr_size<=sorted_sizes[sorted_i]){curr_op++;curr_size+=curr_size-1;}
		while(sorted_i<sorted_sizes.size() && curr_size>sorted_sizes[sorted_i]){curr_size+=sorted_sizes[sorted_i]; sorted_i++;}
		if(curr_op+sorted_sizes.size()-sorted_i<min_op)min_op=curr_op+sorted_sizes.size()-sorted_i;
	}
	return min_op;
}

int main(){
	parse_input(std::cin);
	for(int i=0;i<cases.size();i++){
		std::cout<<"Case #"<<i+1<<": "<<solve_case(cases[i])<<std::endl;
	}

	return 0;
}
