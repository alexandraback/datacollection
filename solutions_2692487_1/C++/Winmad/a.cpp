#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MM(a , x) memset(a , x , sizeof(a))
#define sqr(x) ((x) * (x))
#define abs(x) ((x > 0) ? (x) : -(x))
#define REP(i , n) for ((i) = 0; (i) < (n); ++(i))
#define FOR(i , a , b) for ((i) = (a); (i) <= (b); ++(i))
#define FORD(i , a , b) for ((i) = (a); (i) >= (b); --(i))
typedef long long LL;

const int maxn = 108;

int n , m , T , testcase;
LL ans , A , data[maxn];

void init()
{
	scanf("%I64d%d" , &A , &n);
	int i;
	FOR (i , 1 , n) scanf("%I64d" , &data[i]);
	sort(data + 1 , data + n + 1);
}

LL solve(LL now , int pos)
{
	if (pos > n) return 0;
	int i , j , k;
	FOR (i , pos , n)
	{
		if (now <= data[i]) break;
		now += data[i];
	}
	LL t1 , t2;
	pos = i;
	if (pos > n) return 0;
	t2 = n - i + 1;
	t1 = 0;
	while (now <= data[pos])
	{
		now += now - 1;
		t1++;
	}
	t1 += solve(now , pos);
	return min(t1 , t2);
}

void work()
{
	if (A == 1) ans = n;
	else ans = solve(A , 1);
	printf("Case #%d: %I64d\n" , testcase , ans);
}

int main()
{
	freopen("in.txt" , "r" , stdin);
	freopen("out.txt" , "w" , stdout);
	scanf("%d" , &T);
	FOR (testcase , 1 , T)
	{
		init();
		work();
	}
}
