#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int actionsToEat(int a, vector<int> motes, int st){
	int n;
	int ret;
	n = motes.size();
	ret = 0;
	if (a<=1) return 1000000000;
	while(st<n){
		while(a<=motes[st]){
			a+=a-1;
			ret++;
		}
		a+=motes[st];
		st++;
	}
	return ret;
}

int solve(int a, vector<int> motes){
	int cur, n, ret, r, best;

	sort(motes.begin(), motes.end());
	n = motes.size();

	cur = 0;
	best = n;
	REP(i, n){
		r = actionsToEat(a,motes,0);
		if(best > r + i) best = r+i;
		motes.pop_back();
	}
	return best;
}

int main(void){
	vector <int> motes;
	int A, T, N, ret;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");

	fin >> T;


	REP(w, T){
		fin >> A >> N;
		motes.resize(N);
		REP(i,N) fin >> motes[i];
		ret = solve(A, motes);

		fout << "Case #" << w+1 << ": " << ret << endl;
	}
	fout.close();
	fin.close();
	return 0;
}