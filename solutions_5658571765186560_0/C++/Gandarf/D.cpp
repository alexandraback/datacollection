#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int testn;
int x, r, c;

int main()
{
	//ifstream in("input.txt");
	ifstream in("D-small-attempt1.in");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		in >> x >> r >> c;

		string who = "";

		if (x >= 4)
		{
			if (r * c >= 4 * 3 && (r >= 4 || c >= 4))
				who = "GABRIEL";
			else
				who = "RICHARD";
		}
		else if (x == 3)
		{
			if (r * c > 3 && (r * c) % 3 == 0)
				who = "GABRIEL";
			else
				who = "RICHARD";
			/*
			if ((r * c) % 3 != 0)
				who = "RICHARD";
			else
			{
				if ((r * c) % 2 == 0)
					who = "GABRIEL";
				else
					who = "RICHARD";
			}
			*/
		}
		else if (x == 2)
		{
			if ((r * c) % 2 == 0)
				who = "GABRIEL";
			else
				who = "RICHARD";
		}
		else
			who = "GABRIEL";

		out << "Case #" << test << ": " << who << endl;
	}

	in.close();
	out.close();
	return 0;
}