#include <cstdio>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 100

long long int An[NMAX+1]; // box
int At[NMAX+1];
long long int Bn[NMAX+1]; // toy
int Bt[NMAX+1];

long long int ans[NMAX+1][NMAX+1];

long long int foo(int i, int j, int N, int M, int spi, int spj)
{
	if (i >= N || j >= M)
		return 0ll;
#if 1
	if (!spi && !spj && ans[i][j] != -1)
		return ans[i][j];
#endif

	// throw box group i
	long long int a = foo(i+1, j, N, M, 0, spj);

	long long int b, c;
	if (At[i] == Bt[j]) {
#if 1
		// pick box group i and toy group j
		long long int gg = min(An[i], Bn[j]);
		b = foo(i+1, j+1, N, M, 0, 0) + gg;
		if (An[i] > Bn[j]) {
#if 1
			long long int tmp = An[i];
			long long int mymax = 0;
			for (int k=j; k<M; ++k) {
				if (At[i] == Bt[k]) {
					long long int ggg = min(tmp, Bn[k]);
					tmp -= ggg;
					long long int x;
					if (0 && Bn[k] <= tmp + ggg) {
						x = (An[i] - tmp) + foo(i+1, k+1, N, M, 0, 0);
					} else {
						Bn[k] -= ggg;
						x = (An[i] - tmp) + foo(i+1, k, N, M, 0, 1);
						Bn[k] += ggg;
					}
					if (x > mymax)
						mymax = x;
					if (!tmp)
						break;
				}
			}
			if (mymax > b)
				b = mymax;
#else
			An[i] -= Bn[j];
			b = foo(i, j+1, N, M, 1, 0) + gg;
			An[i] += Bn[j];
#endif
		} else if (An[i] < Bn[j]) {
#if 1
			long long int tmp = Bn[j];
			long long int mymax = 0;
			for (int k=i; k<N; ++k) {
				if (At[k] == Bt[j]) {
					long long int ggg = min(tmp, An[k]);
					tmp -= ggg;
					long long int x;
					if (0 && An[k] <= tmp + ggg) {
						x = (Bn[j] - tmp) + foo(k+1, j+1, N, M, 0, 0);
					} else {
						An[k] -= ggg;
						x = (Bn[j] - tmp) + foo(k, j+1, N, M, 1, 0);
						An[k] += ggg;
					}
					if (x > mymax)
						mymax = x;
					if (!tmp)
						break;
				}
			}
			if (mymax > b)
				b = mymax;
#else
			Bn[j] -= An[i];
			b = foo(i+1, j, N, M, 0, 1) + gg;
			Bn[j] += An[i];
#endif
		}
#else
		b = foo(i+1, j+1, N, M) + std::min(An[i], Bn[j]);
#endif
	} else {
		// throw both
		b = foo(i+1, j+1, N, M, 0, 0);
	}

	// throw toy group j
	c = foo(i, j+1, N, M, spi, 0);

	ans[i][j] = max(a, max(b, c));
	return ans[i][j];
}

int main(void)
{
	int T_;
	scanf("%d ", &T_);
	for (int i_ = 1; i_ <= T_; ++i_) {
		memset(ans, -1, sizeof(ans));
		printf("Case #%d: ", i_);
		int N, M;
		scanf("%d %d", &N, &M);
		for (int i=0; i<N; ++i) {
			long long int ai;
			int Ai;
			scanf("%lld %d", &ai, &Ai);
			An[i] = ai;
			At[i] = Ai;
		}
#if 0
		printf("----------\n");
		for (int i=0; i<N; ++i) {
			printf("%lld %d\n", An[i], At[i]);
		}
		printf("----------\n");
#endif
		for (int i=0; i<M; ++i) {
			long long int bi;
			int Bi;
			scanf("%lld %d", &bi, &Bi);
			Bn[i] = bi;
			Bt[i] = Bi;
		}
#if 0
		for (int i=0; i<M; ++i) {
			printf("%lld %d\n", Bn[i], Bt[i]);
		}
		printf("----------\n");
		continue;
#endif
		printf("%lld\n", foo(0,0,N,M,0,0));
	}
	return 0;
}
