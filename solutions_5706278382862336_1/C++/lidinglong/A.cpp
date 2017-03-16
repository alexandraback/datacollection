#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

void fileOpen()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
}

long long gcd (long long u, long long v)
{
    if ((u == 0) || (v == 0)) return u + v;
    return gcd(v, u % v);
}

int main()
{
    fileOpen();
    int task;
    scanf("%d\n", &task);
    for (int t = 1; t <= task; ++t)
    {
	long long P, Q;
	printf("Case #%d: ", t);
	scanf("%lld/%lld\n", &P, &Q);
	long long mid = gcd(P, Q);
	P /= mid, Q /= mid;
	int ans = 0;
	for (; Q != 1; Q = Q / 2)
	{
	    if ((Q % 2) == 1)
	    {
		ans = -1;
		break;
	    }
	    if (P >= Q / 2)
	    {
		++ans;
		break;
	    }
	    ++ans;
	}
	for (; Q != 1; Q = Q / 2)
	    if ((Q % 2) == 1)
	    {
		ans = -1;
		break;
	    }
	if (ans >= 0)
	    printf("%d\n", ans);
	else printf("impossible\n");
    }
    return 0;
}
