#include <fstream>
#include <iostream>

void solve_case()
{
	int R;
	int C;
	int W;
	int ans = 0;
	
	std::cin >> R;
	std::cin >> C;
	std::cin >> W;
	ans += (C / W) * R;
	
	if( C % W )
		ans += W;
	else
		ans += W - 1;
	
	std::cout << ans;
	return;
}

int main(int argc, char* argv[])
{
	unsigned T;
	
	freopen ("A-small-attempt0.in", "r", stdin);		//input file
	freopen ("A-small-attempt0.out", "w", stdout);		//output file
	std::cin >> T;
	for( int i = 0; i < T; ++i )
	{
		std::cout << "Case #" << i+1 << ": ";
		solve_case();
		std::cout << std::endl;
		
	}
	
	return 0;
}