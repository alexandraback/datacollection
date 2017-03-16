#include <iostream>
#include <vector>

int main()
{
	int testCases;
	std::cin >> testCases;
	for (int t = 1; t <= testCases; ++t) {
		int rows, columns, width;
		std::cin >> rows >> columns >> width;
		int otherColumns = (rows - 1) * (columns / width);
		int lastColumn = (columns / width) - 1 + width;
		if (columns % width != 0) {
			++ lastColumn;
		}
		std::cout << "Case #" << t << ": " << otherColumns + lastColumn << std::endl;
	}
}
