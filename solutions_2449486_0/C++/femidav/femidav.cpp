// gcc version 4.6.1 (tdm-1)
// g++ -I tr1 femidav.cpp -O2 -Wall -std=c++0x -o femidav.exe
// femidav < small-attempt0.in > small-attempt0.out
// femidav < large.in > large.out

#include <cstdio>
#include <iostream>
#include <vector>

#define FOR(I, N) for( int I = 0, end_ = (N); I < end_; ++I )
int rin() { int r; scanf( "%d\n", &r ); return r; }
int ri() { int r; scanf("%d", &r); return r; }
typedef std::vector<int> VI;
VI const rvi(int n) { VI r(n); FOR(i, n) r[i] = ri(); return r; }

int main()
{
    FOR(i, rin())
    {
		int N = ri(), M = rin();

		VI buf = rvi(N*M);
		VI res(N*M);

		for(int a = 2; a > 0; --a)
		{
			for(int n = 0; n < N; ++n)
			{
				bool suitedLine = true;
				for(int m = 0; m < M; ++m)
					if (buf[n * M + m] > a) {suitedLine = false; break;}

				if (suitedLine)
					for(int m = 0; m < M; ++m)
						res[n * M + m] = a;
			}

			for(int m = 0; m < M; ++m)
			{
				bool suitedLine = true;
				for(int n = 0; n < N; ++n)
					if (buf[m + n * M] > a) {suitedLine = false; break;}

				if (suitedLine)
					for(int n = 0; n < N; ++n)
						res[m + n * M] = a;
			}
		}

		bool success = true;
		for(unsigned x = 0; x < res.size(); ++x)
			if (res[x] != buf[x]) {success = false; break;}

		printf("Case #%d: %s\n", i + 1, success ? "YES" : "NO");
    }
}