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

int testNum;
int main () {
	scanf("%d", &testNum);
	for (int tn=1; tn<=testNum; ++tn) { 
		int n, ans = 0;
		scanf("%d", &n);
		set<string> a, b;
		for (int i=0; i<n; ++i) {
			string s, ss;
			cin >> s >> ss;
			if (a.find(s) != a.end() && b.find(ss) != b.end())
				++ans;
			a.insert(s), b.insert(ss);
		}
		printf("Case #%d: %d\n",tn, ans);
	}
	return 0;
}


