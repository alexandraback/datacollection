#include <iostream>
#include <stdio.h>
using namespace std;

__int64 gcd(__int64 a,__int64 b)
{
	return b==0?a:gcd(b,a%b);
}
__int64 num[30];

void solve(__int64 P, __int64 Q)
{
	__int64 x = gcd(P, Q);
	P = P/x; Q = Q/x;
	__int64 temp = Q;
	while (temp %2 == 0)
	{
		temp = temp / 2;
	}
	if (temp != 1)
	{
		printf("impossible\n");
		return;
	}
	__int64 num = 0;
	temp = Q;
	while (temp > P)
	{
		temp = temp/2;
		num++;
	}
	printf("%I64d\n",num);
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
// 	num[0] = 1;
// 	for (int i = 1; i < 14; ++i)
// 	{
// 		num[i] = num[i-1] << 1;
// 		cout << num[i] << endl;
// 	}
	int T;
	__int64 P,Q;
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i)
	{
		scanf("%I64d/%I64d",&P, &Q);
		printf("Case #%d: ",i);
		solve(P,Q);
	}
	return 0;
}