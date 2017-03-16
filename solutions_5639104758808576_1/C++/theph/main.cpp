#include <fstream>
#include <iostream>

void solve_case()
{
	int Smax;
	std::cin >> Smax;
	char Si;
	int answer = 0;
	int standing = 0;
	
	for(int i = 0; i <= Smax; ++i)
	{
		std::cin >> Si;
		Si -= '0';
		if( i > standing )
		{
			++answer;
			++standing;
		}
		
		standing += Si;
	}
	
	std::cout << answer;
	
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("A-large.in", "r", stdin);		//input file
	freopen ("A-large.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}