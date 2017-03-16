#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <cstdarg>

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a b, sizeof(a))

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int,int> pii;

using namespace std;

#define DBG2 0

void dbg(const char * fmt, ...)
{
#ifdef DBG1
#if DBG2
	FILE* file = stderr;
	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

struct Attack {
	int d;
	int w, e;
	ll s;

	Attack(int d, int w, int e, ll s) : d(d), w(w), e(e), s(s) {}

	bool operator < (const Attack & a) const
	{
		return d < a.d;
	}
};

const int MIN_X = -500003000;
const int MAX_X = 500003000;
const ll INF = 1LL << 60;

struct RangeTree {
	vector <ll> v, as;
	vector <int> ls, rs;
	int kk;
	int root;

	RangeTree()
	{
		kk = 1;
		while (kk < MAX_X - MIN_X + 1)
			kk *= 2;
		root = createNewNode();
		dbg("kk = %d, root = %d\n", kk, root);
	}

	int createNewNode()
	{
		int num = (int)v.size();
		dbg("created %d\n", num);
		v.push_back(0);
		as.push_back(0);
		ls.push_back(-1);
		rs.push_back(-1);
		return num;
	}

	ll getMin(int l, int r)
	{
		dbg("getMin(%d %d)\n", l, r);
		ll res = getMin(root, 0, kk - 1, l - MIN_X, r - MIN_X);
		dbg("getMin(%d %d) = %lld\n", l, r, res);
		return res;
	}

	ll getMin(int t, int L, int R, int l, int r)
	{
		dbg("getMin(%d %d %d %d %d)\n", t, L, R, l, r);
		if (R < l || r < L)
			return INF;
		if (l <= L && R <= r)
			return v[t];
		pushModify(t);
		int M = (L + R) / 2;
		return min(getMin(ls[t], L, M, l, r), getMin(rs[t], M + 1, R, l, r));
	}

	void assignMax(int l, int r, ll val)
	{
		dbg("assignMax(%d %d %lld)\n", l, r, val);
		l -= MIN_X;
		r -= MIN_X;
		assignMax(root, 0, kk - 1, l, r, val);
	}

	void assignMax(int t, int L, int R, int l, int r, ll val)
	{
		if (R < l || r < L)
			return ;
		if (l <= L && R <= r)
		{
			makeAssignMax(t, val);
			return ;
		}
		pushModify(t);
		int M = (L + R) / 2;
		assignMax(ls[t], L, M, l, r, val);
		assignMax(rs[t], M + 1, R, l, r, val);
		v[t] = min(v[ls[t]], v[rs[t]]);
	}

	void pushModify(int t)
	{
		if (ls[t] == -1)
		{
			int num = createNewNode();
			ls[t] = num;
		}
		if (rs[t] == -1)
		{
			int num = createNewNode();
			rs[t] = num;
		}
		if (as[t] != -1)
		{
			makeAssignMax(ls[t], as[t]);
			makeAssignMax(rs[t], as[t]);
			as[t] = -1;
		}
	}

	void makeAssignMax(int t, ll val)
	{
		as[t] = max(as[t], val);
		v[t] = max(v[t], val);
	}
};
/*
struct StupidRangeTree {
	vector <ll> v;
	RangeTree cleverTree;

	StupidRangeTree()
	{
		v.resize(MAX_X - MIN_X + 1, 0);
		cleverTree = RangeTree();
	}

	ll getMin(int l, int r)
	{
		ll res = INF;
		for (int i = l; i <= r; ++i)
			res = min(res, v[i - MIN_X]);
		ll cleverRes = cleverTree.getMin(l, r);
		dbg("getMin(%d %d) = %lld %lld\n", l, r, res, cleverRes);
		if (res != cleverRes)
			throw 42;
		return res;
	}

	void assignMax(int l, int r, ll val)
	{
		for (int i = l; i <= r; ++i)
			v[i - MIN_X] = max(v[i - MIN_X], val);
		cleverTree.assignMax(l, r, val);
	}
};*/


int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
	freopen(".err", "w", stderr);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d: ", ii);
		int n;
		scanf("%d", &n);
		vector <Attack> at;
		for (int i = 0; i < n; ++i)
		{
			int nn, dd, ee, ww, deltaD, deltaP, deltaS;
			ll ss;
			cin >> dd >> nn >> ww >> ee >> ss >> deltaD >> deltaP >> deltaS;
			--ee;
			for (int j = 0; j < nn; ++j)
			{
				at.push_back(Attack(dd, ww, ee, ss));
				dd += deltaD;
				ww += deltaP;
				ee += deltaP;
				ss += deltaS;
			}
		}
		dbg("Case #%d (attacks count %d)\n", ii, at.size());
		sort(at.begin(), at.end());

		int ans = 0;
		RangeTree tree;
		for (int i = 0; i < int(at.size()); )
		{
			int j = i;
			while (j < int(at.size()) && at[j].d == at[i].d)
				++j;

			dbg("i = %d, j = %d\n", i, j);
			for (int k = i; k < j; ++k)
			{
				if (tree.getMin(at[k].w, at[k].e) < at[k].s)
					++ans;
			}
			for (int k = i; k < j; ++k)
				tree.assignMax(at[k].w, at[k].e, at[k].s);
			i = j;
		}
		printf("%d\n", ans);
	}

	return 0;
}
