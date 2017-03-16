#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;




void main() {



	ifstream in;
	ofstream out;
	out.open("out.txt");
	in.open("input.txt");
	int T;

	string str;
	int n;
	int count,nval;
	int b,e;


	in >> T;

	for (int i=0; i<T; i++)
	{
		in >> str >> n;
		nval=0;
		for (b=0;b<str.length();b++)
		{
			count=0;
			for (e=b;e<str.length();e++)
			{
				if (str.c_str()[e] == 'e' ||str.c_str()[e] == 'i' ||str.c_str()[e] == 'a' ||str.c_str()[e] == 'u' ||str.c_str()[e] == 'o' )
					count=0;
				else
				{
					count++;
					if (count>=n)
					{
						nval+=str.length()-e;
						break;
					}
				}
			}
		}




		out << "Case #" << i+1 << ": " << nval << endl;
	}

	in.close();
	out.close();

}
