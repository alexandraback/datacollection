#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <algorithm>
#include <vector>

//not the last row - always cheat
int to_fill(int C, int W){
	return C / W;
}

int to_sink(int C, int W){
	int res = (C/W) + W-1 ;

	int penalty = 0;
	if(C%W != 0){
		penalty += 1;
	}
	

	return res + penalty;
}

void solve(int num, std::ifstream& input, std::ofstream& output){
	int R,C,W;

	input >> R;
	input >> C;
	input >> W;

	
	int res = 0;
	if(R > 1){
		res += to_fill(C, W) * (R-1);
	}
	res += to_sink(C, W);

	//std::cout << "Case #" << num << ": " << res << std::endl;
	output << "Case #" << num << ": " << res << std::endl;
}


int main(int argc, char *argv[]){
	if(argc!=3){
		std::cout << "wrong number of arguments";
		return 1;
	}

	std::ifstream file_input (argv[1]);
	if (!file_input.is_open()){
		std::cout << "unable to open the input file";
		return 1;
	}

	std::ofstream file_output (argv[2]);
	if (!file_output.is_open()){
		std::cout << "unable to open the input file";
		return 1;
	}

	int n_tests = 0;
	file_input >> n_tests;

	std::cout << "#tests: " << n_tests << std::endl;

	for(int i = 0; i < n_tests; ++i){
		solve(i+1,file_input,file_output);
	}

}