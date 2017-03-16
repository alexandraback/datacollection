#include <cstdio>
#include <cstring>
#define NN 9000
typedef long long Int64;

const int Max = 10000000;
Int64 all[NN];
int num;

bool palindrome(Int64 a)
{
	Int64 b=0, aa=a;
	while (aa) {
		b = b*10+aa%10;
		aa/=10;
	}
	return b == a;
}

void calall()
{
	Int64 i;
	num=0;
	for (i=1; i<=Max; i++)
	{
		if (palindrome(i) && palindrome(i*i)) all[num++] = i*i;//, printf("%lld ", i*i);
	}
}

int findind(Int64 k)
{
	int i,j,m;
	i=0; j=num-1;
	while (i<j)
	{
		m=(i+j)/2;
		if (all[m]<k) i=m+1;
		else j=m;
	}
	if (all[i]<k) return i+1;
	return i;
}

int main()
{
	int t;
	Int64 a,b;
	freopen("C-large-1.in", "r", stdin);
	freopen("c-large-1.out", "w", stdout);
	calall();
	scanf("%d",&t);
	for (int cas=1; cas<=t; cas++)
	{
		scanf("%lld%lld",&a,&b);
		int i=findind(a);
		int j=findind(b);
		if (j<num && all[j]==b) j++;
		printf("Case #%d: %d\n", cas, j-i);
	}
	return 0;
}

