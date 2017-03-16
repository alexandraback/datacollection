#include<algorithm>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}

string solve() {
	string s; cin >> s;
	ostringstream os;
	char c = s[0];
	deque<char> q; 
	for(int i = 0; i < s.length(); ++i) {
		if (s[i] >= c) {
			q.push_back(s[i]);
			c = s[i];
		}
		else {
			q.push_front(s[i]);
		}
	}
	while (!q.empty()) {
		char c = q.back();
		q.pop_back();
		os << c;
	}
	return os.str();
}

int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; ++x){
		cout << "Case #" << x << ": " << solve() << endl;//result 
	}
	return 0;
}
