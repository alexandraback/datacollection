#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

int main()
{
	ifstream in;
	ofstream out;
	in.open("problemB-small.txt");
	out.open("problemB-small-result.txt");

	int T;
	in >> T;
	for(int t = 1; t <= T; t++)
	{
		int N, X, Y;
		in >> N >> X >> Y;

		out << "Case #" << t << ": ";
		out << fixed << showpoint << setprecision(8);
		X = abs(X);

		if(X == 0 && Y == 0) out << 1.0;
		else if(X == 2 && Y == 0)
		{
			if(N == 1) out << 0.0;
			else if(N == 2) out << 0.5;
			else if(N == 3) out << 0.75;
			else out << 1.0;
		}
		else if(X == 1 && Y == 1)
		{
			if(N < 3) out << 0.0;
			else if(N == 3) out << 0.25;
			else if(N == 4) out << 0.5;
			else out << 1.0;

		}
		else if(X == 0 && Y == 2)
		{
			if(N < 6) out << 0.0;
			else out << 1.0;
		}
		else if(X == 4 && Y == 0)
		{
			if(N < 7) out << 0.0;
			else if(N == 7) out << 0.5;
			else if(N == 8) out << 0.75;
			else if(N == 9) out << 0.875;
			else if(N == 10) out << 0.9375;
			else out << 1.0;
		}
		else if(X == 3 && Y == 1)
		{
			if(N < 8) out << 0.0;
			else if(N == 8) out << 0.25;
			else if(N == 9) out << 0.5;
			else if(N == 10) out << 0.6875;
			else if(N == 11) out << 5.0/6;
			else out << 1.0;
		}
		else if(X == 2 && Y == 2)
		{
			if(N < 9) out << 0.0;
			else if(N == 9) out << 0.125;
			else if(N == 10) out << 0.3125;
			else if(N == 11) out << 0.5;
			else if(N == 12) out << 0.7;
			else out << 1.0;
		}
		else if(X == 1 && Y == 3)
		{
			if(N < 10) out << 0.0;
			else if(N == 10) out << 0.0625;
			else if(N == 11) out << 1.0/6;
			else if(N == 12) out << 0.3;
			else if(N == 13) out << 0.5;
			else out << 1.0;
		}
		else if(X == 0 && Y == 4)
		{
			if(N < 15) out << 0.0;
			else out << 1.0;
		}
		else if(X == 6 && Y == 0)
		{
			if(N < 16) out << 0.0;
			else if(N == 16) out << 0.5;
			else if(N == 17) out << 0.75;
			else out << 1.0;
		}
		else if(X == 5 && Y == 1)
		{
			if(N < 17) out << 0.0;
			else if(N == 17) out << 0.25;
			else if(N == 18) out << 0.5;
			else if(N == 19) out << 0.6875;
			else if(N == 20) out << 0.8125;
			else out << 1.0;
		}
		else if(X == 4 && Y == 2)
		{
			if(N < 18) out << 0.0;
			else if(N == 18) out << 0.125;
			else if(N == 19) out << 0.3125;
			else if(N == 20) out << 0.5;
			else out << 1.0;
		}
		else if(X == 3 && Y == 3)
		{
			if(N < 19) out << 0.0;
			else if(N == 19) out << 0.0625;
			else if(N == 20) out << 0.1875;
			else if(N == 21) out << 21.0/62;
			else if(N == 22) out << 0.5;
			else out << 1.0;
		}
		else if(X == 2 && Y == 4)
		{
			if(N < 20) out << 0.0;
			else if(N == 20) out << 0.03125;
			else if(N == 21) out << 2.0/31;
			else if(N == 22) out << 0.1875;
			else if(N == 23) out << 4.0/13;
			else out << 1.0;
		}
		else out << 0.0;

		out<< endl;
	}

	in.close();
	out.close();

	return 0;
}