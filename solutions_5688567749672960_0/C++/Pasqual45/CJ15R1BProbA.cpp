#include<fstream>
#include<iostream>
#include<sstream>
#include<iomanip>
#include<string>
#include<vector>
#include<list>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<functional>
#include<numeric>
#include<bitset>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define mp make_pair

namespace
{
	int rev(int x)
	{
		int ret(0);
		while (x)
		{
			ret *= 10;
			ret += x % 10;
			x /= 10;
		}
		return ret;
	}

	const static int INF = 0x1f1f1f1f;
	const static int MAXVAL = 1000000;
	int v[MAXVAL + 2];


	void solve(int myMax)
	{
		queue<int> q;
		q.push(1);
		v[1] = 1;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			int thisT = v[cur];

			if (v[cur + 1] == INF && cur+1 <= myMax)
			{
				v[cur + 1] = thisT + 1;
				q.push(cur + 1);
			}

			int myRev = rev(cur);
			if (v[myRev] == INF && myRev <= myMax)
			{
				v[myRev] = thisT + 1;
				q.push(myRev);
			}
		}
	}
}

//int main15R1B_A()
int main()
{
	memset(v, INF, sizeof(v));
	solve(MAXVAL);

	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	//ifstream fin("test.in");
	//ofstream fout("test.out");

	unsigned int numberOfCases;
	fin >> numberOfCases;

	for (unsigned int zz = 1; zz <= numberOfCases; ++zz)
	{
		int x;
		fin >> x;

		int result = v[x];
		fout << "Case #" << zz << ": " << result << endl;
	}

	return 0;
}
