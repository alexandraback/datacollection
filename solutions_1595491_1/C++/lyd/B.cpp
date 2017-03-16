#include<cstdio>

const int mx=110;

int n,s,p;
int a[mx];

int main()
{
	int i;
	int t,ca=0;
	scanf("%d",&t);
	while(t--)
	{
		int mp=0,msp=0;
		scanf("%d%d%d",&n,&s,&p);
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if((a[i]+2)/3>=p) mp++;
			else if(a[i]>1 && (a[i]+4)/3>=p) msp++;
		}
		if(msp > s) msp=s;
		printf("Case #%d: %d\n",(++ca),mp+msp);
	}

	return 0;
}
