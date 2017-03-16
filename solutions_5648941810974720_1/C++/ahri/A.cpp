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

string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int letters[26];

string get(int digit, char letter) {
	int count = letters[letter - 'A'];
	string name = digits[digit];
	for(int i = 0; i < sz(name); ++i) {
		letters[name[i] - 'A'] -= count;
	}
	string ret = "";
	for(int i = 0; i < count; ++i){
		ret += ('0' + digit);
	}
	return ret;
}

void solve() {
	string S;
	cin >> S;
	memset(letters, 0, sizeof(letters));
	for(int i = 0; i < sz(S); ++i){
		letters[S[i]-'A']++;
	}
	string ret = "";
	ret += get(0, 'Z');
	ret += get(6, 'X');
	ret += get(8, 'G');
	ret += get(2, 'W');
	ret += get(4, 'U');
	ret += get(7, 'S');
	ret += get(5, 'V');
	ret += get(9, 'I');
	ret += get(1, 'O');
	ret += get(3, 'T');
	sort(ret.begin(), ret.end());
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
