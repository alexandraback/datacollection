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
vector<int> src;

inline void assert(bool v)
{
	if(!v) throw "ERROR";
}

void readCase()
{
	cin >> N;
	/*
	src.clear();
	string s;
	cin >> s;
	
	for(int i = 0; i <= N; i++) {
		int v = s[i] - '0';
		src.push_back(v);
	}
	/**/
}

vector<int> cnts;

void solveStupid()
{
	int N = 1000000 + 10;

	cnts.assign(N, INT_MAX);

	cnts[1] = 1;

	for(int i = 1; i < N - 1; i++) {
		static char buf[50];
		string s(itoa(i, buf, 10));
		reverse(s.begin(), s.end());
		int n = atoi(s.c_str());
		if(n < N) cnts[n] = min(cnts[n], cnts[i] + 1);
		cnts[i+1] = min(cnts[i+1], cnts[i] + 1);
	}

	for(int i = 1; i < 100; i++) {
		cout << i << ": " << cnts[i] << endl;
	}
}

void solve()
{
	int stupid = -1;
	if(N < cnts.size()) stupid = cnts[N];

	cout << stupid;
}

int main()
{
	solveStupid();

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

