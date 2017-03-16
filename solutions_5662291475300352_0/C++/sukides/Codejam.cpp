#include "stdafx.h"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

typedef unsigned int uint;

int hikers(vector<int> D, vector<int> M)
{
	int n = D.size();
	if (n==1) return 0;
	if (n==2)
	{
		double t0 = (1-D[0]/360.0)*M[0];
		double t1 = (1-D[1]/360.0)*M[1];
		if (t0>=t1+M[1] || t1>=t0+M[0])
			return 1;
		else
			return 0;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	ifstream in("C-small-1-attempt2.in");
	ofstream out("result.txt");
	int T, N;
	int d, h, m;
	in >> T;
	for (int i = 0; i < T; ++i)
	{
		in >> N;
		vector<int> D, M;
		for (int j = 0; j < N; ++j)
		{
			in >> d >> h >> m;
			for (int k = 0; k < h; ++k)
			{
				D.push_back(d);
				M.push_back(m+k);
			}
		}
		out << "Case #" << i+1 << ": " << hikers(D, M) << endl;
		cout << i+1 << endl;
	}

	in.close();
	out.close();
	return 0;
}