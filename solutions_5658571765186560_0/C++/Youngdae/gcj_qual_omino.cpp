#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin("D-small-attempt0.in");
ofstream fout("output.txt");

int main()
{
	int tt, ti;
	fin >> tt;

	for(ti=1; ti<=tt; ti++)
	{
		fout << "Case #" << ti << ": ";
		////////////////////////////////////////////////////

		int x, l, s;
		string r="RICHARD\n", g="GABRIEL\n";

		fin >> x >> l >> s;
		if(s>l)
			swap(l,s);

		if((l*s)%x)
		{
			fout << r;
			continue;
		}

		switch(x)
		{
		case 1:
			fout << g;
			break;

		case 2:
			if(l>=2)
				fout << g;
			else
				fout << r;
			break;

		case 3:
			if(l>=3 && s>=2)
				fout << g;
			else
				fout << r;
			break;

		case 4:
			if(l>=4 && s>=3)
				fout << g;
			else
				fout << r;
			break;

		case 5:
			if(l>=5 && s>=4)
				fout << g;
			else
				fout << r;
			break;

		case 6:
			if(l>=6 && s>=4)
				fout << g;
			else
				fout << r;
			break;

		default:
			fout << r;
			break;
		}
	}

	return 0;
}