#include <fstream>
using namespace std;

int main()
{
	ifstream input("f.txt");
	ofstream output("out.txt");
	int test_cases;
	input >> test_cases;
	for (int test = 1; test <= test_cases; test++)
	{
		int X,Y;
		input >> X >> Y;
		output << "Case #" << test << ": ";
		//handle X
		//if (X == 1) output << "E";
		//else if (X == -1) output << "W";
		if (X >= 1) 
		{
			for (int i = 0 ; i < X; i++)
				output << "WE";
		}
		else
		{
			for (int i = 0 ; i < X*(-1); i++)
				output << "EW";
		}
		//handle Y
		//if (Y == 1) output << "N";
		//else if (Y == -1) output << "S";
		if (Y >= 1) 
		{
			for (int i = 0 ; i < Y; i++)
				output << "SN";
		}
		else
		{
			for (int i = 0 ; i < Y*(-1) ; i++)
				output << "NS";
		}
		output << endl;
	}
	output.close();
	system("PAUSE");
	return 0;
}