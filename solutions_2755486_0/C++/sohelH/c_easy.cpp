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

struct node {
	int left, right;
	int s;
};

vector<node> V[1000000];
int height[1000000];

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases = 1; cases <= test; cases++) {
		int N;
		vector<int> di, ni, wi, ei, si, ddi, dpi, dsi;

		cin >> N;
		for(int i = 0; i < N; i++) {
			int a;
			cin >> a; di.push_back(a);
			cin >> a; ni.push_back(a);
			cin >> a; wi.push_back(a);
			cin >> a; ei.push_back(a);
			cin >> a; si.push_back(a);
			cin >> a; ddi.push_back(a);
			cin >> a; dpi.push_back(a);
			cin >> a; dsi.push_back(a);
		}

		for(int i = 0; i < 1000000; i++)
			V[i].clear();

		int minv = inf;
		for(int i = 0; i < N; i++) {
			int dd = di[i];
			int ww = wi[i];
			int ee = ei[i];
			int ss = si[i];
			minv = min(minv, ww);
			while(ni[i]--) {
				node A;
				A.left = ww;
				A.right = ee;
				A.s = ss;
				V[dd].push_back(A);
				minv = min(minv, ww);
				dd += ddi[i];
				ww += dpi[i];
				ee += dpi[i];
				ss += dsi[i];
			}
		}
		int res = 0;
		int i, j;
		for(i = 0; i < 1000000; i++)
			height[i] = 0;

		// normalize

		for(i = 0; i < 1000000; i++)
			for(j = 0; j < V[i].size(); j++) {
				V[i][j].left += minv * (-1);
				V[i][j].right += minv * (-1);
			}

		for(i = 0; i < 1000000; i++) {
			if( V[i].size() == 0 ) continue;

			for(j = 0; j < V[i].size(); j++) {
				bool yes = false;
				for(int k = V[i][j].left; k < V[i][j].right; k++)
					if( V[i][j].s > height[k] ) yes = true;
				if(yes) res++;
			}

			// fix height
			for(j = 0; j < V[i].size(); j++) {
				for(int k = V[i][j].left; k < V[i][j].right; k++)
					if( V[i][j].s > height[k]) height[k] = V[i][j].s;
			}
		}
		printf("Case #%d: %d\n", cases, res);

	}
	return 0;
}
