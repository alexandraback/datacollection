#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int testn;
int x, r, c;

int main()
{
	//ifstream in("input.txt");
	ifstream in("D-large.in");
	ofstream out("output.txt");

	in >> testn;
	for (int test = 1; test <= testn; ++test) 
	{
		in >> x >> r >> c;

		int rc = r * c;

		string who = "";

		if (x >= 7)
			who = "RICHARD";
		else if (x == 6) {
			if (rc % 6 == 0 && r >= 4 && c >= 4)
				who = "GABRIEL";
			else
				who = "RICHARD";
		}
		else if (x == 5) {
			if (rc % 5 == 0) {
				if ( (r == 3 && c % 5 == 0 && c >= 10) ||
					 (c == 3 && r % r == 0 && r >= 10))
					who = "GABRIEL";

				else if (r >= 4 && c >= 4)
					who = "GABRIEL";
				else 
					who = "RICHARD";
			}
			else
				who = "RICHARD";
		}
		else if (x == 4) {
			if (rc % 4 == 0 && r >= 3 && c >= 3)
				who = "GABRIEL";
			else
				who = "RICHARD";
		}
		else if (x == 3)
		{
			if (rc % 3 == 0 && r >= 2 && c >= 2)
				who = "GABRIEL";
			else
				who = "RICHARD";
		}
		else if (x == 2)
		{
			if (rc % 2 == 0)
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