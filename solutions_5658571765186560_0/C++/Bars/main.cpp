#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#include <memory.h>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

const int MAX = 1005;


int main()
{
	ifstream in ("in.in");
	ofstream out ("out.txt");

	int T;

	in >> T;


	for (int t = 1; t <= T; ++t) 
	{
		out << "Case #" << t << ": ";

		int X, R, C;

		in >> X >> R >> C;

		if (X >= 7)
			out << "RICHARD" << endl;
		else if (X == 1)
			out << "GABRIEL" << endl;
		else if ((R * C) % X != 0)
			out << "RICHARD" << endl;
		else 
		{
			if (X == 2)
				out << "GABRIEL" << endl;
			else if (X == 3)
			{
				if (C == 1 || R == 1)
					out << "RICHARD" << endl;
				else 
					out << "GABRIEL" << endl;
			}
			else 
			{
				if (C < 3 || R < 3)
					out << "RICHARD" << endl;
				else 
					out << "GABRIEL" << endl;
			}
		}

	}

	out.close();
	return 0;
}

void solve()
{

}