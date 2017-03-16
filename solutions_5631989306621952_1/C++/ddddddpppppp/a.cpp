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

const int maxn=11000;

int T,l,r;
char c,ans[maxn];

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	fo(j,1,T)
	{
		while (c=getchar(),c<'A'||c>'Z');
		ans[l=r=2000]=c;
		while (c=getchar(),c>='A'&&c<='Z')
		{
			if (c>=ans[l]) ans[--l]=c;
			else ans[++r]=c;
		}
		printf("Case #%d: ",j);
		fo(i,l,r) printf("%c",ans[i]);
		printf("\n");
	}
}