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

vector <int> dp;

inline bool isCons(char c){
	if(c!= 'a' && c!= 'e' && c!= 'i' && c!= 'o' && c!='u')return true;
	return false;
}

int solve(string str, int n){
	int sz;
	int ret = 0;
	int good;

	sz = str.size();
	dp.clear();
	dp.resize(sz+1, 0);

	FOR(i, n, sz){
		dp[i] = dp[i-1];
		if(isCons(str[i-1])){
			good = 1;
			FOR(q, 1, n-1){
				if(!isCons(str[i-1-q])){
					good = 0;
					break;
				}
			}
			if(good) dp[i]=i-n+1;
		}
	}
	ret = 0;
	REP(i,sz+1)ret+=dp[i];
	return ret;
}

int main(void){
	int T;
	int ret;
	ifstream fin("A-small-attempt0.in");
	ofstream fout("out.txt");
	string str;
	int n;

	fin >> T;
	REP(w, T){
		fin >> str >> n;
		ret = solve(str, n);

		cout << "Case #" << w+1 << ": " << ret << endl;
		fout << "Case #" << w+1 << ": " << ret << endl;
	}

	fin.close();
	fout.close();
	return 0;
}
