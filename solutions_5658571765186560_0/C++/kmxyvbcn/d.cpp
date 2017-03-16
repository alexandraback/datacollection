#include<cstdio>

int X,R,C;

int main()
{
	int TestCase,Case,_;
	//freopen("d.in","rb",stdin);
	//freopen("d.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d%d%d",&X,&R,&C);
		if((R*C)%X)
		{
			printf("Case #%d: RICHARD\n",Case);
			continue;
		}
		if(X>=8)
		{
			printf("Case #%d: RICHARD\n",Case);
			continue;
		}
		if(R<C){_=R;R=C;C=_;}
		if(X>R)
		{
			printf("Case #%d: RICHARD\n",Case);
			continue;
		}
		if(X==1||(X==3&&C==2)||(X==2&&C==1))
		{
			printf("Case #%d: GABRIEL\n",Case);
			continue;
		}
		if((X+1)/2>=C)
		{
			printf("Case #%d: RICHARD\n",Case);
			continue;
		}
		printf("Case #%d: GABRIEL\n",Case);
	}
	return 0;
}
