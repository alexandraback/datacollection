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

int A, N;
vector<int> motes;

void readCase()
{
	scanf("%d %d\n", &A, &N);
	motes.resize(N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &motes[i]);
	}
}

void solve()
{
	sort(motes.begin(), motes.end());

	vector<int> ops;
	vector<bool> valid;

	const int maxops = 130;

	valid.assign(maxops, true);
	ops.resize(maxops);
	ops[0] = A;
	for(int i = 1; i < maxops; i++) {
		ops[i] = 2 * ops[i-1] - 1;
	}

	for(int j = 0; j < N; j++) {
		int curmote = motes[j];
		int skipop = 0;
		for(int i = maxops - 1; i >= 0; i--) {
			if(!valid[i]) continue;
			int curop = ops[i];
			if(curmote < ops[i]) {
				curop += curmote;
			} else {
				if(i == 0 || !valid[i-1]) {
					valid[i] = false;
				} else {
					curop = ops[i-1];
				}
			}
			ops[i] = curop;
		}	
		for(int i = 1; i < maxops; i++) {
			if(!valid[i-1]) continue;
			ops[i] = max(ops[i], 2 * ops[i-1] - 1);
		}
	}

	int minop = 0;
	while(!valid[minop]) minop++;

	printf("%d", minop);
}

int main()
{
	//string fname = "./test/A-example.in";
	string fname = "./test/A-small-attempt0.in";
	//string fname = "./test/A-large.in";
	
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

