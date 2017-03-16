#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

#define fo(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
	
typedef long long ll;

const int maxn=2510;

int T,n,tax[maxn];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	fo(id,1,T)
	{
		memset(tax,0,sizeof(tax));
		scanf("%d",&n);
		fo(i,1,2*n-1)
			fo(j,1,n)
			{
				int x;
				scanf("%d",&x);
				tax[x]^=1;
			}
		printf("Case #%d:",id);
		fo(i,0,2500)
			if (tax[i]) printf(" %d",i);
		printf("\n");
	}
}