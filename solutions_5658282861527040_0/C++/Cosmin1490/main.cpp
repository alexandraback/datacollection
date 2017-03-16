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


vector<int> compute(string& str)
{
	vector<int> res;

	char prev = str[0];
	res.push_back(1);

	for(int i = 1; i < str.size(); i++)
	{
		if(str[i] == prev)
		{
			res[res.size() -1]++;
		}
		else
		{
			res.push_back(1);
			prev = str[i];
		}
	}
	return res;
}

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
	
		int A, B, K;
		long long Sol = 0;
		fin >> A >> B >> K;
		for(int i = 0; i < A; i++)
		{
			for(int j = 0; j < B; j++)
			{
				if((i & j)  < K)
				{
					Sol++;
				}
			}
		}

		fout << "Case #" << t <<": ";
		fout << Sol;
		fout << "\n";
		
	}


#ifdef ONLINE_JUDGE
#else
    fout.close();
	fin.close();
#endif
}
