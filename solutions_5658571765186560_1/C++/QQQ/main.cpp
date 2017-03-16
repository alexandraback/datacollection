#include <iostream>

const char* G = "GABRIEL";
const char* R = "RICHARD";
void GWinsIf(int iCase, bool win)
{
	std::cout<<"Case #" << iCase << ": " << (win ? G : R) << std::endl;
}
void GWins(int iCase)
{
	GWinsIf(iCase, true);
}
void RWins(int iCase)
{
	GWinsIf(iCase, false);
}

int main()
{
	int numCases = 0;
	std::cin >> numCases;

	for (int iCase = 1; iCase <= numCases; iCase++)
	{
		int X, R, C;
		std::cin >> X >> R >> C;

		if ((R * C % X != 0) || (R * C < X) || (X >= 7))
		{
			RWins(iCase);
			continue;
		}

		switch (X)
		{
			case 1:
				GWins(iCase);
				break;
			case 2:
				GWins(iCase);
				break;
			case 3:
				GWinsIf(iCase, (R%3==0 && C>=2) || (C%3==0 && R>=2));
				break;
			case 4:
				GWinsIf(iCase, (R>=4 && C>=3) || (C>=4 && R>=3));
				break;
			case 5:
				GWinsIf(iCase, (R%5==0 && C>=4) || (C%5==0 && R>=4));
				break;
			case 6:
				GWinsIf(iCase, (R>=6 && C>=4) || (C>=6 && R>=4));
				break;
		}
	}

	return 0;
}