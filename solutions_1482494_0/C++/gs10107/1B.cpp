#include <stdio.h>
int a[1001];
int b[1001];
int che[1001];
int ab[2002][1000];
int bb[2002][1000];
int ua[2002];
int ub[2002];
int main()
{
	freopen("B-small-attempt4.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,j,l,t,z,n,st,use,check,ch,max;
	scanf("%d",&t);
	for(z=1;z<=t;z++)
	{
		for(i=0;i<=2001;i++)
		{
			ua[i]=0;
			ub[i]=0;
		}
		for(i=0;i<=1000;i++)
		{
			che[i]=0;
		}
		st=0;
		use=0;
		printf("Case #%d: ",z);
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			scanf("%d",&b[i]);
			ua[a[i]]++;
			ab[a[i]][ua[a[i]]]=i;
			ub[b[i]]++;
			bb[b[i]][ub[b[i]]]=i;
		}
		while(st!=2*n)
		{
			check=0;
			for(j=st;j>=0;j--)
			{
				for(l=1;l<=ub[j];l++)
				{
					if(che[bb[j][l]]!=2)
					{
						use++;
						st+=(2-che[bb[j][l]]);
						che[bb[j][l]]=2;
						check=1;
						break;
					}
				}
				if(check==1)
				{
					break;
				}
			}
			if(check==1)
			{
				continue;
			}
			ch=0;
			max=0;
			for(j=st;j>=0;j--)
			{
				for(l=1;l<=ua[j];l++)
				{
					if(che[ab[j][l]]==0 && max<=b[ab[j][l]])
					{
						max=b[ab[j][l]];
						ch=ab[j][l];
						check=1;
					}
				}
			}
			if(check==0)
			{
				break;
			}
			else
			{
				che[ch]=1;
				use++;
				st++;
			}
		}
		if(st<2*n)
		{
			printf("Too Bad\n");
		}
		else
		{
			printf("%d\n",use);
		}
	}
	return 0;
}