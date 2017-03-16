// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream fi("a.in");
	ofstream fo("a.out");

	int t;
	fi >> t;

	for (int i = 0; i < t; i++)
	{
		int r, c, w;
		fi >> r >> c >> w;

		int min = r*(c/w) + w;
		if (c % w == 0) min -= 1;

		fo << "Case #" << i + 1 << ": " << min << endl;
	}

	fi.close();
	fo.close();

	return 0;
}
