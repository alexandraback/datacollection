

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <deque>
#include <fstream>
#include <limits>


#define Long unsigned long long
#define pi pair <int, int>
#define Point pair <double, double>
#define vi vector < int >
#define vvi vector < vi >
#define vpi vector < pi >
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define forall(i,n) for( int i = 0; i < n; ++i )
#define Forall(i,a,b) for( int i = a; i < b; ++i )
#define pb push_back
#define mp make_pair

using namespace std;


ofstream out ("A.out");
ifstream in ("A.in");


int main (int argc, char const* argv[])
{
	bool pos[101];
	int a, sur[100], nsur[100], N, S, P, count;
	pos[0] = 0;
	sur[0] = 0;
	nsur[0] = 0;
	pos[1] = 0;
	sur[1] = 1;
	nsur[1] = 1;
	pos[29] = 0;
	sur[29] = 10;
	nsur[29] = 10;
	pos[30] = 0;
	sur[30] = 10;
	nsur[30] = 10;
	for (int i = 2; i < 29; i += 1)
	{
		pos[i] = true;
		if (i%3==0)
		{
			sur[i] = (i/3) + 1;
			nsur[i] = (i/3);
		}
		else if (i%3 == 1)
		{
			sur[i] = (i/3) + 1;
			nsur[i] = (i/3) + 1;
		}
		else
		{
			sur[i] = (i/3) + 2;
			nsur[i] = (i/3) + 1;
		}
	}
	
	int T;
	in >> T;

	for (int t = 1; t <= T; t += 1)
	{
		in >> N >> S >> P;
		count = 0;
		out << "Case #" << t << ": ";
		forall( i, N )
		{
			in >> a;
			if (nsur[a] >= P)
			{
				count++;
			}
			else if (sur[a] >= P && S > 0)
			{
				count++;
				S--;
			}
		}
		out << count << '\n';
	}
	return 0;
}


