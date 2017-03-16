#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#include <utility>
#include <iterator>
#include <fstream>
#include <cstdio>
#include <functional>
#include <cassert>
#include <array>

using namespace std;

template<class T>
string tostring(T a){ stringstream ss; ss << a; return ss.str(); }

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> II;
#define SZ(a) int((a).size()) 
#define PB push_back 
#define ALL(c) (c).begin(),(c).end() 
#define FOR(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define LOOP(i,a,b) for((i)=(a);(i)<(b);(i)++)
#define MP(a,b) make_pair((a),(b))
#define LAST(t) (t[SZ(t)-1])


vector<string> strs{ "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };
vector<vector<int>> dighists(10, vector<int>(26));

bool containshist(const vector<int> &a, const vector<int> &b){ // a contains b
	assert(SZ(a) == 26);
	assert(SZ(b) == 26);
	FOR(i, SZ(a)){
		if(a[i] < b[i])
			return false;
	}
	return true;
}


vector<int> sol;

bool solve(int dig, VI &remhist){

	bool done = true;
	for(int i = 0; i < 26; i++){
		if(remhist[i] != 0)
			done = false;
	}
	if(done)
		return true;

	if(containshist(remhist, dighists[dig])){
		for(int i = 0; i < 26; i++){
			remhist[i] -= dighists[dig][i];
		}
		sol.push_back(dig);
		if(solve(dig, remhist)){
			return true;
		} else {
			sol.pop_back();
		}
		for(int i = 0; i < 26; i++){
			remhist[i] += dighists[dig][i];
		}

		if(dig == 9)
			return false;
		return solve(dig + 1, remhist);

	} else {
		if(dig == 9)
			return false;
		//assert(dig < 9);
		return solve(dig + 1, remhist);
	}
	return false;
}


int main(){

	
	FOR(i, 10){
		for(char c : strs[i]){
			dighists[i][c - 'A']++;
		}
	}

	ifstream be("A-small-attempt2.in");
	ofstream ki("ki.txt");
	int T;
	be >> T;
	{string s; getline(be, s); }
	FOR(tt, T){
		string s; 
		getline(be, s);

		vector<int> behist(26);
		for(char c: s){
			behist[c - 'A']++;
		}
		sol.clear();

		bool b = solve(0, behist);
		assert(b);

		ostringstream ss;
		for(int x : sol){
			ss << x;
		}

		ki<<"Case #"<<tt+1<<": "<< ss.str() <<endl;
	}

	ki.close();
	return 0;
}