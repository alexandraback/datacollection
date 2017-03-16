#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <deque>
#include <map>
#include <set>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <sstream>
#include <cstring>
#include <bitset>
#include <climits>

using namespace std;
#define  AS(arr)  (sizeof(arr)/sizeof(arr[0]))
#define ALL(c) (c).begin(),(c).end() 
#define SIZE(a) int((a).size())
#define EACH(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define REP(i,n) for(int i=0;i<(int)n;++i)
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;


		int M[1000][10];
		int MN[1000];

int p;

void path(int s, int e)
{
	REP(i, MN[s])
	{
		if(M[s][i] == e)
		{
			p++;
		}
		else
		{
			path(M[s][i], e);
		}
	}
}


int main()
{
	int testcases;
	cin >> testcases;

	REP(testcase, testcases)
	{
		
		int N;
		cin >> N;
		

		REP(i, N)
		{
			cin >> MN[i];
			REP(j, MN[i])
			{
				cin >> M[i][j];
				M[i][j]--;
			}
		}

		string ret = "No";

		REP(i, N)
		{
			REP(j, N)
			{
				p = 0;
				path(i, j);
				
				/*
				if(p >= 1)
				{
					printf("%d: %d,%d\n", p, i, j);
				}
				*/

				if(p >= 2)
				{
					ret = "Yes";
					goto AAA;

				}
				
			}
		}
AAA:
	
		cout << "Case #" << testcase+1 << ": " << ret << endl;
	}
	return 0;
}
