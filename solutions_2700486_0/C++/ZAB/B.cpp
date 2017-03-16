#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

int N, x, y;

void readCase()
{
	scanf("%d %d %d", &N, &x, &y);
	if(x < 0) x = -x;
}

double count(int x, int y, int N)
{
//	if()


	return 0;
}

void solve()
{
	if( (abs(x) + abs(y)) % 2 ) {
		printf("0.0");
		return;
	}

	int curi = (abs(x) + abs(y))/2;
	if(curi == 0) {
		printf("1.0");
		return;
	}

	int cura = 2 * curi + 1;
	int curb = (cura * cura + cura) / 2;
	int preda = 2 * (curi - 1) + 1;
	int predb = (preda * preda + preda) / 2;

	if(N == curb) {
		if(x == 0) {
			printf("1.0");
			return;
		} else {
			printf("0.0");
			return;
		}
	}

	if(x == 0 && N != curb) {
		printf("0.0");
		return;
	}

	N -= predb;
	if(N <= 0) {
		printf("0.0");
		return;
	}

	int sum = 0;
	for(int i = 0; i < (1 << N); i++) {
		int cnt = 0;
		int j = i;
		while(j > 0) cnt++, j &= (j-1);
		if(cnt > y) sum++;
	}

	printf("%f", 1. * sum / pow(2., N));
}

int main()
{
	//string fname = "./test/B-example.in";
	string fname = "./test/B-small-attempt0.in";
	//string fname = "./test/B-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	int analizeCase = -1;
	
	int T;
	scanf("%d", &T);
	for(int tCase = 1; tCase <= T; tCase++) {
		printf("Case #%d: ", tCase);
		readCase();
		if(analizeCase < 0 || analizeCase == tCase) solve();
		printf("\n");
		fflush(stdout);
		fprintf(stderr, "Done %d %%     \r", 100 * tCase / T );
	}
	return 0;
}

