#include <stdio.h>
#include <functional>
#include <bitset>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <bitset>
#include <string.h>
#include <iomanip>
using namespace std;

int K;
int L;
int S;
string keyboard;
string word;

void readCase()
{
	cin >> K >> L >> S;
	cin >> keyboard;
	cin >> word;
}

map<char, int> keys;
int wordi;
int wordmod;

int cnt;
int success;
int mcount;

void enumwords(int curword = 0, int mcnt = 0, int pos = 0)
{
	if(pos == S) {
		cnt++;
		success += mcnt;
		mcount = max(mcount, mcnt);
		return;
	}

	int nword = curword * keys.size();
	nword %= wordmod;

	for(int i = 0; i < K; i++) {
		char k = keyboard[i];
		int nwordk = nword + keys[k];
		int nmcnt = mcnt;
		if(nwordk == wordi) {
			nmcnt++;
		}
		enumwords(nwordk, nmcnt, pos+1);
	}
}

double stupidsolve()
{
	keys.clear();
	keys['_'] = 0;

	for(int i = 0; i < keyboard.size(); i++) {
		char k = keyboard[i];
		int idx;
		if(keys.count(k) == 0) {
			idx = keys.size();
			keys[k] = idx;
		} else idx = keys[k];
	}

	wordi = 0;
	wordmod = 1;
	
	for(int i = 0; i < word.size(); i++) {
		char k = word[i];
		int idx;
		if(keys.count(k) == 0) {
			return 0;
		} else idx = keys[k];
		wordi *= keys.size();
		wordi += idx;
		wordmod *= keys.size();
	}

	cnt = 0;
	success = 0;
	mcount = 0;

	enumwords();

	return mcount - 1. * success / cnt;
}

int complexsolve()
{
	return 0;
}

void solve()
{
	double ss = stupidsolve();
	//int cs = complexsolve();

	//if(ss != cs) 
	//	cout << "err!!!";

	cout << ss;// << " " << cs;
}

int main()
{
	//string fname = "./test/B-example.in";
	string fname = "./test/B-small-attempt0.in";
	//string fname = "./test/B-small-attempt1.in";
	//string fname = "./test/B-small-attempt2.in";
	//string fname = "./test/B-small-practice.in";
	//string fname = "./test/B-large-practice.in";
	//string fname = "./test/B-large.in";
	
	freopen(fname.c_str(),"r",stdin);freopen((fname+".out").c_str(),"w",stdout);

	cout << std::setprecision(10);

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

