#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

const int maxn = 1000;
const int maxtn = 2 * 10 * 1000 * 1000;

map<int, int> vst;

struct Interval
{
	Interval(){}
	Interval(int d, int w, int e, int s){di=d;wi=w;ei=e;si=s;}
	bool operator < (const Interval &a) const
	{
		return di<a.di;
	}
	int di, wi, ei, si;
} interval[maxn*maxn+5];

struct Node
{
	bool flag;
	int lowest;
} tree[maxtn];

int n, in, m;

int num[maxn*maxn*2 + 5];

void build(int root, int l, int r)
{
	tree[root].lowest = 0;
	tree[root].flag = false;
	if (l + 1 == r) return;
	int mid = (l + r)/2;
	build(root*2, l, mid);
	build(root*2+1, mid, r);
}

void go_down(int root, int l, int r, int mid)
{
	tree[root].flag = false;
	tree[root*2].lowest = max(tree[root*2].lowest,
			tree[root].lowest);
	tree[root*2+1].lowest = max(tree[root*2+1].lowest,
			tree[root].lowest);
	tree[root*2].flag = true;
	tree[root*2+1].flag = true;
}

bool query(int root, int l, int r, int x, int y, int val)
{
	if (y<=l || x>=r) return false;
	if (x<=l && r<=y)
		return tree[root].lowest < val;
	int mid = (l + r) / 2;
	if (tree[root].flag) go_down(root, l, r, mid);
	return query(root*2, l, mid, x, y, val) ||
		query(root*2+1, mid, r, x, y, val);
}

void insert(int root, int l, int r, int x, int y, int val)
{
	if (y<=l || x>=r) return;
	if (val <= tree[root].lowest) return;
	if (x<=l && r<=y)
	{
		tree[root].lowest = val;
		tree[root].flag = true;
		return;
	}
	int mid = (l + r) / 2;
	if (tree[root].flag) go_down(root, l, r, mid);
	insert(root*2, l, mid, x, y, val);
	insert(root*2+1, mid, r, x, y, val);
	tree[root].lowest = min(tree[root*2].lowest, tree[root*2+1].lowest);
}

void init()
{
	int i, k, di, ni, wi, ei, si, delta_di, delta_pi, delta_si;
	int d, w, e, s;
	in = 0;
	vst.clear();
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d%d%d%d%d%d%d", &di, &ni, &wi, &ei, &si,
				&delta_di, &delta_pi, &delta_si);
		d=di;
		w=wi;
		e=ei;
		s=si;
		for (k=0; k<ni; k++)
		{
			interval[in++] = Interval(d,w,e,s);
			vst[w]=1;
			vst[e]=1;
			d+=delta_di;
			w+=delta_pi;
			e+=delta_pi;
			s+=delta_si;
		}
	}
	m=0;
	for (map<int, int>::iterator it=vst.begin(); it!=vst.end(); it++)
	{
		m++;
		num[m] = it->first;
		it->second=m;
	}
	build(1, 1, m);
}

int solve()
{
	int pre, ans, i, j;
	sort(interval, interval+in);
	pre = -1;
	ans = 0;
	for (i=0; i<in; i++)
	{
		if (i==in-1 || interval[i].di != interval[i+1].di)
		{
			for (j=pre+1; j<=i; j++)
			{
				if (query(1, 1, m,
							vst[interval[j].wi], vst[interval[j].ei], interval[j].si))
				{
					ans++;
					//printf("failed d=%d w=%d e=%d s=%d\n", interval[j].di, interval[j].wi, interval[j].ei, interval[j].si);
				}

			}
			for (j=pre+1; j<=i; j++)
			{
				insert(1, 1, m,
						vst[interval[j].wi], vst[interval[j].ei], interval[j].si);
				//printf("d=%d w=%d e=%d s=%d\n", interval[i].di, interval[i].wi, interval[i].ei, interval[i].si);
			}
			pre = i;
		}
	}
	return ans;
}

int main()
{
	int T, cas;
	scanf("%d", &T);
	for (cas=1; cas<=T; cas++)
	{
		init();
		printf("Case #%d: %d\n", cas, solve());
	}
	return 0;
}
