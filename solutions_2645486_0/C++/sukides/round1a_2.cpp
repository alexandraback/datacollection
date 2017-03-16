// round1a.cpp : Defines the entry point for the console application.
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

int manage_energy(int E, int R, vector<int>& v)
{
	int ans = 0, N = v.size();
	if (E <= R)
	{
		for (int i = 0; i < v.size(); i++)
			ans += v[i];
		return E*ans;
	}
	else
	{
		vector<vector<int>> vt;
		vector<int> tmp(N, 0);
		for (int i = 0; i <= E; i++)
			vt.push_back(tmp);
		for (int i = R; i <= E; i++)
			vt[i][N-1] = v[N-1] * i;
		for (int k = N-2; k >= 0; k--)
		{
			for (int i = R; i <= E; i++)
			{
				for (int j = 0; j <= i; j++)
				{
					vt[i][k] = max(vt[i][k], v[k]*j+vt[min(E, i-j+R)][k+1]);
				}
			}
		}
		return vt[E][0];
	}
}

vector<int> parse_line(string line, int n)
{
	int p = 0, lp = 0;
	vector<int> v1;
	for (int k = 0; k < n; k++)
	{
		p = line.find(' ', lp);
		if (p == string::npos) p = line.length();
		v1.push_back(atoi(line.substr(lp, p-lp).c_str()));
		lp = p + 1;
	}
	return v1;
}

int main(int argc, char* argv[])
{
	ifstream in("B-small-attempt1.in");
	ofstream out("output.txt");
	string line;

	getline(in, line);
	int T = atoi(line.c_str());
	for (int i = 0; i < T; i++)
	{
		getline(in, line);
		vector<int> w = parse_line(line, 3);
		getline(in, line);
		vector<int> v = parse_line(line, w[2]);
		out << "Case #" << i+1 << ": " << manage_energy(w[0], w[1], v) << endl;
		cout << "\n" <<  i+1 << "\n";
	}
	getchar();
	return 0;
}
