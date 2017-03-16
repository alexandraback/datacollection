#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std; 

#define DEBUG(x) cerr << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

const int INF = 1<<29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return n & two(b); }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while(n && ++res) n-=n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MAX = 1000;
const ll SHIFT = 1000000000LL, MAXB = 2147483648LL;
struct Tribe
{
	int d, n, s;
	ll w, e;
	int dd, dp, ds;
	bool operator<(const Tribe & t) const { return d > t.d; }
};

struct Node
{
	Node(int _h): left(NULL), right(NULL), height(_h), height2(_h) {}

	Node * left, * right;
	int height, height2;
};

void del(Node * node)
{
	if (node->left) del(node->left);
	if (node->right) del(node->right);
	delete node;
}

int get(ll int_be, ll int_en, ll be, ll en, Node * node)
{
	if ((int_be == be && int_en == en) || node->left == NULL)
		return node->height;
	ll m = (int_be + int_en) / 2;
	int res = 1000000000;
	if (be < m)
		res = min(res, get(int_be, m, be, min(m, en), node->left));
	if (m < en)
		res = min(res, get(m, int_en, max(m, be), en, node->right));
	return res;
}

void update(ll int_be, ll int_en, ll be, ll en, Node * node, int h)
{
	if (node->height >= h)
		return;
	if (int_be == be && int_en == en && !node->left)
	{
		node->height = node->height2 = h;
		return;
	}

	ll m = (int_be + int_en) / 2;
	if (!node->left)
	{
		node->left = new Node(node->height);
		node->right = new Node(node->height);
	}

	if (be < m)
		update(int_be, m, be, min(m, en), node->left, h);
	if (m < en)
		update(m, int_en, max(m, be), en, node->right, h);
	node->height = min(node->left->height, node->right->height);
	node->height2 = max(node->left->height2, node->right->height2);

	if (node->height == node->height2)
	{
		del(node->left);
		del(node->right);
		node->left = node->right = NULL;
	}
}

bool brute = false;
int brutes[1000];

void Solve(int tc)
{
	DEBUG(tc)
	memset(brutes, 0, sizeof(brutes));

	int N;
	scanf("%d", &N);

	priority_queue<Tribe> manage;
	REP(i, N)
	{
		Tribe t;
		scanf("%d%d%lld%lld%d %d%d%d", &t.d, &t.n, &t.w, &t.e, &t.s, &t.dd, &t.dp, &t.ds);
		t.e += SHIFT;
		t.w += SHIFT;
		manage.push(t);
	}

	int result = 0;
	Node * root = new Node(0);
	while (!manage.empty())
	{
		int day = manage.top().d;
		vector<Tribe> used;
		while (!manage.empty() && manage.top().d == day)
		{
			used.push_back(manage.top());
			manage.pop();
		}

		REP(i, used.size())
		{
			bool cond1 = (get(0, MAXB, used[i].w, used[i].e, root) < used[i].s);
			if (cond1)
				++result;

			if (brute)
			{
				bool cond2 = false;
				int be = used[i].w-SHIFT+500, en = used[i].e-SHIFT+500;
				FOR(j, be, en-1)
					if (brutes[j] < used[i].s)
						cond2 = true;
				
				if (cond1 != cond2)
					DEBUG("ERROR");
				//if (cond2) ++result;
			}
		}

		// update
		REP(i, used.size())
		{
			update(0, MAXB, used[i].w, used[i].e, root, used[i].s);
			if (brute)
			{
				int be = used[i].w-SHIFT+500, en = used[i].e-SHIFT+500;
				FOR(j, be, en-1)
					chmax(brutes[j], used[i].s);
			}
		}

		REP(i, used.size())
		{
			used[i].d += used[i].dd;
			used[i].w += used[i].dp;
			used[i].e += used[i].dp;
			used[i].s += used[i].ds;
			used[i].n -= 1;
			if (used[i].n)
				manage.push(used[i]);
		}
	}
	del(root);

	printf("Case #%d: %d\n", tc, result);
}

int main()
{
	int T;
	scanf("%d\n", &T);
	FOR(tc,1,T) Solve(tc);

	return 0;
}
