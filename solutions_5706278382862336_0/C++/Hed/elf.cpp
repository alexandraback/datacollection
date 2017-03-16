#include<cstdio>
#include<algorithm>
#define fo(i,a,b) for (int i = a;i <= b;i ++)

using namespace std;
typedef long long LL;

const LL B = 1ll << 40;
int T;
LL P,Q;
char c;

LL gcd(LL x,LL y)
{
	if (!y) return x; else return gcd(y,x%y);
}

int main()
{
	freopen("elf.in","r",stdin);
	freopen("elf.out","w",stdout);
	scanf("%d",&T);
	fo(cs,1,T)
	{
		scanf("%I64d%c%I64d",&P,&c,&Q);
		LL d = gcd(P,Q);
		P /= d; Q /= d;
		printf("Case #%d: ",cs);
		if (P > Q || Q != (Q & (-Q))) printf("impossible\n");
		else
		{
			int c = 0,ans = 0;
			for (LL k = 1;k < Q;k <<= 1) c ++;
			fo(i,1,40-c) P = P * 2;
			for (LL k = 1;k <= P;k <<= 1) ans ++;
			printf("%d\n",41-ans);
		}
	}
	return 0;
}
