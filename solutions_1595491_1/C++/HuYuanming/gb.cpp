/*2012.4.13*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <assert.h>
//#include <cmath>
using namespace std;
#define PL printf("%d\n", __LINE__);
#define MM(a, b) memset(a, b, sizeof(a));
#define For(i, a) for (register int i = 0; i < (a); i++)
#define Foru(i, a, b) for (register int i = (a); i < (b); i++)
#define foru(i, a, b) for (register int i = (a); i <= (b); i++)
#define ford(i, a, b) for (register int i = (a); i >= (b); i--)
#define fore(i, a, b) for (register __typeof(a) i = (a); (i) != (b); (i)++)
#define inf 1000000000
#define linf 10000000000000000LL
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define Walk(u) for (elist l = de[u]; l; l = l->next)
#define bgn begin
#define fi first
#define se second
#define ite iterator
#define All(x) (x).bgn(), (x).end()
#define sz(x) ((int)x.size())
#define pq priority_queue
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n, S, P;
int t[111];

int Max(int a) {
	return (a + 2) / 3;
}

int SMax(int a) {
	if (a == 0) return 0;
	if (a == 1) return 1;
	if (a == 2) return 2;
	if (a == 3) return 2;
	return (a + 4) / 3;
}

int Process() {
	scanf("%d%d%d", &n, &S, &P);
	For (i, n) scanf("%d", t + i);
	sort(t, t + n);
	int res = 0;
	ford (i, n - 1, 0) {	
		if (Max(t[i]) >= P) res++;
		else if (S)
			if (SMax(t[i]) >= P) {
				res++; S--;
			}
	}
	return res;
}

int main() {
	int T; scanf("%d", &T);
	For (t, T) printf("Case #%d: %d\n", t + 1, Process());
	return 0;
}
