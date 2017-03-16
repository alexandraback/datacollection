#include <iostream>
#include <memory.h>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

#define SZ(a) (int)(a).size()
#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; ++i)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; --i)
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;

struct item {
	item *L, *R;
	int val, pr, cnt;
	item(int _val, int _pr) {
		val = _val; pr = _pr;
	}
};

typedef item* pitem;

void reCalc(pitem& root)
{
	if (!root) return;
}

void merge(pitem& T, pitem L, pitem R)
{
	if (!L) T = R; else
		if (!R) T = L; else
			if (L->pr > R->pr) {
				merge(L->R, L->R, R); T = L;
			}
			else {
				merge(R->L, L, R->L); T = R;
			}
	reCalc(R);
}

void printTree(pitem& root)
{
	if (!root) return;
	printTree(root->L);
	printf("%d ", root->val);
	printTree(root->R);
}

vector<VI> gr;
int mark[1001];
int In[1001];

bool Check(int v, int z)
{
	if (mark[v]==z) return true;
	mark[v] = z;
	FOR(i, 0, SZ(gr[v]))
		if (Check(gr[v][i]-1, z))
			return true;
	return false;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		int n; scanf("%d", &n);
		gr.clear(); gr.resize(n); FILL(In, 0);
		FOR(i, 0, n)
		{
			int m; scanf("%d", &m);
			gr[i].resize(m);
			FOR(j, 0, m) {
				scanf("%d", &gr[i][j]);
				In[gr[i][j]-1]++;
			}
		}

		FILL(mark, 0);

		bool fl = false;
		int tmp = 0;
		FOR(i, 0, n)
			if (!In[i])
				if (Check(i, ++tmp)) {
					fl = true; break;
				}

			printf("Case #%d: %s\n", ++ind, (fl?"Yes":"No"));
	}

	return 0;
}