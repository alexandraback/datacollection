#include <cstdio>
#include <vector>
#include <algorithm>

#define FOR(I, N) for( int I = 0, end_ = (N); I < end_; ++I )
int ri() { int r; scanf( "%d", &r ); return r; }
typedef std::vector<int> VI;
VI const rvi(int n) { VI r(n); FOR(i, n) r[i] = ri(); return r; }

int main()
{
    FOR(i, ri())
    {
		int N = ri();
		VI v = rvi(N);

		for(int j = 1; j < N; ++j)
		{
			for(int k = 2; k < N; ++k)
			{
				int M[20] = {0};int l = 0;
				while(l < k && l < N) M[l++] = 1;
				while(l < j && l < N) M[l++] = 2;
				do {
					int S1 = 0;
					for(int m = 0; m < N; ++m) if (M[m] == 1) S1 += v[m];
					int S2 = 0;
					for(int m = 0; m < N; ++m) if (M[m] == 2) S2 += v[m];
					if (S1 == S2)
					{
						printf("Case #%d:\n", i + 1);
						for(int m = 0; m < N; ++m) if (M[m] == 1) printf("%d ", v[m]);
						printf("\n");
						for(int m = 0; m < N; ++m) if (M[m] == 2) printf("%d ", v[m]);
						printf("\n");
						goto case_solved;
					}
				} while(std::next_permutation(M, M + N));
			}
		}
		case_solved:;
    }
}