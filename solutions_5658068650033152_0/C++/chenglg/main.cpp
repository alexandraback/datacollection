#ifdef __GNUC__
#include <ext/hash_map>
#include <ext/hash_set>
#else
#include <hash_map>
#include <hash_set>
#endif

namespace std
{
 using namespace __gnu_cxx;
}

#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <climits>
#include <iomanip> 
using namespace std;

typedef long long LL;
typedef long double LD;

string its(int n)
{
	string ret;
	if(n == 0)
	{
		ret = "0";
		return ret;
	}
	while(n > 0)
	{
		ret += (n % 10 + '0');
		n /= 10;
	}
	reverse(ret.begin() , ret.end());
	return ret;
}


int main()
{
//==============in put=================
	ifstream curFile("C-small-attempt0.in");
	vector<int> result;
	int T; // testcases count
	int N;
	int M;
	int K;
	int r;
	if(curFile.is_open())
	{
		curFile >> T;
		for(int c = 0 ; c < T ; c++)
		{
//==============solution==================
			curFile >> N;
			curFile >> M;
			curFile >> K;
			if(N > M)
				swap(N , M);
			if(N < 3)
				r = K;
			else if(K < 5)
				r = K;
			
			else if(N == 3)
			{
				int w = 0;
				if (M * N < K + 4)
				{
					w = M - 2;
					r = K - w;
				}
				else{
					int w = 0;
					w = (K -2) /3;
					r = K - w;
				}
			}
			else if (N == 4)
			{
				int w = 0;
				if(K <= 12)
				{
					if(K == 12)
						w = 4;
					else if (K == 11)
						w = 3;
					else if (K == 10)
						w = 3;
					else
						w = (K - 2) / 3;
				}
				else if (M == 4)
				{
					w = 4;
				}
				else if (M == 5)
				{
					if(K >= 16)
						w = 6;
					else if (K == 15 || K == 14)
						w = 5;
					else 
						w = 4;
				}
				r = K - w;
			} 
			result.push_back(r);
//==============solution end==============
		}	
	}
	curFile.close();
//==============out put==================
	ofstream outfile;
	outfile.open("result.txt");
	if(outfile.is_open())
	{
//		outFile << setprecision(6);
		for(int i = 0; i < result.size() ; i++)
			outfile << "Case #" << i + 1<< ": " <<result[i] << endl;
	}
	outfile.close();
	return 0;
}
