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


ofstream out ("A.out");
ifstream in ("A.in");

int main (int argc, char const* argv[])
{
	int T, A;
	double B;
	double p[100005], q[100005], r[100005], G[4];
	in >> T;
	for (int t = 0; t < T; t += 1)
	{
		in >> A >> B;
		p[0] = 0;
		for (int i = 0; i < A; i += 1)
		{
			in >> p[i+1];
		}
		q[0] = 1;
		for (int i = 1; i <= A; i += 1)
		{
			q[i] = q[i-1]*p[i];
		}
		
		G[1] = 100000;
		for (int b = 0; b <= A; b += 1)
		{
			G[1] = min( G[1], 1 + b + double(B-A+b) + (1-q[A-b])*(B+1) );
		}
		G[2] = 2 + B;
		printf("Case #%d: %.6lf\n",t+1, min(G[1],G[2]));
		
	}
	return 0;
}




















