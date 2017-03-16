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

long long B, M;

void readCase()
{
	cin >> B >> M;
}

bool G[6][6];
bool vis[6];
bool path[6];
long long pcount[6];
bool loop = false;

long long dumbdfs(int v)
{
	if(path[v]) {
		loop = true;
		return 0;
	}
	if(vis[v]) return pcount[v];
	path[v] = true;
		
	for(int i = 0; i < B; i++) {
		if(G[v][i]) {
			pcount[v] += dumbdfs(i);
		}
	}
	
	path[v] = false;
	vis[v] = true;
	return pcount[v];
}

bool dumbsolve()
{
	vector< pair<int, pair<int, int>> > bits;

	for(int x = 0; x < B - 1; x++) {
		for(int y = 1; y < B; y++) {
			if(x == y) continue;
			bits.push_back( make_pair( 1 << bits.size(), make_pair(x, y) ) );
		}
	}

	for(int m = 0; m < (1 << bits.size()); m++) {
		memset(G, 0, sizeof(G));

		for(int i = 0; i < bits.size(); i++) {
			if(m & bits[i].first) G[bits[i].second.first][bits[i].second.second] = true;
		}

		memset(vis, 0, sizeof(vis));
		memset(path, 0, sizeof(path));
		memset(pcount, 0, sizeof(pcount));
		pcount[B-1] = 1;
		loop = false;
		long long cnt = dumbdfs(0);
		if(loop) continue;
		if(cnt == M) {
			cout << "POSSIBLE";
			for(int x = 0; x < B; x++) {
				cout << endl;
				for(int y = 0; y < B; y++) {
					if(G[x][y]) cout << '1'; else cout << '0';
				}
			}

			return true;
		}
	}

	cout << "IMPOSSIBLE";
   
	return false;
}

bool complexsolve()
{

	return false;
}

void solve()
{
	bool ss = dumbsolve();
	//bool cs = complexsolve();

	//if(ss != cs) 
		//cout << "err!!!";

	//cout << ss << " " << cs;
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

