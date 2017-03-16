#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	ifstream fin;
	fin.open("D-small-attempt0.in");
	if (fin.is_open())
	{
		ofstream fout;
		fout.open("D-small-attempt0.out");
		int T;
		fin >> T;
		for (int i = 0; i < T; i++)
		{
			int K, C,S;
			fin >> K;
			fin >> C;
			fin >> S;
			cout << "Case #" << i + 1 << ":";
			for (int j = 0; j < K; j++) cout << " " << j+1;
			cout << endl;
			fout << "Case #" << i + 1 << ":";
			for (int j = 0; j < K; j++) fout << " " << j+1;
			fout << endl;
		}
		fin.close();
		fout.close();
	}
	return 0;
}