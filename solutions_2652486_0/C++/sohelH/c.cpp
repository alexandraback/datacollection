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

int R, N, M, K;
vector<int> v;

bool possible(int a, int b, int c) {
	int A[5];
	A[0] = a; A[1] = b; A[2] = c;

	int i, j, k;

	for(i = 0; i < v.size(); i++) {
		bool yes = false;
		for(j = 0; j < 8; j++) {
			int p = 1;
			for(k = 0; k < 3; k++) {
				if( j & (1<<k) )
				p *= A[k];
			}
			if( p == v[i] ) yes = true;
		}
		if(yes == false) return false;
	}
	return true;
}

int main() {
	int test, cases = 1;
	cin >> test;
	while(test--) {
		printf("Case #1:\n");
		cin >> R >> N >> M >> K;

		while(R--) {

			v = takeInput<int>(K);

			int i, j, k;
			vector< vector<int> > res;
			for(i = 2; i <= M; i++)
				for(j = i; j <= M; j++)
					for(k = j; k <= M; k++) {
						bool yes = possible(i, j, k);
						if(yes) {
							vector<int> vv;
							vv.push_back(i);
							vv.push_back(j);
							vv.push_back(k);
							res.push_back(vv);
						}
					}
			if( res.size() == 1 ) cout << res[0][0] << res[0][1] << res[0][2] << endl;
			else if( res.size() == 0 ) cout << "222\n";
			else {
				int r = rand() % res.size();
				cout << res[r][0] << res[r][1] << res[r][2] << endl;
			}
		}

	}
	return 0;
}
