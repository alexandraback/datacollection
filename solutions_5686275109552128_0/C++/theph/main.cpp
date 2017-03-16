#include <fstream>
#include <iostream>
#include <vector>

void solve_case()
{
	unsigned int D;
	std::cin >> D;
	std::vector<unsigned int> P(D);
	for(unsigned int i = 0; i < D; ++i)
	{
		std::cin >> P[i];
	}
	
	long answer = 1000;
	for(int i = 1; i < answer; ++i)
	{
		long temp_answer = 0;
		for(int j = 0; j < D; ++j)
		{
			temp_answer += (P[j] - 1) / i;
		}
		temp_answer += i;
		if(temp_answer < answer)
			answer = temp_answer;
	}
	std::cout << answer;
	
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("B-small-attempt0.in", "r", stdin);		//input file
	freopen ("B-small-attempt0.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}