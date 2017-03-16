#include <stdio.h>
#include <algorithm>
using namespace std;
double NB[1000],KB[1000],NB2[1000],KB2[1000];

int main()
{
	freopen("D-large.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,tests,tcount,n,ns,ns2;
	scanf("%d",&tests);
	for(tcount=0;tcount<tests;tcount++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%lf",&NB[i]);
			NB2[i]=NB[i];
		}
		for(i=0;i<n;i++)
		{
			scanf("%lf",&KB[i]);
			KB2[i]=KB[i];
		}

		ns=n;
		ns2=0;
		sort(NB,NB+n);
		sort(KB,KB+n);
		sort(NB2,NB2+n);
		sort(KB2,KB2+n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(KB[j]>0&&NB[i]>0&&KB[j]>NB[i])
				{
					KB[j]=0;
					NB[i]=0;
					ns--;
				}
			}
		}
		for(i=n-1;i>=0;i--)
		{
			for(j=n-1;j>=0;j--)
			{
				if(KB2[i]>0&&NB2[j]>0&&NB2[j]>KB2[i])
				{
					KB2[i]=0;
					NB2[j]=0;
					ns2++;
				}
			}
		};
		printf("Case #%d: %d %d\n",tcount+1,ns2,ns);
	}
    return 0;
}
