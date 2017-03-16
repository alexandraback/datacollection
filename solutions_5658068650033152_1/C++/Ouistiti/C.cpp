#include <cstdio>
#include <algorithm>

using namespace std;

int dy[1001];

int main ()
{
	freopen ("C-large.in","r",stdin);
	freopen ("C-large.out","w",stdout);
	int n,m,k,t,mi;
	scanf ("%d",&t);
	for (int g=1;g<=t;g++)
	{
		scanf ("%d %d %d",&n,&m,&k);
		for (int i=0;i<=k;i++)
			dy[i] = i;
		for (int i=1;i<=n-2;i++)
			for (int j=1;j<=m-2;j++)
			{
				dy[2*i+2*j+i*j] = min (dy[2*i+2*j+i*j],2*i+2*j);
				if (i!=1&&j!=1)
					dy[2*i+2*j+i*j-2] = min (dy[2*i+2*j+i*j-2],2*i+2*j-1);
				if ((i>=2||j>=2)&&(i!=2||j!=2))
					dy[2*i+2*j+i*j-4] = min (dy[2*i+2*j+i*j-4],2*i+2*j-2);
				if (i>2&&j>2)
				{
					dy[2*i+2*j+i*j-6] = min (dy[2*i+2*j+i*j-6],2*i+2*j-3);
					dy[2*i+2*j+i*j-8] = min (dy[2*i+2*j+i*j-8],2*i+2*j-4);
				}
			}
		for (int i=0;i<k;i++)
		{
			if (dy[i+1]-dy[i]>1)
				dy[i+1] = dy[i]+1;
			//if (dy[i]>dy[i+1])
				//dy[i] = dy[i+1];
		}
		printf ("Case #%d: %d\n",g,dy[k]);
	}
}
