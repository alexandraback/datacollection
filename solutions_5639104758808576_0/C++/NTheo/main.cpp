#include <algorithm>
#include <fstream>
#include <string>

int main()
{
	int T;
	std::ifstream input("A-small-attempt1.in");
	std::ofstream output("A-small-attempt1.out");
	input >> T;
	for (int i = 0; i < T; i++)
	{
		int Smax;
		std::string shy;
		input >> Smax >> shy;
		int numberWhoStand = 0;
		int wj = 0;
		for (int j = 0; j < Smax; j++)
		{
			numberWhoStand += int(shy[j] - '0');
			wj = std::max(wj, j + 1 - numberWhoStand);
		}
		output << "Case #" << (i + 1) << ": " << wj << std::endl;
	}
	return 0;
}