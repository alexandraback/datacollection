// gcc version 4.6.1 (tdm-1)
// g++ -I tr1 femidav.cpp -O2 -Wall -std=c++0x -o femidav.exe
// femidav < small-attempt0.in > small-attempt0.out
// femidav < large.in > large.out

#include <cstdio>
#include <vector>
#include <functional>
#include <numeric>
#include <cmath>

#define FOR(I, N) for( int I = 0, end_ = (N); I < end_; ++I )
int ri() { int r; scanf( "%d", &r ); return r; }
typedef std::vector<int> VI;
VI const rvi(int n) { VI r(n); FOR(i, n) r[i] = ri(); return r; }

int main()
{
    FOR(i, ri())
    {
		int N = ri(), n = N, oldN;
		VI V = rvi(N);

		int S0 = std::accumulate(V.begin(), V.end(), 0), S = 0;
		double T = 2*S0/(double) N;

		do {
			oldN = n; n = N; S = 0;
			for(int j = 0; j < N; j++)
				if (V[j] > T)
					--n, S += V[j];
			T = (2*S0 - S)/(double) n;
		} while(n < oldN);

        printf("Case #%d:", i + 1);
		FOR(k, N)
		{
			if (V[k] > T)
		        printf(" 0.000000");
		    else
		        printf(" %.6f", 100*(T - V[k])/S0);
		}
        printf("\n");
    }
}