#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
int main()
{
	int ts;
	scanf("%d", &ts);
	for(int t=1; t<=ts; t++)
	{
		int R, C, r, c, v, k;
		scanf("%d%d%d", &R, &C, &k);
		v=k;
		for(r=2; r<=R; r++)
			for(c=2; c<=C; c++)
			{
				int i, j, ii, jj;
				for(i=0; i<r && i<c; i++)
					for(j=0; i+j<r && j<c; j++)
						for(ii=0; ii<r && ii+i<c; ii++)
							for(jj=0; ii+jj<r && jj+j<c; jj++)
							{
								int p=2*(r+c-i-j-ii-jj)+i-1+j-1+ii-1+jj-1;
								int s=r*c-i*(i+1)/2-ii*(ii+1)/2-j*(j+1)/2-jj*(jj+1)/2;
								if(s>=k) v=min(v, p);
							}
			}
		printf("Case #%d: %d\n", t, v);
	}
	return 0;
}
