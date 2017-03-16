#include <stdio.h>

const int L=1000100;
int TC,tc;
int l,n,t;
int c[L],f[L];
char a[L];
__int64 s;

int main()
{
	int i;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	for(scanf("%d",&TC),tc=1;tc<=TC;++tc)
	{
		scanf("%s%d",a,&n);
		for(l=0;a[l];++l);
		for(i=0;i<l;++i)
			c[i]=0;
		t=0;
		for(i=0;i<l;++i)
		{
			if(a[i]=='a' || a[i]=='e' || a[i]=='i' || a[i]=='o' || a[i]=='u') t=0;
			else
			{
				++t;
				if(t>=n) 
					c[i]=1;
			}
		}
		s=0;
		t=l;
		for(i=l-n;i>=0;--i)
		{
			if(c[i+n-1]) t=i+n-1;
			s+=l-t;
		}
		printf("Case #%d: %I64d\n",tc,s);
	}
	return 0;
}