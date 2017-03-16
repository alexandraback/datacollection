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

	int x,y;
	int j;
	in >> T;

	for (int i=0; i<T; i++)
	{

		in >> x >> y;
		out << "Case #" << i+1 << ": ";

		if (x>0)
		{
			for (j=0;j<x;j++)
				out << "WE";
		}
		else
		{
			for (j=x;j<0;j++)
				out << "EW";
		}	

		if (y>0)
		{
			for (j=0;j<y;j++)
				out << "SN";
		}
		else
		{
			for (j=y;j<0;j++)
				out << "NS";
		}	

		out << endl;

		
	}

	in.close();
	out.close();

}
