#include <stdio.h>
#include <algorithm>
using namespace std;

#define INF 0x7fffffff

struct Data {
	Data(){}
	Data (int d, int w, int e, int s)
		: d(d), w(w), e(e), s(s) {}

	int d, w, e, s;

	inline bool operator < (const Data &rhs) const { return d < rhs.d; }
};

int binarysearch(int* x, int n, int v)
{
	int low=0, high=n, mid;

	while (low<=high) {
		mid=(low+high)/2;

		if (x[mid]==v) return mid;
		if (x[mid]<v) low=mid+1;
		else high=mid-1;
	}
	return -1;
}

int n;
Data data[1000010];

int xcnt, x[2000010];

int tree_start;
int tree[8000010], treev[8000010];

void renew_min(int &x, int y) { if (x>y) x=y; }
void renew_max(int &x, int y) { if (x<y) x=y; }

void tree_insert(int left, int right, int v)
{
	for (left+=tree_start, right+=tree_start; left<=right; left>>=1, right>>=1) {
		if (left&1) {
			renew_max(treev[left], v);
			for (int x=left; x; x>>=1)
				tree[x] = max(treev[x], min(tree[x<<1], tree[(x<<1)+1]));

			left++;
		}
		if (!(right&1)) {
			renew_max(treev[right], v);
			for (int x=right; x; x>>=1)
				tree[x] = max(treev[x], min(tree[x<<1], tree[(x<<1)+1]));

			right--;
		}
	}
}

int tree_find(int left, int right)
{
	int res = INF;
	int m;

	for (left+=tree_start, right+=tree_start; left<=right; left>>=1, right>>=1) {
		if (left&1) {
			m=0;
			for (int x=left; x; x>>=1)
				renew_max(m, tree[x]);
			renew_min(res, m);

			left++;
		}

		if (!(right&1)) {
			m=0;
			for (int x=right; x; x>>=1)
				renew_max(m, tree[x]);
			renew_min(res, m);

			right--;
		}
	}

	return res;
}

int main()
{
	freopen ("c.in", "r", stdin);
	freopen ("c.out", "w", stdout);

	int t, tt=0;
	scanf ("%d", &t);
	while (t--) {
		n=xcnt=0;

		int cnt;
		scanf ("%d", &cnt);
		for (int i=0; i<cnt; i++) {
			int d, nn, w, e, s, dd, dp, ds;
			scanf("%d%d%d%d%d%d%d%d", &d, &nn, &w, &e, &s, &dd, &dp, &ds);
			for (int j=0; j<nn; j++) {
				data[n++] = Data(d, w, e, s);
				x[xcnt++] = w;
				x[xcnt++] = e;
				d += dd;
				w += dp;
				e += dp;
				s += ds;
			}
		}

		sort(data, data+n);

		sort(x, x+xcnt);
		xcnt = unique(x, x+xcnt) - x;

		for (int i=0; i<n; i++) {
			data[i].w = binarysearch(x, xcnt, data[i].w);
			data[i].e = binarysearch(x, xcnt, data[i].e)-1;
		}

		for (tree_start=1; tree_start<xcnt; tree_start<<=1) ;

		for (int i=1; i<tree_start*4; i++) tree[i] = treev[i] = 0;

		int lastidx=0;
		int ans=0;
		for (int i=0; i<n; i++) {
			if (i && data[i].d != data[i-1].d) {
				for (int j=lastidx; j<i; j++)
					tree_insert(data[j].w, data[j].e, data[j].s);
				lastidx = i;
			}

			if (tree_find(data[i].w, data[i].e) < data[i].s)
				ans++;
		}

		printf ("Case #%d: %d\n", ++tt, ans);
	}

	return 0;
}
