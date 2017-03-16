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

int N, M;
int height[1000][1000];
int maxx[1000];
int maxy[1000];

void readCase()
{
	scanf("%d %d", &N, &M);
	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			scanf("%d\n", &height[x][y]);
		}
	}
}

void solve()
{
	for(int y = 0; y < N; y++) {
		maxy[y] = 0;
		for(int x = 0; x < M; x++) {
			maxy[y] = max(maxy[y], height[x][y]);
		}
	}

	for(int x = 0; x < M; x++) {
		maxx[x] = 0;
		for(int y = 0; y < N; y++) {
			maxx[x] = max(maxx[x], height[x][y]);
		}
	}

	for(int y = 0; y < N; y++) {
		for(int x = 0; x < M; x++) {
			if(height[x][y] != maxx[x] && height[x][y] != maxy[y]) {
				printf("NO");
				return;
			}
		}
	}	

	printf("YES");
}

int main()
{
	//string fname = "./test/B-example.in";
	//string fname = "./test/B-small-attempt0.in";
	string fname = "./test/B-large.in";
	
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

