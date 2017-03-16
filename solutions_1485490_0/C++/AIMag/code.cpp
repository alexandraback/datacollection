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
int mark[1101];
int In[1101];

bool Check(int v, int z)
{
	if (mark[v]==z) return true;
	mark[v] = z;
	FOR(i, 0, SZ(gr[v]))
		if (Check(gr[v][i]-1, z))
			return true;
	return false;
}

int n, m;
int A[101], B[101];
LL a[101], b[101];

LL Calc(int na, int nb)
{
	if (na==n) return 0;
	if (nb==m) return 0;

	LL res = Calc(na+1, nb);
	LL sum = a[na];
	while (nb<m)
	{
		while (nb<m && B[nb]!=A[na]) nb++;
		if (nb==m) break;

		LL old = b[nb];
		LL tt = min(sum, b[nb]);
		sum -= tt;
		b[nb] -= tt;
		res = max(res, Calc(na+1, nb) + (a[na]-sum));
		b[nb] += tt;
		nb++;
	}

	return res;
}

LL min(LL a, LL b) { if (a<b) return a; return b; }
LL max(LL a, LL b) { if (a>b) return a; return b; }

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		scanf("%d %d", &n, &m);
		FOR(i, 0, n) scanf("%lld %d", a+i, A+i);
		FOR(i, 0, m) scanf("%lld %d", b+i, B+i);

		int na = n, nb = m;
		LL res = 0;
		if (na==1)
		{
			LL sum = 0;
			FOR(i, 0, nb)
				if (B[i] == A[0])
					sum += b[i];
			res = min(A[0], sum);
		}
		if (na==2)
		{
			FOR(p, 0, nb+1)
			{
				LL s1=0, s2=0;
				FOR(i, 0, p)
					if (B[i]==A[0])
						s1 += b[i];
				FOR(i, p, nb)
					if (B[i]==A[1])
						s2 += b[i];

				LL curr = min(A[0], s1)+min(A[1], s2);
				res = max(res, curr);
			}
		}
		if (na==3)
		{
			FOR(p1, 0, nb+1)
				FOR(p2, p1, nb+1)
				{
					LL s1=0, s2=0, s3=0;
					FOR(i, 0, p1)
						if (B[i]==A[0])
							s1 += b[i];
					FOR(i, p1, p2)
						if (B[i]==A[1])
							s2 += b[i];
					FOR(i, p2, nb)
						if (B[i]==A[2])
							s3 += b[i];
					LL curr = min(A[0], s1) + min(A[1], s2) + min(A[2], s3);
					res = max(res, curr);
				}
		}

		printf("Case #%d: %lld\n", ++ind, Calc(0, 0));
	}

	return 0;
}