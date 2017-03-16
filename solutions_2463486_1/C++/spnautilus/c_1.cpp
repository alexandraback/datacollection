#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

#define MAXN (50005)

typedef long long ll;
typedef pair <ll, int> PLI;

const ll MAXVAL = 10000000000000ll;

int T;
ll A, B;

int N;
ll pal[MAXN];
char s1[32];

set <PLI> S;

void add(ll a)
{
//	printf("? %I64d %I64d\n", a, a * a);
	a *= a;
	sprintf(s1, "%I64d", a);
	int len = strlen(s1);
	int i;
	for(i = 0; i + i < len; ++i)
	{
		if(s1[i] != s1[len - i - 1])
			return;
	}

//	printf("+ %I64d\n", a);
	pal[N++] = a;
}

int query(ll a)
{
	set <PLI> :: iterator si;
	si = S.lower_bound(PLI(a + 1, 0));
	--si;
	return si->second;
}

int main()
{
	int i;
	N = 0;
	for(i = 1; i < 10000; ++i)
	{
		int a = i;
		int b = 0;
		int c = 1;

		while(a > 0)
		{
			b = b * 10 + a % 10;
			a /= 10;
			c *= 10;
		}

		add(i * c + b);
		add(i * c / 10 + b % (c / 10));
	}

//	printf("%d\n", N);

	sort(pal, pal + N);
	S.insert(PLI(-1, 0));
	for(i = 0; i < N; ++i)
	{
		S.insert(PLI(pal[i], i + 1));
	}

	int tt;
	scanf("%d", &T);
	for(tt = 1; tt <= T; ++tt)
	{
		scanf("%I64d %I64d", &A, &B);

		printf("Case #%d: %d\n", tt, query(B) - query(A - 1));
	}

	return 0;
}
