// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>

using namespace std;

ifstream fin("c.in");
ofstream fout("c.out");

#define MAXN 110
int i, t, T, N, M;
int atype[MAXN], btype[MAXN];
long long anum[MAXN], bnum[MAXN];

long long max(long long &a, long long &b) {
	return a > b ? a : b;
}
int max(int &a, int &b) {
	return a > b ? a : b;
}

long long doit(int apos, long long adropped, int bpos, long long bdropped) {
	if(apos == N || bpos == M) return 0;

	long long res = 0;
	// drop all boxes
	res = doit(apos + 1, 0, bpos, bdropped);

	// try to find matches
	for(int i = bpos; i < M; i++) {
		if(i > bpos) bdropped = 0;
		if(atype[apos] == btype[i]) {
			long long m = min(anum[apos] - adropped, bnum[i] - bdropped);
			adropped += m;
			bdropped += m;

			if(adropped == anum[apos]) {
				if(bdropped == bnum[i]) res = max(res, m + doit(apos + 1, 0, i + 1, 0));
				else res = max(res, m + doit(apos + 1, 0, i, bdropped));
			}
			else {
				if(bdropped == bnum[i]) res = max(res, m + doit(apos, adropped, i + 1, 0));
				else res = max(res, m + doit(apos, adropped, i, bdropped));
			}
			return res;
		}
	}

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	fin >> T;
	for(t = 1; t <= T; t++) {
		fin >> N >> M;
		for(i = 0; i < N; i++)
			fin >> anum[i] >> atype[i];
		for(i = 0; i < M; i++)
			fin >> bnum[i] >> btype[i];

		long long res = doit(0, 0, 0, 0);

		fout << "Case #" << t << ": " << res << "\n";
	}
	return 0;
}

