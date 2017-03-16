#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <complex>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>

#define REP(i,x) for(int i=0 ; i<(int)(x) ; i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long

using namespace std;

inline bool check(string s){
	static bool charSet[30];
	memset(charSet,false,sizeof(charSet));
	char prev = -1;
	REP(i, s.size()){
		if (prev != s[i]){
			if (charSet[s[i]-'a'])return false;
			charSet[s[i] - 'a'] = true;
		}
		prev = s[i];
	}
	return true;
}

int main(){
	int T;
	cin >> T;
	REP(testCase, T){
		int N;
		cin >> N;
		vector<string> sets(N);
		vector<int> idx;
		REP(i, N){
			cin >> sets[i];
			idx.push_back(i);
		}
		int res = 0;
		do{
			string s = "";
			REP(i, N)s += sets[idx[i]];
			if (check(s)){
				//cout << s << endl;
				res++;
			}
		} while (next_permutation(ALL(idx)));
		cout << "Case #" << testCase + 1 << ": " << res << endl;
	}
}