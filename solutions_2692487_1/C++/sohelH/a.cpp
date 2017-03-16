#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

// ------------- PRE-WRITTEN CODES ---------------------------------

// defines and const
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

// input reading
template<class T>
vector<T> takeInput(int n) {
	vector<T> list;
	T a; int i;
	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
	return list;
}

// math
long long ncr[305][305] = {0};
void gen_ncr(int n) {
	int i, j;
	for(i = 0; i <= n; i++) ncr[i][0] = 1;
	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// --------------- END of PRE-WRITTEN CODES --------------------------

int main() {
	int test, cases = 1;

	cin >> test;
	for(cases = 1; cases <= test; cases++) {
		int a, n;
		cin >> a >> n;
		vector<int> v = takeInput<int>(n);
		sort(v.begin(), v.end());
		int res = n;
		int cnt = 0;
		int rem = n;
		int i;
		if( a == 1 ) {
			printf("Case #%d: %d\n", cases, res);
			continue;
		}
		for(i = 0; i < n; i++) {
			if( a > v[i] ) {
				a += v[i];
				rem--;
				if( cnt + rem < res ) res = cnt + rem;
			}
			else {
				cnt++;
				i--;
				a += (a-1);
			}

		}
		printf("Case #%d: %d\n", cases, res);
	}

	return 0;
}
