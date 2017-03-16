#include <fstream>

using namespace std;

int main()
{
	ifstream istr("test");
	ofstream ostr("out");
	int T;
	istr >> T;
	for(int casenum=1;casenum<=T;casenum++)
	{
		ostr << "Case #" << casenum << ": ";
		int X, R, C;
		istr >> X >> R >> C;

		if(X == 1)
		{
			ostr << "GABRIEL" << endl;
		}
		else if(X == 2)
		{
			if((R * C) % 2 == 0)
				ostr << "GABRIEL" << endl;
			else
				ostr << "RICHARD" << endl;
		}
		else if(X == 3)
		{
			if((R * C) % 3 == 0 && (R * C) / 3 != 1)
				ostr << "GABRIEL" << endl;
			else
				ostr << "RICHARD" << endl;
		}
		else
		{
			if((R * C) % 4 == 0 && (R * C) / 4 !=1 && (R * C) / 4 !=2)
				ostr << "GABRIEL" << endl;
			else
				ostr << "RICHARD" << endl;
		}
	}
	return 0;
}