#include <stdio.h>
#include <math.h>
int main()
{

freopen("test2.in", "r", stdin);
freopen("out.txt", "w", stdout);
int E, R, n, i, k, gain, m1, x, te, j, Enow, yes, m, dist;

scanf("%d", &te);
for(i=1; i<=te; i++)
{
	
	scanf("%d%d%d", &E, &R, &n);
	int v[n+1];
	for(j=0; j<n; j++)
		scanf("%d", &v[j]);
		
	Enow = E;
	v[n]=0;
	gain = 0;
	x = 0;
	for(k=0; k<=n; k++)
	{
		yes = 0;
		for(m=k+1; m <=n; m++)
		{
			if(v[m]>=v[k])
			{
				yes = 1;
				break;
			}
		}
		
		
		if(yes == 1)
		{
			dist = (m-k);
			m1 = Enow+R*dist-E;
			x = (m1>E)?E:m1;
			x = (x>0)?x:0;
			//printf("k = %d    dist = %d \n", k, dist);
		}
		
		else
		{
			x = Enow;
		}
		Enow = Enow - x + R;
		Enow = (Enow>E)?E:Enow;
		gain = gain + v[k]*x;	
		//printf("  k = %d     x = %d   \n", k, x);
	}
	
	printf("Case #%d: %d\n", i, gain);
}

return 0;
}
