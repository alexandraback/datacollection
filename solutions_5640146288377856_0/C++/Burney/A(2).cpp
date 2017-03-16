#include<cstdio>
int T,R,C,W;
int solve()
{
	int ans=(C/W)*R+W;
	if(C%W==0)ans--;
	return ans;
}
int main()
{
	freopen("A.txt","r",stdin);
	freopen("A1.txt","w",stdout);
	scanf("%d",&T);
	int kase=1;
	while(T--)
	{
		scanf("%d%d%d",&R,&C,&W);
		printf("Case #%d: %d\n",kase++,solve());
	}
	return 0;
}
