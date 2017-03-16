// code_jam_practice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& str, const vector<T> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i) << ", ";
	}
	str << "]";
	return str;
}

template<typename T>
ostream& operator<<(ostream& str, const vector<pair<T,T>> &v)
{
	str << "[";
	for (int i = 0; i < v.size(); i++)
	{
		str << v.at(i).first << "-" << v.at(i).second << ", ";
	}
	str << "]";
	return str;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	ifstream ifs("B-small-0.in", ifstream::in);
	ofstream ofs("B-small-0.out", ifstream::out);
	ifs >> T;
	for (int i = 0; i < T; i++)
	{
		double C, F, X;
		ifs >> C >> F >> X;

		double min = numeric_limits<double>::max();
		int farm_count = 0;
		double last = 0;
		while (true)
		{
			double temp = last + X / (F*farm_count + 2);
			if (temp > min) break;

			last += C/ (F*farm_count+2);
			min = temp;
			farm_count++;
		}

		ofs << "Case #" << i+1<< ": " << fixed << setprecision(7) << min << endl;
	}
	system("pause");
	return 0;
}

