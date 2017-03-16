#include<iostream>
#include<fstream>
#include<stdlib.h>
#include <sstream>
#include<string>

long long reverse(long long a){
	long long ans = 0;
	long long tens = 1;
	long long anti_ten = 1;
	while(a/tens > 0){
		tens*=10;	
	}
	tens/=10;
	//std::cout<<tens<<std::endl;
	while(tens > 0){
		long long temp = tens*10;
		temp = a/temp;
		temp = a/tens-10*temp;
		//std::cout<<"digit 1 "<<temp<<std::endl;
		temp = temp*anti_ten;
		//std::cout<<"convertted digit 1 "<<temp<<std::endl;
		ans+=temp;
		//std::cout<<ans<<std::endl;
		tens/=10;
		anti_ten*=10;
	}
	return ans;

}

int main(){

	std::string readln;
	std::ifstream input;
	std::ofstream output;
	long long num_tests;
	long long testing_num;	
	long long num_steps;
	long long ans;

	input.open("A-small-attempt0.in");
	output.open("output.txt");

	input >> readln;
	num_tests = std::stoll(readln);


	for (int case_num = 1; case_num <= num_tests; case_num++){

		input>>readln;
		testing_num= std::stoll(readln);
		num_steps = 0;

		while(testing_num>0){
			long long reverse_num = reverse(testing_num);
			if (testing_num != reverse(reverse_num)){
				reverse_num = testing_num-1;
			}
			if(testing_num-1 < reverse_num){
				testing_num = testing_num-1;
			}
			else{
				testing_num = reverse_num;
			}
			//std::cout<<testing_num<<std::endl;
			num_steps++;
		}

		output<<"Case #"<<case_num<<": " <<num_steps<<std::endl;
	}

	input.close();
	output.close();

	return 0;
}
