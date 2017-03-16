#include <stdio.h>
#include <math.h>
int treeSz[10000];
int cb[25][25];
int side;
double pp[1000][1000];


int main()
{
	for (int q=0;q<=20;++q) for (int w=0;w<=q;++w)
		if (q==w || w==0) cb[q][w]=1;
		else cb[q][w]=cb[q-1][w-1]+cb[q-1][w];
	for (int q=0;q<10000;++q)
		treeSz[q]=(2*q+1)*(q+1);

	//적당히 잘 translate하면 된다
	int T;
	scanf("%d",&T);
	for (int kase=1;kase<=T;++kase)
	{
		int n,x,y;
		double prob = 0;
		scanf("%d %d %d",&n,&x,&y);
		int len = 0;
		for (;treeSz[len]<=n;++len); --len;
		int mod = n-treeSz[len];
		
		if (x<0) x=-x;
		if (x+y <= 2*len) prob = 1;
		else if (x+y > 2*(len+1)) prob = 0;
		else
		{
			// 2*len < x+y <= 2*(len+1)
			// emp = treeSz[len+1] - treeSz[len]
			side = (len+1)*2;
			prob = 0;
			for (int q=0;q<=side;++q) for (int w=0;w<=side;++w)
				pp[q][w]=0;

			pp[0][0]=1.0;
			for (int q=0;q<=side;++q) for (int w=0;w<=side;++w)
			{
				if (q+1<=side && w+1<=side)
				{
					pp[q+1][w] += pp[q][w]*0.5;
					pp[q][w+1] += pp[q][w]*0.5;
				}
				else if (q+1<=side)
				{
					pp[q+1][w] += pp[q][w];
				}
				else if (w+1<=side)
				{
					pp[q][w+1] += pp[q][w];
				}
			}
			
			for (int c1=y+1;;++c1)
			{
				int c0 = mod-c1;
				if (c0 > side || c1 > side) break;
				prob += pp[c0][c1]; 
			}
		}
		printf("Case #%d: %.8lf\n",kase,prob);
		
	}
	return 0;
}
