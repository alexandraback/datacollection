//NTheo 2015

//So I thought it was faster to do this one by hand
//Now I've done it I don't think so anymore.

//Basically for X >= 7 answer is trivially Richard.
//Then Gabriel wins => X divides RC and you figure out all the cases.

//problem is, absence of real test cases makes it difficult to test
//algorithm or to know if solution by hand is correct

#include <algorithm>
#include <fstream>
#include <string>

int main(int, char**)
{
	std::string GABRIELA = "GABRIEL";
	std::string RICARDO = "RICHARD";
	std::ifstream input("D-large.in");
	std::ofstream output("D-large.out");
	int T;
	input >> T;
	for (int t = 0; t < T; t++)
	{
		output << "Case #" << (t + 1) << ": ";
		int X; int R; int C;
		input >> X >> R >> C;
		int m = std::min(R, C);
		switch (X)
		{
		case 1:
			output << GABRIELA;
			break;
		case 2:
			output << ((((C*R) % 2)==0) ? GABRIELA : RICARDO);
			break;
		case 3:
			if (((R*C) % 3) == 0 && m > 1)
				output << GABRIELA;
			else
				output << RICARDO;
			break;
		case 4:
			if (((R*C) % 4) == 0 && m > 2)
				output << GABRIELA;
			else
				output << RICARDO;
			break;
		case 5:
			if (((R*C) % 5) == 0 && (m > 3 || R + C == 8))
				output << GABRIELA;
			else
				output << RICARDO;
			break;
		case 6:
			if (((R*C) % 6) == 0 && m > 3)
				output << GABRIELA;
			else
				output << RICARDO;
			break;
		default:
			output << RICARDO;
			break;
		}
		output << std::endl;
	}
	return 0;
}

