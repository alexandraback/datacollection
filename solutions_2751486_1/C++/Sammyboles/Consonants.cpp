#include <iostream>
#include <fstream>
#include <string>
using namespace std;

long long countn(string &, long long);

int main()
{
	ifstream in;
	ofstream out;
	long long T;
	long long i;
	long long nval;
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

long long countn(string & name, long long n)
{
	long long ncount = 0;
	long long nval = 0;
	long long i, j, temp, counter;
	temp = 0;
	long long temp2 = 0;
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