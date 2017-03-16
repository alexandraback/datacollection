#ifndef FLLD
#ifdef WIN32
#define FLLD "%I64d"
#else
#define FLLD "%lld"
#endif
#endif

#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <ctime>
#include <tuple>
#include <random>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <queue>

#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define NOKEY(x, y) ((x).find(y) == (x).end())
#define EXISTKEY(x, y) ((x).find(y) != (x).end())
#define INCMAP(x, y) ((x)[y] = MAPINTV(x, y) + 1)
#define MAPINTV(x, y) (EXISTKEY(x, y) ? (x)[y] : 0)
#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; i ++)
#define FORALL(x, l) for (const auto & x : l)
#define DEBUGLEVEL 5
#define DEBUG(debuglevel, ...) if(debuglevel <= DEBUGLEVEL) fprintf(stderr, ##__VA_ARGS__);
typedef long long ll;

using namespace std;

FILE * outFile;

int N;
int mapss[55][55];
vector<vector<int> > inp;
map<int, int> mm;

bool comp(vector<int> &a, vector<int> &b) {
	REP(i, 0, N) {
		if (a[i] < b[i])	return true;
		if (a[i] > b[i])	return false;
	}
	return true;
}

int search(int c, int r, int fc, int fr, int cur) {
	/*
	printf("%d %d %d %d %d:\n", c, r, fc, fr, cur);
	for (int i = 0; i < N; i ++)
	{
		for (int j = 0; j < N; j ++)
			printf("%d ", mapss[i][j]);
		printf("\n");
	}
	*/
	if (c == N && r == N) {
		if (fc != -1) {
			REP(i, 0, N)	fprintf(outFile, " %d", abs(mapss[fc][i]));
		}
		if (fr != -1) {
			REP(i, 0, N)	fprintf(outFile, " %d", abs(mapss[i][fr]));
		}
		fprintf(outFile, "\n");
		return 1;
	}
	if (c == fc)	return search(c + 1, r, fc, fr, cur);
	if (r == fr)	return search(c, r + 1, fc, fr, cur);
	int flag = 1;
	if (c == N)	flag = 0;
	for (int i = 0; i < N && flag; i ++)
		if (mapss[c][i] != 0 && mapss[c][i] != inp[cur][i])
			flag = 0;
	if (flag) {
		for (int i = 0; i < N; i ++) {
			if (mapss[c][i] == 0)	mapss[c][i] = inp[cur][i];
			else	mapss[c][i] = -inp[cur][i];
		}
		if (search(c + 1, r, fc, fr, cur + 1))	return 1;
		for (int i = 0; i < N; i ++) {
			if (mapss[c][i] < 0)	mapss[c][i] = -mapss[c][i];
			else	mapss[c][i] = 0;
		}
	}

	flag = 1;
	if (r == N)	flag = 0;
	for (int i = 0; i < N && flag; i ++)
		if (mapss[i][r] != 0 && mapss[i][r] != inp[cur][i])
			flag = 0;
	if (flag) {
		for (int i = 0; i < N; i ++) {
			if (mapss[i][r] == 0)	mapss[i][r] = inp[cur][i];
			else	mapss[i][r] = -inp[cur][i];
		}
		if (search(c, r + 1, fc, fr, cur + 1))	return 1;
		for (int i = 0; i < N; i ++) {
			if (mapss[i][r] < 0)	mapss[i][r] = -mapss[i][r];
			else	mapss[i][r] = 0;
		}
	}
	return 0;
}

int main() {
	int T;
	FILE * inFile = fopen("B-large.in", "r");
	outFile = fopen("B-2.out", "w");
	fscanf(inFile, "%d", &T);
	REP(testCase, 0, T) {
		inp.resize(0);
		fprintf(outFile, "Case #%d:", testCase + 1);
		fscanf(inFile, "%d", &N);
		mm.clear();
		REP(i, 0, 2 * N - 1) {
			vector<int> tmp;
			tmp.resize(0);
			int x;
			REP(j, 0, N) {
				fscanf(inFile, "%d", &x);
				mm[x] ++;
				//tmp.push_back(x);
			}
			//inp.push_back(tmp);
		}
		for (int i = 1; i <= 2500; i ++)
			if (mm[i] % 2 == 1)
				fprintf(outFile, " %d", i);
		fprintf(outFile, "\n");
		/*
		sort(inp.begin(), inp.end(), comp);
		memset(mapss, 0, sizeof(mapss));
		int flag = 0;
		for (int i = 0; i < N && flag == 0; i ++)
			flag = search(0, 0, i, -1, 0);
		for (int i = 0; i < N && flag == 0; i ++)
			flag = search(0, 0, -1, i, 0);
		*/
	}
	return 0;
}
