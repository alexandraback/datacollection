// hehe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "windows.h"
#include <set>
#include <map>

using namespace std;


typedef unsigned __int64 uint64_t;


int _tmain(int argc, _TCHAR* argv[])
{
	unsigned int T = 0;
	cin >> T;
	for (int k = 0; k < T; ++k) {
		int x = 0;
		int y = 0;
		cin >> x >> y;
		cout << "Case #" << k+1 << ": ";
		std::string tt;
		if (x < 0)
			tt = "EW";
		else 
			tt = "WE";
		if (x<0)
			x = x*-1;
		for (int i = 0; i < x; i++)
			cout << tt;
		if (y < 0)
			tt = "NS";
		else 
			tt = "SN";
		if ( y < 0)
			y = y*-1;
		for (int i = 0; i < y; i++)
			cout << tt;
		cout << std::endl;
	}


	return 0;
}

