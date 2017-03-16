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
int t[3000]; 
int solve() {
	int n; cin >> n;
	for(int i = 0; i < 3000; ++i) {
		t[i] = 0;
	}
	for(int i = 0; i < 2*n-1; ++i) {
		for(int j = 0; j < n; ++j) {
			int k; cin >> k;
			t[k] += 1;
		}
	}
	for(int i = 0; i < 3000; ++i) {
		if (t[i] % 2) {
			cout << " " << i;
		}
	}
	return 0;
}

int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; ++x){
		cout << "Case #" << x << ":";
	 	solve(); 
		cout << endl;//result 
	}
	return 0;
}
