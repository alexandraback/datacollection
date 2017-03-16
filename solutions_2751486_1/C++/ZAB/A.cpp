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

int N;
string name;
bool cons[256];

void init()
{
	for(int i = 0; i < 256; i++) {
		cons[i] = string("aeiou").find((char)i) == string::npos;
	}
}

void readCase()
{
	static char buf[2*1000*1000];
	scanf("%s %d\n", &buf, &N);
	name = buf;
}

void solve()
{
	int L = name.size();

	long long count = 0;

	int conscnt = 0;
	int start = 0;
	for(int i = 0; i < N; i++)
		if(cons[name[i]]) conscnt++;
	
	int predstart = -1;
	int end = N;

	while(true) {
		if(conscnt == N) {
			count += 1LL * (L - end + 1) * (start - predstart);
			predstart = start;
		}		
		if(end == L) break;
		if(cons[name[start]]) conscnt--;
		if(cons[name[end]]) conscnt++;
		start++;
		end++;
	}
	
	printf("%lld", count);
}

int main()
{
	init();

	//string fname = "./test/A-example.in";
	//string fname = "./test/A-small-attempt0.in";
	string fname = "./test/A-large.in";
	
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

