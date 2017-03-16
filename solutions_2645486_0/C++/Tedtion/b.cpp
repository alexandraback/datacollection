#include <cstdio>
#include <algorithm>
#include <set>
#define NN 10008
using namespace std;
int en[NN];

bool cmp(const int a, const int b)
{
	return en[a] > en[b];
}

int main()
{
	int T,i,e,r,n;
	int ind[NN];
	int spend[NN];
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-2.out", "w", stdout);
	scanf("%d",&T);
	for (int cas=1; cas<=T; cas++)
	{
		scanf("%d%d%d",&e,&r,&n);
		for (i=0; i<n; i++) scanf("%d",&en[i]), ind[i]=i;
		stable_sort(ind, ind+n, cmp);
//	for (i=0; i<n; i++) printf("%d ", ind[i]); printf("\n");
		set<int> done;
		for (i=0; i<n; i++)
		{
			int x = ind[i];
			set<int>::iterator suf = done.lower_bound(x);
			set<int>::iterator pre = suf;
			int p,s;
			if (suf != done.end()) s = *suf;
			else s=n;
			
			if (!done.empty()){
				if (pre != done.begin()) {
					--pre;
					p = *pre;
				} else {
					p = -1;
				}
			} else {
				p = -1;
			}
			long long total = (s-p)*(long long)r;
			long long xspend;
			long long xtotal = (x-p)*(long long)r;
			if (p==-1) total=(long long)s*r+e, xtotal=x*(long long)r+e;
//	printf("x=%d t=%lld, xt=%lld\n", x, total, xtotal);
			if (s==n) {
				xspend = (xtotal>e? e:xtotal);
			} else {
				if (total>e) xspend = total-e;
				else xspend = 0;
				if (xtotal < xspend) xspend = xtotal;
				if (xspend>e) xspend = e;
			}
			spend[x] = xspend;
			done.insert(x);
		}
		long long total=0;
		for (i=0; i<n; i++) total += (long long)en[i]*spend[i];
		printf("Case #%d: %lld\n", cas, total);
	}
	return 0;
}

