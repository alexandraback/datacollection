

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
	int N, L, count;
	long long A, B;
	long long p10[15];
	set<long long> v;
	
	p10[0] = 1;
	
	forall ( i, 14 )	p10[i+1] = p10[i]*10;
	
	int T;
	in >> T;
	cout << T << " in total!\n";

	for (int t = 1; t <= T; t += 1)
	{
		in >> A >> B;
		L = int(log10(A))+1;
		v.clear();
		out << "Case #" << t << ": ";
		Forall( i, A, B )
		{
			Forall( j, 1, L-1 )
			{
				N = (i%p10[j])*p10[L-j] + (i/p10[j]);
				if (i < N && N <= B)
				{
					v.insert((Long)i*p10[8] + N);
				}
			}
		}
		out << v.size() << '\n';
		cout << t << "done!\n";
	}
	return 0;
}




















