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
#include <iomanip>
using namespace std;

int J, P, S, K;

inline void assert(bool v)
{
	if(!v) 
		throw "ERROR";
}

void readCase()
{
	cin >> J >> P >> S >> K;
}

int stupidsolve()
{
	typedef pair<int, pair<int, int>> outfit;

	vector<outfit> solution;

	map< pair<int, int>, int > JP;
	map< pair<int, int>, int > JS;
	map< pair<int, int>, int > PS;

	for(int j = 0; j < J; j++) {
		for(int p = 0; p < P; p++) {
			for(int s = 0; s < S; s++) {
				if(JP[make_pair(j, p)] == K) continue;
				if(JS[make_pair(j, s)] == K) continue;
				if(PS[make_pair(p, s)] == K) continue;
				JP[make_pair(j, p)]++;
				JS[make_pair(j, s)]++;
				PS[make_pair(p, s)]++;
				solution.push_back(make_pair(j, make_pair(p, s)));	
			}
		}
	}

	cout << solution.size();
	for(int j = 0; j < solution.size(); j++) {
		outfit& cur = solution[j];
		cout << endl;
		cout << cur.first + 1 << " " << cur.second.first + 1 << " " << cur.second.second + 1;
	}

	return solution.size();
}


int complexsolve()
{
	return 0;
}

void solve()
{
	stupidsolve();
}

int main()
{
	//string fname = "./test/C-example.in";
	//string fname = "./test/C-small-attempt0.in";
	string fname = "./test/C-small-attempt1.in";
	//string fname = "./test/C-small-attempt2.in";
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

