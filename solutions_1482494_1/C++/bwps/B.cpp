#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

int T, N, A[1100], B[1100], done[1100];

int calc() {
	int res = 0;
	while (1) {
		int stars = 0;
		FOR(i, 0, N) stars += done[i];
		if (stars == 2*N) break;
		res++;
		int vmax = -1, imax = -1;
		FOR(i, 0, N) {
			if (done[i] < 2 && B[i] <= stars) {
				stars += (2 - done[i]);
				done[i] = 2;
				goto end;
			}
		}
		FOR(i, 0, N) {
			if (done[i] == 0 && A[i] <= stars) {
				if (B[i] > vmax) {
					vmax = B[i];
					imax = i;
				}
			}
		}
		if (vmax == -1) return -1;
		stars++;
		done[imax] = 1;
end:	;
	}
	return res;
}

int main() {
	cin >> T;
	FOR(cs, 1, T+1) {
		cin >> N;
		FOR(i, 0, N) cin >> A[i] >> B[i];
		memset(done, 0, sizeof(done));
		int res = calc();
		if (res == -1) {
			cout << "Case #" << cs << ": Too Bad" << endl;
		} else {
			cout << "Case #" << cs << ": " << res << endl;
		}
	}
	return 0;
}
