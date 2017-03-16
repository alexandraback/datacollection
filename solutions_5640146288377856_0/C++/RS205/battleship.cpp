#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <sstream>
#include<string>

int main(){

	std::string readln;
	std::ifstream input;
	std::ofstream output;
	int num_tests;	
	int ans;
	int rows;
	int cols;
	int width;

	input.open("A-small-attempt1.in");
	output.open("output2.txt");

	input >> readln;
	num_tests = atoi(readln.c_str());


	for (int case_num = 1; case_num <= num_tests; case_num++){

		input>>readln;
		rows = atoi(readln.c_str());

		input>>readln;
		cols = atoi(readln.c_str());

		input>>readln;
		width = atoi(readln.c_str());

		if (cols == width) {
			ans =  width;
		}
		else if(width+1 == cols){
			ans = cols;
		}
		else{
			int num_remaining = cols/width;
			num_remaining = cols - width*(num_remaining-1);
			if (num_remaining > width){
				ans = cols/width+width;
			}
			else{
				ans = cols/width+width-1;
			}
		}


		output<<"Case #"<<case_num<<": " <<ans<<std::endl;
	}

	input.close();
	output.close();

	return 0;
}
