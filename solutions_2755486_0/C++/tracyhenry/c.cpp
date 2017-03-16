#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <cstring>
#include <string>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define LL long long
#define pi 3.1415926535897932384626433 
#define sqr(a) ((a)*(a))

using namespace std;

struct node
{
	int d, x, y, s;
	
	node() {}
	node(int d_, int x_, int y_, int s_) : d(d_), x(x_), y(y_), s(s_) {}
	
	int operator < (const node &o) const
	{
		return d < o.d;
	}
};

struct btre
{
	int l, r, mid, lc, rc;
	int f, min;
}tree[5000000];

map<int, int> M;
map<int, vector<node> > List;
vector<node> attack;
int n, L, tot;

void buildtree(int a, int x, int y)
{
	tree[a].l = x, tree[a].r = y;
	tree[a].mid = (x + y) / 2;
	tree[a].f = tree[a].min = 0;
	if (x != y)
	{
		tree[a].lc = ++ tot, buildtree(tree[a].lc, x, tree[a].mid);
		tree[a].rc = ++ tot, buildtree(tree[a].rc, tree[a].mid + 1, y);
	}
}

void refresh(int x)
{
	if (! tree[x].f) return ;
	if (tree[x].l < tree[x].r)
	{
		int lc = tree[x].lc, rc = tree[x].rc;
		tree[lc].f = max(tree[lc].f, tree[x].f);
		tree[lc].min = max(tree[lc].min, tree[lc].f);
		tree[rc].f = max(tree[rc].f, tree[x].f);
		tree[rc].min = max(tree[rc].min, tree[rc].f);
	}
	tree[x].f = 0;
}
		
int ask(int x, int l, int r)
{
	refresh(x);
	if (l <= tree[x].l && tree[x].r <= r)
		return tree[x].min;
	int ans = 1 << 30;
	if (l <= tree[x].mid) ans = min(ans, ask(tree[x].lc, l, r));
	if (r >  tree[x].mid) ans = min(ans, ask(tree[x].rc, l, r));
	return ans;
}

void insert(int x, int l, int r, int s)
{
	refresh(x);
	if (l <= tree[x].l && tree[x].r <= r)
	{
		tree[x].f = max(tree[x].f, s); 
		tree[x].min = max(tree[x].min, tree[x].f);
		return ;
	}
	if (l <= tree[x].mid) insert(tree[x].lc, l, r, s);
	if (r >  tree[x].mid) insert(tree[x].rc, l, r, s);
	tree[x].min = min(tree[tree[x].lc].min, tree[tree[x].rc].min);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
#endif
	int T; cin >> T;
	for (int t = 1; t <= T; t ++)
	{
		cout << "Case #" << t << ": ";
		scanf("%d", &n);
		M.clear(); attack.clear();
		for (int i = 1; i <= n; i ++)
		{
			int d, N, w, e, s, delta_d, delta_p, delta_s;
			cin >> d >> N >> w >> e >> s >> delta_d >> delta_p >> delta_s;
			for (int j = 1; j <= N; j ++)
			{
				M[w] = M[e] = 0;
				attack.push_back(node(d, w, e, s));
				d += delta_d;
				w += delta_p, e += delta_p;
				s += delta_s;
			}
		}
		
		//build the segment tree
		L = tot = 0; tot ++;
		for (map<int, int>::iterator i = M.begin(); i != M.end(); i ++)
			i->second = ++ L;
		buildtree(1, 1, L - 1);
		//sort
		sort(attack.begin(), attack.end());
		List.clear();
		for (int i = 0; i < attack.size(); i ++)
			List[attack[i].d].push_back(attack[i]);
		//work
		int ans = 0;
		for (map<int, vector<node> >::iterator k = List.begin(); k != List.end(); k ++)
		{
			for (int i = 0; i < (k->second).size(); i ++)
			{
				node cur = (k->second)[i];
				if (ask(1, M[cur.x], M[cur.y] - 1) < cur.s) ans ++;
			}
			
			for (int i = 0; i < (k->second).size(); i ++)
			{
				node cur = (k->second)[i];
				insert(1, M[cur.x], M[cur.y] - 1, cur.s);
			}
			
/*
			if (k->first == 1)			
			for (int i = 1; i <= tot; i ++)
				cout << tree[i].l << " " << tree[i].r << " : " << tree[i].f << " " << tree[i].min << endl;		
				
			if (k->first == 1)
//				cout << tree[1].min << " " << tree[1].f << endl;
				cout << ask(1, 1, 5) << endl;	   */

 		}
		cout << ans << endl;
	}
	return 0;
}
