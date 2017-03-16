#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int countn(string &, int);

int main()
{
	ifstream in;
	ofstream out;
	int T;
	int i;
	int nval;
	string x;
	in.open("Asm1.in");
	out.open("out");
	in >> T;
	for (i = 0; i < T; i++)
	{
		in >> x;
		in >> nval;
		out << "Case #" << i + 1 << ": " << countn(x, nval) << '\n';
	}
	return 0;
}

int countn(string & name, int n)
{
	int ncount = 0;
	int nval = 0;
	int i, j, temp, counter;
	temp = 0;
	int temp2 = 0;
	counter = 0;
	for(j = 0; j < name.length(); j++)
	{
		switch(name[j])
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			{
				counter = 0;
				break;
			}
			default:
			{
				counter++;
				break;
			}
		}
		if (counter == n)
		{
			temp = j - ( n - 2 );
			nval += (temp - temp2) * (name.length() - j);
			temp2 = temp;
			ncount++;
			counter--;
		}
	}
	return nval;
}