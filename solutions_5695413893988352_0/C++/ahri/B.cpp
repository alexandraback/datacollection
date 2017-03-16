/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
#define EXISTS(x, s) ( (s).find((x)) != (s).end() ) 
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }

char buffer[20];
string pad(int i, string code) {
	sprintf(buffer, "%d", i);
	string ret = string(buffer);
	while (sz(ret ) < sz(code))
		ret = "0" + ret;
	return ret;
	
}

bool fit(string code, string value) {
	if (sz(code) != sz(value)) 
		return false;
	for(int i = 0; i < sz(code); ++i){
		if (code[i] != '?' && code[i] != value[i])
			return false;
	}
	return true;
}

void solve(){
	string S[2];
	cin >> S[0] >> S[1];
	int best = 1000;
	string ret = "";
	for(int i = 0; i < 1000; ++i){
		string si = pad(i, S[0]);
		if (fit(S[0], si))
			for(int j = 0; j < 1000; ++j){
				string sj = pad(j, S[1]);
				if (fit(S[1], sj)) {
					if (abs(j - i) < best) {
						ret = si + " " + sj;
						best = abs(j - i);
						// cerr << best << endl;
					}
				}
			}
	}
	cout << ret << endl;
	
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
