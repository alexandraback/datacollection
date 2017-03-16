#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;


class solver 
{
public:

	void solve(int pos, int total, int nE)
	{
		if (pos == N)
		{
			if (total > max)
				max = total;
			return;
		}
		for (int i = 0; i <= nE; i++)
		{
			int nt= total + i * v[pos];
			int nnE = nE - i + R;
			if (nnE > E)
				nnE = E;
			solve(pos + 1,  nt, nnE);
		}
		return;
	}

	int max; 
	int E, R, N;
	vector<int> v;
};


int main()
{

	int T;


   ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\B-small-attempt2.in");

    //ifstream fin("C:\\Compete\\CodeJam1A\\CodeJam1A\\Text.txt");

    ofstream fout("C:\\Compete\\CodeJam1A\\CodeJam1A\\output.txt");

	fin >> T;
   
	for (int i=0; i < T; i++)
	{
		int  E, R, N;

		fin >> E >> R >> N;

		solver s; s.E = E; s.R = R; s.N = N; 
		s.max = 0; s.v.clear();
		for (int j=0; j < N; j++)
		{
			int c; fin >> c;
			s.v.push_back(c);
		}
		s.solve(0, 0, E);

		fout << "Case #" << i+1 <<  ": " << s.max << endl;
		
	}
	return 0;
} 