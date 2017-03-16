#include <fstream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <utility>
#include <cmath>
#include <functional>
#include <stack>
#include <set>

using namespace std;

const int mtable[4][4] =	{	{1, 2, 3, 4},
								{2,-1, 4,-3},
								{3,-4,-1, 2},
								{4, 3,-2,-1}
							};

int ctoi(char ch) 
{
	switch (ch)
	{
		case 'i' : return 2;
		case 'j' : return 3;
		case 'k' : return 4;
	}
	return 1;
} 

int prefix[100000];
int suffix[100000];

int mult(int i, int j)
{
	int res = mtable[abs(i)-1][abs(j)-1];
	if ((i < 0) ^ (j < 0))
	{
		res = -res;
	}
	return res;
}

const int M = 4;

int main()
{
	ifstream ifs("c.in");
	ofstream ofs("c.out");
	int t;
	ifs >> t;
	for (int test = 0; test < t; ++test)
	{
		long long n, x;
		string s;
		ifs >> n >> x >> s;
		string t;
		for (int i = 0; i < M*2; ++i)
		{
			t += s;
		}
		int prev = 1;
		for (int i = 0; i < n*M*2; ++i)
		{
			prefix[i] = mult(prev, ctoi(t[i]));
			prev = prefix[i];
		}
		prev = 1;
		for (int i = 0; i < n*M*2; ++i)
		{
			suffix[i] = mult(ctoi(t[t.size()-1-i]), prev);
			prev = suffix[i];
		}

		bool ok = false;
/*		for (int i = 0; (i < n*M) && !ok; ++i)
		{
			if (prefix[i] == 2)
			{
				for (int j = 0; j < n*M; ++j)
					if (i+j+2 < n*x && suffix[j] == 4)
					{
						long long realj = n*x-j-1;
						if (i / n == realj / n)
						{
							if (mult(prefix[i % n], 3) == prefix[(realj % n)-1])
							{
								ok = true;
								break;
							}
						}
						else 
						{
							long long fi = i % n;
							long long fj = j % n;
							long long res = 1;
							if (fi+1 < n)
								res = suffix[n - fi - 2];
							long long cnt = (realj / n) - (i / n) - 1;
							if (cnt > 0)
								res = mult(res, prefix[n * (cnt % M) - 1]);
							if (fj+1 < n)
								res = mult(res, prefix[n - fj - 2]);
							if (res == 3)
							{
								ok = true;
								break;
							}
						}
					}
			}
		}
*/
		int all = 1;
		for (int i = 0; i < x % 4; ++i)
		{
			all = mult(all, prefix[n-1]);
		}
		for (int i = 0; i < min(n*M, n*x) && !ok; ++i)
		{
			if (prefix[i] == 2)
			{
				for (int j = i+1; j < min(n*x-1, i+n*M+1); ++j)
				{
					if (prefix[j] == 4)
					{
						if (all == -1)
						{
							ok = true;
							break;
						}

					}
				}
			}
		}
		ofs << "Case #" << test+1 << ": " << (ok ? "YES" : "NO") << endl;
	}
	return 0;
}
