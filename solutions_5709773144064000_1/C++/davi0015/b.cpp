#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <map>
#include <queue>
#include <ctime>
#include <cmath>

using namespace std;

#define forn(I,N) for (int I=0; I<N; I++)
#define fornd(I,N) for (int I=N-1; I>=0; I--)
#define forab(I,A,B) for (int I=A; I<=B; I++)
#define forabd(I,A,B) for (int I=B, I>=A; I--)
#define FOREACH(I,A) for (__typeof__(A)::iterator I=A.begin(); I<A.end(); I++)
#define pb push_back
#define mp make_pair

typedef long long int ll;

int main()
{
	int T;
	cin >> T;
	cout << fixed;
	forn (i, T)
	{
		double C, F, X;
		cin >> C >> F >> X;
		
		double best = X / 2.0;
		double time = 0;
		double prod = 2;
		while (true)
		{
			time += C/prod;
			prod += F;
			double nextBest = time + X / prod;
			if (nextBest < best)
				best = nextBest;
			else
				break;
		}
		
		cout << "Case #" << i+1 << ": " << setprecision(7) << best << endl;
	}
	
	return 0;
}