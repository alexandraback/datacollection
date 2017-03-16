#include <cstdio>
#include <cstring>
#define LL long long
#define D 33
LL pd[D][2][2][2]; // already less

int a[D], b[D], k[D]; 
LL solve(int p, int la, int lb, int lk)
{
	if(p == -1) return 1;

	LL& ans = pd[p][la][lb][lk];
	if(ans != -1) return ans;

	int ma = la?1:a[p], mb = lb?1:b[p];

	ans = 0;
	for(int i=0;i<=ma;++i)
		for(int j=0;j<=mb;++j)
		{
			if(lk)
				ans += solve(p-1, la ||(i<a[p]), lb || (j<b[p]), lk);
			else
			{
				if((i&j) == k[p])
					ans += solve(p-1, la ||(i<a[p]), lb || (j<b[p]), 0);
				if((i&j) < k[p])
					ans += solve(p-1, la ||(i<a[p]), lb || (j<b[p]), 1);
			}
		}
	return ans;
}
void tobin(int v, int* b)
{
	for(int p=0;v;++p,v>>=1)
		b[p]=v&1;
}
int main()
{
	int t;scanf("%d",&t);
	for(int cs=1;cs<=t;++cs)
	{
		int A,B,K; scanf("%d%d%d",&A,&B,&K);
		memset(pd, -1, sizeof pd);
		--A,--B,--K;
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		memset(k, 0, sizeof k);
		tobin(A, a); tobin(B, b); tobin(K, k);
		printf("Case #%d: %lld\n", cs, solve(32,0,0,0));
	}
	return 0;
}
