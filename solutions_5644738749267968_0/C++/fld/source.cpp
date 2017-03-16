/*
   Google Code Jam
   Author: FLD 
   Date: 2014/04/12

   Save small input as stdin_small.txt
   Compile with: g++ -o small -DSMALL source.cpp
   Run with ./small
   Check output in stdout_small.txt

   Save large input as large.txt
   Compile with: g++ -o large -DLARGE source.cpp
   Run with ./large
   Check output in stdout_small.txt
*/

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;


#define FOR(loop,first,end) for(int loop=(int)(first);loop<(int)(end);loop++)
#define REP(loop,times) FOR(loop,0,times)
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

int play_dwar(vector<double> naomi, vector<double> ken, int N) {
	int pt = 0;
	double pn;
	REP(n, N) {
		pn = naomi.front();
		if (pn < ken.front()) {
			ken.pop_back();
			naomi.erase(naomi.begin());
		} else {
			pt++;
			naomi.erase(naomi.begin());
			ken.erase(ken.begin());
		}
	}
	return pt;
}

int play_war(vector<double> naomi, vector<double> ken, int N) {
	int pt = 0;
	double pn;
	REP(n, N) {
		pn = naomi.back();
		naomi.pop_back();
		if (pn > ken[N-n-1]) {
			ken.erase(ken.begin());
			pt++;
		} else {
			REP(i, N-n-1) {
				if (ken[i] > pn) {
					ken.erase(ken.begin()+i);
					break;
				}
			}
		}
	}
	return pt;
}

int main(int argc, char const *argv[])
{
	int T, N;
	vector<double> naomi, naomid;
	vector<double> ken, kend;
	double w;
	int dwar, war;

	// adjust stding and stdout
	#ifdef DEFAULT
	freopen("stdin.txt","rt",stdin);
	#endif
	#ifdef SMALL
	freopen("stdin_small.txt","rt",stdin);
	freopen("stdout_small.txt","wt",stdout);
	#endif
	#ifdef LARGE
	freopen("stdin_large.txt","rt",stdin);
	freopen("stdout_large.txt","wt",stdout);
	#endif

	cin >> T;
	REP(t,T) {
		cin >> N;
		REP(n, N) {
			cin >> w;
			naomi.push_back(w);
		}
		std::sort(naomi.begin(), naomi.end());
		naomid = naomi;
		REP(n, N) {
			cin >> w;
			ken.push_back(w);
		}
		std::sort(ken.begin(), ken.end());
		kend=ken;

		war = play_war(naomi, ken, N);
		dwar = play_dwar(naomid, kend, N);

		printf("Case #%d: %d %d\n", t+1, war, dwar);
		naomi.clear();
		ken.clear();
	}
	
	return 0;
}