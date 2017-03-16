#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
	int t, smax = 0;
	ifstream infile("small.in");
	ofstream outfile("small.out");
	infile >> t;

	for (int index = 0; index < t; index++)
	{
		int x, r, c;
		bool richardwin= false;
		infile >> x >> r >> c;
		if (x >= 7)richardwin = true;
		else if (x>max(r, c))richardwin = true;
		else if ((x + 1) / 2 > min(r, c))richardwin = true;
		else if (r*c%x != 0)richardwin = true;
		else
		{
			if (x == 1 || x == 2 || x == 3);
			else if (x == 4){ if (min(r, c) == 2)richardwin = true; }
			else if (x == 5){ if (min(r, c) == 3 && max(r, c) == 5)richardwin = true; }
			else if (x == 6){ if (min(r, c) == 3)richardwin = true; }
		}
		string str;
		if (richardwin)str = "RICHARD"; else str = "GABRIEL";
		outfile << "Case #" << index + 1 << ": " << str<< endl;
	}
	infile.close();
	outfile.close();
	return 0;
}