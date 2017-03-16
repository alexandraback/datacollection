#include <cstdio>

FILE *in,*out;

long long n,m;
int c[60];

int main ()
{
	int T,t;

	in = fopen("input.txt","r");
	out = fopen ("output.txt","w");

	fscanf (in,"%d",&T);
	for (t=1;t<=T;t++)
	{
		int i,j,s;
		long long l;

		fscanf (in,"%lld%lld",&n,&m);
		fprintf (out, "Case #%d: ",t);
		for (l=1,i=2;i<n;i++,l*=2);
		if (l<m)
		{
			fprintf (out, "IMPOSSIBLE\n");
			continue;
		}
		for (i=1;i<=n;i++)
			c[i]=0;
		m--,c[n]=c[1]=1;
		for (i=n-1;i>1;i--)
		{
			c[i] = m%2;
			m/=2;
		}
		fprintf (out, "POSSIBLE\n");
		for (i=1;i<=n;i++)
		{
			for (j=1;j<=n;j++)
			{
				if (i>1) fprintf (out, "%d",j>i);
				else fprintf (out, "%d",(j>i)&&c[i]&&c[j]);
			}
			fprintf (out, "\n");
		}
	}

	return 0;
}