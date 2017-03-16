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

int main() {
	FILE * inFile = fopen("A-large.in", "r");
	FILE * outFile = fopen("A.out", "w");
	int T;
	fscanf(inFile, "%d\n", &T);
	for (int testCase = 1; testCase <= T; testCase ++) {
		char c;
		string result = "";
		while (fscanf(inFile, "%c", &c) != EOF && c != '\n') {
			if (result == "" || c >= result[0])	result = c + result;
			else	result = result + c;
		}
		fprintf(outFile, "Case #%d: %s\n", testCase, result.c_str());
	}
	fclose(outFile);
	return 0;
}
