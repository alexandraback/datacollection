#include <cstdio>
#define FOR(i,b,e) for(int i=(b); i<=(e); ++i)
using namespace std;


int main()
{
	int Q; scanf("%d", &Q);
	FOR(q, 1, Q) {
		int x, y;
		scanf("%d%d", &x, &y);
		
		printf("Case #%d: ", q);
		while (x > 0) printf("WE"), --x;
		while (x < 0) printf("EW"), ++x;
		while (y > 0) printf("SN"), --y;
		while (y < 0) printf("NS"), ++y;
		putchar('\n');
	}
	
	return 0;
}
