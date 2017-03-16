// round0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <utility>
#include <unordered_set>
#include <windows.h>

using namespace std;

int black_ring(int r, int t)
{
	int ans = -1, delta = 2*r+1;
	while (t >= 0)
	{
		t -= delta;
		delta += 4;
		ans ++;
	}
	return ans;
}

int main(int argc, char* argv[])
{
	ifstream in("A-small-attempt0.in");
	ofstream out("output.txt");
	string line;

	getline(in, line);
	int T = atoi(line.c_str());
	for (int i = 0; i < T; i++)
	{
		getline(in, line);
		int pos = line.find(' ');
		int r = atoi(line.substr(0, pos).c_str());
		int t = atoi(line.substr(pos+1).c_str());
		out << "Case #" << i+1 << ": " << black_ring(r, t) << endl;
		cout << "\n" <<  i+1 << "\n";
	}
	getchar();
	return 0;
}
