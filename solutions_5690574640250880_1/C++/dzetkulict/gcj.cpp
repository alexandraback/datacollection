#include <stdio.h>
#include <algorithm>

using namespace std;


int main()
{
	long long tc,t,r=0;
	scanf("%lld\n",&t);
	for (tc=0;tc<t;++tc)
	{
		int r,c,m,k,i,j,ok,f;
		char x[110][110];
		scanf("%d %d %d",&r,&c,&m);
		f=r*c-m;
		for (i=0;i<r;++i) for (j=0;j<c;++j) x[i][j]='*';
		ok=0;
		if (c==1 || r==1)
		{
			if (c==1) for (i=0;i<f;++i) x[i][0]='.'; else for (i=0;i<f;++i) x[0][i]='.';
			x[0][0]='c';
			ok=1;
		} else if (f==1)
		{
			x[0][0]='c';
			ok=1;
		} else
		{
			for (int a=2;a<=r;++a) for (int b=2;b<=c;++b) 
				for (int aa=0;aa<=a;++aa) if (aa==0 || (aa>1 && b<c)) for (int bb=0;bb<=b;++bb) if (bb==0 || (bb>1 && a<r))
					if (!ok && a*b+aa+bb==f)
			{
				for (i=0;i<a;++i) for (j=0;j<b;++j) x[i][j]='.';
				for (i=0;i<aa;++i) x[i][b]='.';
				for (j=0;j<bb;++j) x[a][j]='.';
				x[0][0]='c';
				ok = 1;
			}
		}
		printf("Case #%lld:\n",tc+1);
		if (ok)
		{
			for (i=0;i<r;++i)
			{
				for (j=0;j<c;++j) printf("%c",x[i][j]);
				printf("\n");
			}
		} else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}
