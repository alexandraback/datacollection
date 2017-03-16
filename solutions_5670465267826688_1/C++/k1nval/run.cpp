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
		LL l,x;
		scanf("%I64d%I64d", &l, &x);
		char ts[10001];
		scanf("%s", &ts);
		string s = ts;
		bool good = true;
		int al = -1;
		quat cur = quat('1');
		int step = 0;
		for(int i = 0; i < x; ++i)
		{
			if (step == 3) break;
			al++;
			if (al == 4) {good = false;break;}
			for(int j = 0; j < s.size(); ++j)
			{
				cur = multi(cur, quat(s[j]));
				if (step == 0)
				{
					if (cur.cur == 'i' && cur.minus == 0)
					{
						step++;
						cur = quat('1');
						al = -1;
					}
				}
				if (step == 1)
				{
					if (cur.cur == 'j' && cur.minus == 0)
					{
						step++;
						cur = quat('1');
						al = -1;
					}
				}
				if (step == 2){
					if (cur.cur == 'k' && cur.minus == 0)
					{
						step++;
						cur = quat('1');
						for(int ll = j + 1; ll < s.size(); ++ll)
						{
							cur = multi(cur, quat(s[ll]));
						}

						quat sl = quat('1');

						for(int ll = 0; ll < s.size(); ++ll)
						{
							sl = multi(sl, quat(s[ll]));
						}

						sl = bpow(sl, x - i - 1);

						cur = multi(cur, sl);
						if (cur.cur == '1' && cur.minus == 0)
						{

						}else
						{
							good = false;
							break;
						}
					}
				}
			}
		}

		//if (cur.cur != 'k' || cur.minus != 0 || step != 2) good = false;
		if (step != 3) good = false;
		printf("Case #%d: ", tc + 1);
		good ? printf("YES\n"):printf("NO\n");

	}
	
    return 0;
}