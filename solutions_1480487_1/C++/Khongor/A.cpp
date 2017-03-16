#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#define sqr(x) ((x)*(x))
#define ABS(x) ((x<0)?(-(x)):(x))
#define eps (1e-9)
#define mp make_pair
#define pb push_back
#define Pair pair<int,int>
#define equal(a,b) (ABS(a-b)<eps)
using namespace std;

template<class T> string tostring(T x) { ostringstream out; out<<x; return out.str();}
long long toint(string s) { istringstream in(s); long long x; in>>x; return x; }

int dx[8]={0, 0, 1,-1, 1, 1,-1,-1};
int dy[8]={1,-1, 0, 0,-1, 1,-1, 1};
int kx[8]={1, 1,-1,-1, 2, 2,-2,-2};
int ky[8]={2,-2, 2,-2, 1,-1, 1,-1};

/////////////////////////////////////////////////////////////////////////////////////////////////////

string fileName = "A-large";

void solveSingle(int testNumber) {
	int judge[200];
	int n, sum = 0;

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &judge[i]), sum += judge[i];
	printf("Case #%d:", testNumber);
	for (int i = 0; i < n; i++) {
		double low = 0.0, up = 1.0;
		for (int iter = 0; iter < 100; iter++) {
			double mid = (low + up) / 2.0;
			double score = judge[i] + sum * mid;
			double y = mid;
			for (int j = 0; j < n; j++)
				if (j != i) {
					if (judge[j] > score) continue;
					double need = (score - judge[j]) / sum + eps;
					y += need;
				}
			if (y <= 1.0) low = mid;
			else up = mid;
		}
		printf(" %.7lf", low * 100.0);
	}
	printf("\n");
	fflush(stdout);
}

int main() {
	freopen((fileName + ".in").c_str(), "r", stdin);
	freopen((fileName + ".out").c_str(), "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		solveSingle(t);
	}
	return 0;
}
