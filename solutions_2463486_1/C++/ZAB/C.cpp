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
#include <list>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
using namespace std;

static long long fair[] = {1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 
	1002001LL, 1234321LL, 4008004LL, 100020001LL, 102030201LL, 104060401LL, 121242121LL, 123454321LL, 
	125686521LL, 400080004LL, 404090404LL, 10000200001LL, 10221412201LL, 12102420121LL, 12345654321LL, 
	40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL, 
	1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 
	4000008000004LL, 4004009004004LL, 100000020000001LL, 100220141022001LL, 102012040210201LL, 102234363432201LL, 
	121000242000121LL, 121242363242121LL, 123212464212321LL, 123456787654321LL, 400000080000004LL};

long long A, B;

void readCase()
{
	scanf("%lld %lld", &A, &B);
}

void solve()
{
	int count = 0;
	for(int i = 0; i < _countof(fair); i++) {
		if( A <= fair[i] && fair[i] <= B ) {
			count++;
		}
	}

	printf("%d", count);
}

int main()
{
	//string fname = "./test/C-example.in";
	//string fname = "./test/C-small-attempt0.in";
	string fname = "./test/C-large-1.in";
	//string fname = "./test/C-large.in";
	
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

