#include<bits/stdc++.h>
using namespace std;
const int maxn=100+5;
char c[maxn];
int main()
{
	//freopen("B-small-attempt0.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T, cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",c);
		int l=strlen(c), res=0;
		c[l]='+';
		while(l--) if(c[l]!=c[l+1]) res++;
		printf("Case #%d: %d\n",++cas,res);
	}
	return 0;
}

