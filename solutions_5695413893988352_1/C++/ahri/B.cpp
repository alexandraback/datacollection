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

char get_biggest(char c) {
	return c == '?' ? '9' : c;
}
char get_smallest(char c) {
	return c == '?' ? '0' : c;
}

char try_same(char a, char b) {
	if (a == '?' && b == '?') return '0';
	if (a == '?') return b;
	if (b == '?') return a;
	return 0;
}

string try_plusone(char a, char b) {	
	if (a == '?' && b == '?') return "01";
	if (a == '?') return b == '0' ? "" : (string(1, b - 1) + string(1, b));
	if (b == '?') return a == '9' ? "" : (string(1, a) + string(1, a + 1));
	if (a < b)
		return string(1, a) + string(1, b);
	return "";
}

bool shit_follows(string A, string B, int index, int len) {
	if (index == len) return false;
	if ((A[index] == '?' && B[index] == '0')
	||  (A[index] == '9' && B[index] == '?'))
		return shit_follows(A, B, index + 1, len);
	if (A[index] == '?' || B[index] == '?')
		return false;
	if (A[index] == B[index])
		return shit_follows(A, B, index + 1, len);
	return A[index] > B[index];
}

bool tentative_shit_follows(string A, string B, int index, int len) {
	if (index == len) return false;
	if (A[index] == '?' && B[index] == '?')
		return tentative_shit_follows(A, B, index + 1, len);
	if (A[index] == '?' || B[index] == '?')
		return false;
	return A[index] > B[index];
}

bool tent_test(string A, string B, int index, int len) {
	// cerr << A << " " << B << " " << index << endl;
	if (index >= len - 1)
		return false;
	if (!(A[index] == '?' && B[index] != '?'))
		return false;
	if (A[index + 1] != '?' || B[index + 1] != '?')
		return false;
	return tentative_shit_follows(A, B, index + 1, len);
}


string smaller(string S1, string S2, bool swapped) {
	int N = sz(S1);
	int is_smaller = false;
	string R1 = S1, R2 = S2;
	for(int i = 0; i < N; ++i){
		if (is_smaller) {		
			R1[i] = get_biggest(S1[i]);
			R2[i] = get_smallest(S2[i]);
		} else {		
			bool shit = shit_follows(S1, S2, i + 1, N);
			bool tent_shit = !shit && tent_test(S1, S2, i, N);
			if (tent_shit) {
				string x = try_plusone(S1[i], S2[i]);
				cerr << S1 << " " << S2 << " " << i << " " << x << endl;
				if (x != "") {
					R1[i] = x[0];
					R2[i] = x[1];
					// cerr << R1 << " " << R2 << endl;
					is_smaller = true;
					continue;
				}
			}
			if (shit) {
				string x = try_plusone(S1[i], S2[i]);
				// cerr << S1 << " " << S2 << " " << i << " " << x << endl;
				if (x == "")
					return "";
				R1[i] = x[0];
				R2[i] = x[1];
				// cerr << R1 << " " << R2 << endl;
				is_smaller = true;
				continue;
			}
			char c = try_same(S1[i], S2[i]);
			if (c) {
				R1[i] = R2[i] = c;
			} else {
				if (S1[i] > S2[i])
					return "";
				if (S1[i] < S2[i])
					is_smaller = true;				
			}
		}
	}
	if (swapped) {
		return R2 + " " + R1;
	}
	return R1 + " " + R2;
}

void solve2() {
	string S[2];
	cin >> S[0] >> S[1];
	string ret = smaller(S[0], S[1], false);
	string ret2 = smaller(S[1], S[0], true);
	if (ret == "")
		cout << ret2 << endl;
	if (ret2 == "")
		cout << ret << endl;
	if (ret != "" && ret2 != "") {
		int64 a, b, diff, diff2;
		sscanf(ret.c_str(), "%lld %lld", &a, &b);
		diff = abs(a - b);
		sscanf(ret2.c_str(), "%lld %lld", &a, &b);
		diff2 = abs(a-b);
		if (diff == diff2) {
			cout << ((ret2 < ret) ? ret2 : ret) << endl;			
		} else {
			cout << ((diff2 < diff) ? ret2 : ret) << endl;			
		}
		// cout << " LLALALA " << ret << " " << ret2 << endl;
	}
}


int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve2();
  }
  
  return 0;
}
