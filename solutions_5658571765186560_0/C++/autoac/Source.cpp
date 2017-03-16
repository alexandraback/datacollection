#include <iostream>
#include <vector>
#include <algorithm>
#include<fstream>
using namespace std;

int main()
{
	//ifstream file1("sample.txt");
	ifstream file1 ("D-small-attempt0.in");
	ofstream file2 ("D-large.txt");
	int T; file1 >> T;
	for (int t = 1; t <= T; t++)
	{
		int a, s, d;
		file1 >> a >> s >> d;
		file2 << "Case #" << t << ": ";
		if (a == 1)
			file2 << "GABRIEL";
		else if (a == 2)
		{
			if (((s*d) & 1) == 0)
				file2 << "GABRIEL";
			else
				file2 << "RICHARD";
		}
		else if (a==3)
		{ if ((s*d)>3 && ((s*d)%3)==0)
		file2 << "GABRIEL";
		else
			file2 << "RICHARD";
		}
		else
		{ if (s*d==12||s*d==16)
		file2 << "GABRIEL";
		else
			file2 << "RICHARD";
		}
		file2 << endl;
	}
	return 0;
}

