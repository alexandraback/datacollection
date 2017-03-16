#include <stdio.h>
#include <string.h>

int dis(int a,int b)
{
	//printf("dis:\t%d\n",a*a+b*b);
	return a*a+b*b;
}
int gcd(int a,int b)
{
	a=a>0?a:-a;
	b=b>0?b:-b;
	return a<b?(gcd(b,a)):(b?gcd(b,a%b):a);
}
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D.out","w",stdout);
	int T,H,W,D;
	char buf[50];
	scanf("%d",&T);
	for(int k=1;k<=T;++k)
	{
		int cnt=0;
		scanf("%d%d%d",&H,&W,&D);
		int m=H-2,n=W-2;
//
	//	printf("%d %d\n",m,n);//////////
//
		int km=D/(2*m)+1,kn=D/(2*n)+1;

	//	printf("%d %d\n",km,kn);//////////

		int x=1,y=1;
		char *f=NULL;
		for(int i=0;i<H;++i)
		{
			scanf("%s",buf);
	//		puts(buf);
			if(f==NULL)
			{
				f=strchr(buf,'X');
				if(f!=NULL)x=i,y=f-buf;
			}
		}

	//	printf("%d %d\n",x,y);////////////

		int a,b,c,d;
		int Ds=D*D;
		for(int i=-km;i<=km;++i)
			for(int j=-kn;j<=kn;++j)
			{
				a=2*i*m;
				b=2*j*n;
				c=a+2*(n-y)+1;
				d=b+2*x-1;
				if(dis(a,b)<=Ds&&gcd(a,b)==1)++cnt;
				if(dis(a,d)<=Ds&&gcd(a,d)==1)++cnt;
				if(dis(c,d)<=Ds&&gcd(c,d)==1)++cnt;
				if(dis(c,b)<=Ds&&gcd(c,b)==1)++cnt;
	//			if(dis(a,b)<=Ds)++cnt;
	//			if(dis(a,d)<=Ds)++cnt;
	//			if(dis(c,d)<=Ds)++cnt;
	//			if(dis(c,b)<=Ds)++cnt;
			}
		printf("Case #%d: %d\n",k,cnt);
	}
	return 0;
}
