#define _HAS_CPP0X 0
#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)

bool isVowel(char c){
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
void Go(){
	string s;
	int n;
	cin >> s >> n;
	for (int i = 0; i < s.size(); i++){
		if (isVowel(s[i])){
			s[i] = 0;
		}
		else{
			s[i] = 1;
		}
	}
	vector<LL> dp(s.size());	
	int last_count = 0;
	for (int i = 0; i < s.size(); i++){
		if (s[i]){
			last_count++;
		}
		else{
			last_count = 0;
		}
		if (last_count >= n){
			dp[i] = i - n + 2;
		}
		if (i > 0 && dp[i - 1] > 0){
			dp[i] = max(dp[i], dp[i - 1]);
		}
	}
	LL res = accumulate(dp.begin(), dp.end(), LL(0));
	cout << res;
}
void Go1(){
	string s;
	int n;
	cin >> s >> n;
	for (int i = 0; i < s.size(); i++){
		if (isVowel(s[i])){
			s[i] = 0;
		}
		else{
			s[i] = 1;
		}
	}
	int res = 0;
	for (int i = 0; i < s.size(); i++){
		for (int j = i + n; j <= s.size(); j++){
			int k = i;
			while (k < j){
				while (k < j && !s[k]){
					k++;
				}
				int sk = k;
				while (k < j && s[k]){
					k++;
				}
				if (k - sk >= n){
					res++;
					break;
				}				
			}
		}
	}
	cout << res;
}

int main(){
	const string task = "A";
	const string folder = "gcj/2013/1C";
	const int attempt = -1;
	const bool dbg = false;


	if (dbg){
		freopen("inp.txt", "r", stdin);
	}
	else{
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t){	
		printf("Case #%d: ", i + 1);
		Go();
		printf("\n");
	}
	return 0;
}