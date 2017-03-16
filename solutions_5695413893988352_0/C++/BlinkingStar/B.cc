#include <bits/stdc++.h>
using namespace std;
#define PI 2*acos(0.0)
#define INF 1e8
#define EPSILON 1e-8
#ifdef DEBUG
#define DPRINTF(x) printf x
#else
#define DPRINTF(x) ;
#endif

typedef pair<int, int> pii;
typedef pair<int, pair<int, int> > piii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<bool> vb;
typedef vector<string> vs;

int testNum, n;
string A, B;

long long solve(string &a, string &b, int pos, bool big) {
	if (pos == a.size()) {
		if (!big) return 0;
		long long aa=0, bb=0;
		for (int i=0; i<a.size(); ++i) {
			aa*=10, bb*=10;
			aa+=a[i]-'0', bb+=b[i]-'0';
		}
		return aa-bb;
	}

	long long ret;

	if (a[pos] == '?') {
		if (b[pos] == '?') b[pos] = big ? '9' : '0';
		for (int i=big ? '0' : b[pos]; i<='9'; ++i) {
			a[pos] = i;
			if (ret = solve(a, b, pos+1, big || a[pos] > b[pos]))
				return ret;
		}
		return 0;
	}
	else {
		if (b[pos] != '?') {
			if (!big && b[pos] > a[pos]) return 0;
			return solve(a, b, pos+1, big || a[pos] > b[pos]);
		}
		for (int i= big ? '9' : a[pos]; i>='0'; --i) {
			b[pos] = i;
			if (ret = solve(a, b, pos+1, big || a[pos] > b[pos]))
				return ret;
		}
		return 0;
	}
}

int main () {
	scanf("%d", &testNum);
	for (int tn=1; tn<=testNum; ++tn) { 
		printf("Case #%d: ", tn);

		cin >> A >> B;
		n = A.size();

		int diff = -1;
		for (int i=0; i<n; ++i) {
			if(A[i] != '?' && B[i] != '?' && A[i] != B[i]) {
				diff = i;
				break;
			}
		}

		if (diff == -1) {
			for (int i=0; i<n; ++i) {
				if (A[i] != '?') putchar(A[i]);
				else if (B[i] != '?') putchar(B[i]);
				else putchar('0');
			}
			putchar(' ');
			for (int i=0; i<n; ++i) {
				if (A[i] != '?') putchar(A[i]);
				else if (B[i] != '?') putchar(B[i]);
				else putchar('0');
			}
			puts("");
			continue;
		}

		string tA = A, tB = B;
		long long c1 = solve(tA, tB, 0, false);
		if (!c1) c1 = 200000LL* 100000 * 100000 * 1000;
		string ttA = A, ttB = B;
		long long c2 = solve(ttB, ttA, 0, false);
		if (!c2) c2 = 200000LL* 100000 * 100000 * 1000;

		if (c1 < c2 || (c1 == c2 && tA < ttA) || (c1 == c2 && tA == ttA && tB < ttB)) {
			cout << tA << ' ' << tB << endl;
		}
		else {
			cout << ttA << ' ' << ttB << endl;
		}
	}
	return 0;
}


