#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#define MAX 1000000000LL
using namespace std;

long long int r, t;
int ans = 0;

long long int chk(long long int x)
{
	return 2*x*x+(2*r-1)*x;
}

void bs(long long int L, long long int R)
{
	//printf("%I64d %I64d\n", L, R);
	if(L > R) return;
	long long int mid = (L+R)/2;
	//printf("%I64d\n", chk(mid));
	if(chk(mid) <= t)
	{
		ans = mid;
		bs(mid+1LL, R);
	}
	else
	{
		bs(L, mid-1LL);
	}
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("outa2.txt", "w", stdout);
	int T;
	int tt = 1;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%I64d%I64d", &r, &t);

		long double dr = r, dt = t;
		long double lm = dt/(2.0*dr-1.0);
		
		bs(0, min((long long int)lm, MAX));

		//scanf("%d%d", &r, &t);
		
		printf("Case #%d: %d\n", tt, ans);
		tt++;
	}
	return 0;
}

