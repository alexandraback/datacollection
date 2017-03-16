#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long

int r,n,m,k,a[15],now[15],end;
set<int> s;

void doit(int at,int mi) {
	if (end) return;
	if (at == n) {
		s.clear();
		for (int i=0; i<(1<<n); i++) {
			int pro = 1;
			for (int j=0; j<n; j++)
				if ((1<<j) & i) pro *= now[j];
			s.insert(pro);
		}
		int ok = 1;
		for (int i=0; i<k; i++)
			if (s.find(a[i]) == s.end()) { ok = 0; break; }
		if (ok) {
			for (int i=0; i<n; i++) printf("%d",now[i]);
			puts("");
			end = 1;
		}
		return;
	}
	for (int i=mi; i<=m; i++) {
		now[at] = i;
		doit(at+1,i);
	}
}

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		printf("Case #%d:\n",t);
		scanf("%d%d%d%d",&r,&n,&m,&k);
		while (r--) {
			end = 0;
			for (int i=0; i<k; i++)
				scanf("%d",&a[i]);
			doit(0,2);
		}
	}
	return 0;
}
