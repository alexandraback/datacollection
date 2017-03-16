#include <cstdio>
#define max(x,y) (x>y?x:y)
#define min(x,y) (x<y?x:y)
int main()
{
	int T,x,r,c;
	bool flag;
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D.out","w",stdout);
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("%d%d%d",&x,&r,&c);
		flag=true;
		if(x>6||(r*c%x!=0)||max(r,c)<x) flag=false;
		else if(x==3&&min(r,c)<2) flag=false;
		else if(x==4&&min(r,c)<3) flag=false;
		else if(x>4&&min(r,c)<4) flag=false;
		if(flag) printf("Case #%d: GABRIEL\n",j);
		else printf("Case #%d: RICHARD\n",j);
	}
	return 0;
}
