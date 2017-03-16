#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
#define LL long long

struct S {
	int a,id;
} s[10005];

int e,r,n;
set<int> ss;
LL need[10005],used[10005];

bool cmp(S a,S b) {
	if (a.a == b.a) return a.id < b.id;
	return a.a > b.a;
}

int main() {
	int tc;
	scanf("%d",&tc);
	for (int t=1; t<=tc; t++) {
		ss.clear();
		scanf("%d%d%d",&e,&r,&n);
		ss.insert(-1);
		ss.insert(n);
		for (int i=0; i<n; i++) {
			scanf("%d",&s[i].a);
			s[i].id = i;
		}
		sort(s,s+n,cmp);
		LL ret = 0;
		memset(need,-1,sizeof(need));
		for (int i=0; i<n; i++) {
			set<int>::iterator it;
			it = ss.lower_bound(s[i].id);
			int hi = *it;
			it--;
			int lo = *it;

			LL res = e;
			LL hv = e,nd = 0;
			if (lo != -1) {
				//res = min(res,(s[i].id-lo)*1LL*r+need[lo]-used[lo]);
				hv = (s[i].id-lo)*1LL*r+need[lo]-used[lo];
				hv = min(hv,e*1LL);
			}

			if (hi != n) {
				//res = min(res,res-(need[hi]-r*1LL*(hi-s[i].id)));
				//need[s[i].id] = need[hi]-r*1LL*(hi-s[i].id);
				nd = need[hi]-r*1LL*(hi-s[i].id);
				nd = max(nd,0LL);
			}
			used[s[i].id] = min(hv-nd,e*1LL);
			need[s[i].id] = min(e*1LL,nd+used[s[i].id]);

			//printf("%d %d (%d) %lld need: %lld\n",lo,hi,s[i].id,used[s[i].id],need[s[i].id]);
			ret += used[s[i].id]*1LL*s[i].a;
			ss.insert(s[i].id);
		}
		printf("Case #%d: %lld\n",t,ret);
	}
	return 0;
}
