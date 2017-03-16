#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen("largeA.in","r",stdin);
//	freopen("largeA.out","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--)
	{
		int R,C,W;
		scanf("%d%d%d",&R,&C,&W);
		printf("Case #%d: %d\n",++kase,(C/W)*R+W-1+((C%W)?1:0));
	}
}
