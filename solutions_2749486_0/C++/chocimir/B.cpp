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
using namespace std;

typedef long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
int main() {
	int t; cin >> t;
	for(int x = 1; x <= t; ++x){
		string res = "";
		int a, b;
		cin >> b >> a;
		int actx = 0, acty = 0;
		int d = 1;
		if (a < 0) {
			d = -1;
		}
		int act = 1;
		while (a != 0 && actx != a) {
			if (a > 0) {
				res += "SN";
				actx++;
			}
			else {
				res += "NS";
				actx--;
			}
		}
		while (b != 0 && acty != b) {
			if (b > 0) {
				res += "WE";
				acty++;
			}
			else {
				res += "EW";
				acty--;
			}
		}
		cout << "Case #" << x << ": " << res << endl; 
	}
	return 0;
}
