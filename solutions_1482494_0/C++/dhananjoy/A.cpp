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
#include <set>


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
#define Forall(i,a,b) for( int i = a; i <= b; ++i )
#define pb push_back
#define mp make_pair

using namespace std;


ofstream out ("B.out");
ifstream in ("A.in");

bool mycomp ( pi a, pi b )
{
	return a.X < b.X;
}

int main (int argc, char const* argv[])
{
	int T, N;
	int P[1005], tot, G, last;
	bool done[1005], blah;
	pi A[1005];
	in >> T;
	for (int t = 0; t < T; t += 1)
	{
		in >> N;
		tot = 0;
		for (int i = 0; i < N; i += 1)
		{
			in >> A[i].X >> A[i].Y;
			done[i] = false;
			P[i] = 0;
		}
		sort(A, A+N, mycomp);
		G = 0;
		last = 0;
		while (tot < 2*N)
		{
			blah = false;
			for (int i = 0; i < N; i += 1)
			{
				if (!done[i])
				{
					if (A[i].Y <= tot)
					{
						tot += 2-P[i];
						done[i] = true;
						blah = true;
						G++;
						break;
					}
				}
			}
			if (!blah)
			{
				if (!done[last] && last < N && A[last].X <= tot)
				{
					P[last]=1;
					last++;
					tot++;
					G++;
				}
				else if ( last < N && done[last] )	last++;
				else	break;
			}	
		}
		if (tot == 2*N)
		{
			out << "Case #" << t+1 << ": " << G << '\n';
		}
		else	out << "Case #" << t+1 << ": " << "Too Bad" << '\n';
	}
	return 0;
}




















