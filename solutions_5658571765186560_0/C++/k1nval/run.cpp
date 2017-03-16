#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <map>
#include <hash_map>
#include <string>
#include <iomanip>
#include <vector>
#include <memory.h>
#include <queue>
#include <set>
#include <stack>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <functional>
#include <bitset>
//#pragma comment (linker, "/STACK:167177216")
using namespace std;
#define mems(A, val) memset(A, val, sizeof(A))
#define mp(a, b) make_pair(a, b)
#define all(B) (B).begin(), (B).end()
#define forn(it, from, to) for(int it = from; it < to; ++it)
#define forit (it, coll) for(auto it = coll.begin(); it != coll.end(); ++it)
const int MAX = 2147483647;
const int MAXN = 205000;
typedef long long LL;
const LL MOD = 1000000000 + 7;

struct quat{
	char cur;
	int minus;
	quat(char c, int minus = 0):cur(c),minus(minus){}
};

quat multi(quat q1, quat q2){
	if (q1.cur == '1' && q2.cur == '1')
	{
		return quat('1', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == '1' && q2.cur == 'i')
	{
		return quat('i', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == '1' && q2.cur == 'j')
	{
		return quat('j', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == '1' && q2.cur == 'k')
	{
		return quat('k', (q1.minus + q2.minus) & 1);
	}

	if (q1.cur == 'i' && q2.cur == '1')
	{
		return quat('i', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == 'i' && q2.cur == 'i')
	{
		return quat('1', (q1.minus + q2.minus + 1) & 1);
	}
	if (q1.cur == 'i' && q2.cur == 'j')
	{
		return quat('k', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == 'i' && q2.cur == 'k')
	{
		return quat('j', (q1.minus + q2.minus + 1) & 1);
	}

	if (q1.cur == 'j' && q2.cur == '1')
	{
		return quat('j', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == 'j' && q2.cur == 'i')
	{
		return quat('k', (q1.minus + q2.minus + 1) & 1);
	}
	if (q1.cur == 'j' && q2.cur == 'j')
	{
		return quat('1', (q1.minus + q2.minus + 1) & 1);
	}
	if (q1.cur == 'j' && q2.cur == 'k')
	{
		return quat('i', (q1.minus + q2.minus) & 1);
	}

	if (q1.cur == 'k' && q2.cur == '1')
	{
		return quat('k', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == 'k' && q2.cur == 'i')
	{
		return quat('j', (q1.minus + q2.minus) & 1);
	}
	if (q1.cur == 'k' && q2.cur == 'j')
	{
		return quat('i', (q1.minus + q2.minus + 1) & 1);
	}
	if (q1.cur == 'k' && q2.cur == 'k')
	{
		return quat('1', (q1.minus + q2.minus + 1) & 1);
	}
}

quat bpow(quat q, LL p)
{
	if (p == 0) return quat('1');
	quat tmp = bpow(q, p >> 1);
	tmp = multi(tmp, tmp);
	if (p & 1) tmp = multi(tmp, q);
	return tmp;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#else
    freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	LL TC;
	scanf("%I64d", &TC);
	forn(tc, 0, TC){
		int x,r,c;
		bool good;
		scanf("%d%d%d", &x,&r,&c);

		if (x == 1)
		{
			good = false;
		}
		if (x == 2)
		{
			good = (r * c) % 2 == 1;
		}
		if (x == 3)
		{
			if (r == 1 || c == 1)
			{
				good = true;
			}
			else
			{
				good = (r * c) % 3 != 0;
			}
		}
		if (x == 4)
		{
			if (r == 1 || c == 1 || r == 2 || c == 2)
			{
				good = true;
			}
			else
			{
				good = (r * c) % 4 != 0;
			}
		}

		if (x == 5)
		{
			if (r == 1 || c == 1 || r == 2 || c == 2)
			{
				good = true;
			}
			else
			{
				good = (r * c) % 5 != 0;
			}
		}

		if (x == 6)
		{
			if (r == 1 || c == 1 || r == 2 || c == 2 || (x > r && x > c))
			{
				good = true;
			}
			else
			{
				good = (r * c) % 6 != 0;
			}
		}

		if (x >= 7)
		{

				good = true;
		}
		printf("Case #%d: ", tc + 1);
		good ? printf("RICHARD\n"):printf("GABRIEL\n");

	}
	
    return 0;
}