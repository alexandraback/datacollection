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

typedef unsigned long long LL;
typedef long double LD;

#define dprintf(...) fprintf(stderr, __VA_ARGS__)

int cond = 1;
#define DB(X) {if(cond){cerr<<"Line:"<<__LINE__<<", "<<#X<<" = "<<X<<endl;}}
long long func(LL r, LL y) {
	return 2*r*y + 2*y*(y-1)+y;
}
long long find(long long r, long long t) {
	LL b = 1, e = (LL) sqrt(t/2);
	while (b <= e) {
		LL m = (b + e) / 2;
		LL p = func(r, m);
	 	if (p	< t) {
			b = m + 1;
		}
		else if (p > t)  {
			e = m - 1;
		}
		else {
			return m;
		}
	}
	return b - 1;
}
int main() {
	int tt; cin >> tt;
	long long r, t;
	for(int x = 1; x <= tt; ++x){
		cin >> r >> t;
		cout << "Case #" << x << ": " << find(r, t) << endl;//result 
	}
	return 0;
}
