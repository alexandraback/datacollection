// gcc version 4.6.1 (tdm-1)
// g++ -I tr1 femidav.cpp -O2 -Wall -std=c++0x -o femidav.exe
// femidav < small-attempt0.in > small-attempt0.out
// femidav < large.in > large.out

#include <cstdio>
#include <algorithm>

#define FOR(I, N) for(int I = 0, end_ = (N); I < end_; ++I)
int ri() { int r; scanf("%d", &r); return r; }

int main()
{
	int p[] = {1, 4, 9, 121, 484};
    FOR(i, ri())
    {
		int A = ri(), B = ri();
		printf("Case #%d: %d\n", i + 1, std::distance(std::lower_bound(p, p + 5, A), std::upper_bound(p, p + 5, B)));
    }
}