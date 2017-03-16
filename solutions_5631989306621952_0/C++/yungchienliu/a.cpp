#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;

#define S second
#define F first
#define mp make_pair
typedef pair<int, int> PII;
#define pb push_back
typedef long long ll;

int main () {
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; ++tt){
		string s;
		cin >> s;
		string ans = "";
		for(int i = 0; i < s.length(); ++i){
			if(ans.length() == 0) ans += s[i];
			else if(s[i] >= ans[0]) ans = s[i] + ans;
			else ans = ans + s[i];
		}
		cout <<"Case #" << tt<<": "<< ans <<endl;
	}
}