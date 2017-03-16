#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iterator>
#include <assert.h>
#include <math.h>
using namespace std;

const string file = "file";

const string infile = file + ".in";
const string outfile = file + ".out";

const int INF = 0x3f3f3f3f; 
const int MODN = 666013;
const double EPS = 0.0000001;

//#define ONLINE_JUDGE


int main()
{
#ifdef ONLINE_JUDGE
	ostream &fout = cout;
	istream &fin = cin;
#else
	fstream fin(infile.c_str(), ios::in | ios::binary);
	fstream fout(outfile.c_str(), ios::out);
#endif	
	
	int T;
	fin >> T;
	for(int t = 1; t <= T; t++)
	{
		int Sol = INF;


		int N, M, K;
		fin >> N >> M >> K;


		if( N >= 3 && M >= 3)
		{
			for(int i = 1; i < N - 1; i++)
			{
				for(int j = 1; j < M - 1; j++)
				{
					if(i * j + 2 * (i + j) >= K)
					{
						Sol = min(Sol, (2 * (i + j)));
					}
				}
			}
		}
		else
		{
			Sol = K;
		}

		if(Sol == INF)
		{
			Sol = 2 * (N - 2 + M - 2) + (K - (N - 2) * (M - 2)  - 2 * (N - 2 + M - 2));
		}

		fout << "Case #" << t << ": ";
		fout << Sol;
		fout << "\n";

	}

#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
