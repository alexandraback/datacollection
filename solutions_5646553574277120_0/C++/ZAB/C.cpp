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

int C;
int D;
int V;

vector<int> coins;

inline void assert(bool v)
{
	if(!v) 
		throw "ERROR";
}

void readCase()
{
	cin >> C >> D >> V;

	coins.clear();

	for(int i = 0; i < D; i++) {
		int coin = -1;
		cin >> coin;
		coins.push_back(coin);
	}
}

int stupidsolve()
{
	if(C != 1) return -1;

	int cancnt = 0;
	vector<bool> can;
	can.assign(150, false);
	can[0] = true;

	for(int i = 0; i < D; i++) {
		vector<bool> ncan = can;
		for(int j = 0; j < ncan.size(); j++) {
			if(!ncan[j]) continue;
			int n = j + coins[i];
			if(n >= can.size()) continue;
			if(!ncan[n] && n <= V) cancnt++;
			can[n] = true;
		}
	}

	set<int> denoms(coins.begin(), coins.end());

	int bestcnt = 0;
	int bestdenom = 0;

	while(cancnt < V) {
		for(int newdenom = 1; newdenom <= V; newdenom++) {
			int cnt = cancnt;
			if(denoms.count(newdenom)) continue;
			bool need = false;
			vector<bool> ncan = can;
			for(int j = 0; j < can.size(); j++) {
				if(!ncan[j]) continue;
				int n = j + newdenom;
				if(n >= can.size()) continue;
				if(!ncan[n] && n <= V) cnt++, need = true;
				//can[n] = true;
			}
			//if(need) denoms.insert(newdenom);
			if(bestcnt < cnt) {
				bestcnt = cnt;
				bestdenom = newdenom;
			}
		}
		{
			int newdenom = bestdenom;

			vector<bool> ncan = can;
		
			for(int j = 0; j < can.size(); j++) {
				if(!ncan[j]) continue;
				int n = j + newdenom;
				if(n >= can.size()) continue;
				if(!ncan[n] && n <= V) cancnt++;
				can[n] = true;
			}
			denoms.insert(newdenom);
		}
	}

	return denoms.size() - coins.size();
}

int complexsolve()
{
	return 0;
}

void solve()
{
	int ss = stupidsolve();
	//int cs = complexsolve();

	//if(ss != cs) 
	//	cout << "err!!!";

	cout << ss;// << " " << cs;
}

int main()
{
	//string fname = "./test/C-example.in";
	//string fname = "./test/C-small-attempt0.in";
	//string fname = "./test/C-small-attempt1.in";
	string fname = "./test/C-small-attempt2.in";
	//string fname = "./test/C-large.in";
	//string fname = "./test/C-large-2.in";

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

