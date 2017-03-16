#include <iostream>
#include <fstream>
#include <vector>

//#define test
//#define small 
#define large

void solve()
{
	short R, C, W;
	std::cin >> R >> C >> W;
	//std::vector<std::vector<
	short per_row = C / W;
	if (per_row == 0)
		per_row = 1;
	int minimum_score = 0;
	minimum_score += per_row * R;
	short right_over = C % W;
	if (right_over > 0)
		minimum_score++;
	minimum_score += (W - 1);
	std::cout << minimum_score << std::endl;
}

int main()
{
#if defined(test)
	std::ifstream in("in.in");
#elif defined(small)
	std::ifstream in("A-small-attempt1.in");
#elif defined(large)
	std::ifstream in("A-large.in");
#endif
	std::cin.rdbuf(in.rdbuf());
	std::ofstream out("out.out");
	std::cout.rdbuf(out.rdbuf());

	short T;
	std::cin >> T;
	
	for (short i = 1; i <= T; i++)
	{
		std::cout << "Case #" << i << ": ";
		solve();
	}
}