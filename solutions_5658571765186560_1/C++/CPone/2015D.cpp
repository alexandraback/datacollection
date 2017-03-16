#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

bool RICHARD(int X, int R, int C)
{
	if (X > 6)
		return true;
	if (X == 1)
		return false;
	if (X == 2)
		return (R*C % 2 != 0);
	if (R > C)
		std::swap(R, C);
	if (X == 3)
		return (R*C % 3 != 0) || R < 2;
	if (X == 4)
		return (R*C % 4 != 0) || R < 3;
	if (X == 5)
		return (R*C % 5 != 0) || R < 3 || (R == 3 && C == 5);
	else // (X == 6)
		return (R*C % 6 != 0) || R < 4;
}

int main(int argc, char *argv[])
{
	std::ifstream in(argv[1]);
	std::ofstream out(argv[1] + std::string(".out"));

	int T;
	in >> T;
	for (int x = 1; x <= T; ++x)
	{
		out << "Case #" << x << ": ";

		int X, R, C;
		in >> X >> R >> C;

		if (RICHARD(X, R, C))
		{
			out << "RICHARD" << "\n";
		}
		else
		{
			out << "GABRIEL" << "\n";
		}
	}
}