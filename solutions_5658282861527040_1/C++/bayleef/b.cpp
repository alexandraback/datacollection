#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>

using namespace std;

long long d[40][8];
int T,ts,i,j,k,l,o;
long long a[3],ans;

int main()
{
	freopen("b.in","r",stdin);	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld%lld",&a[0],&a[1],&a[2]);
		a[0]--;
		a[1]--;
		a[2]--;
		memset(d,0,sizeof(d));
		d[30][7]=1;
		for(i=29;i>=0;i--)
			for(j=0;j<8;j++)
				for(k=0;k<8;k++)
				{
					if((k&j) != j) continue;
					if(!d[i+1][k]) continue;
					for(l=0;l<3;l++)
						if(((j^k)>>l&1) && !(a[l]>>i&1))
							break;
					if(l<3) continue;

					if((j^k)&3)
					{
						if(!(k&4))
							d[i][j]+=d[i+1][k]*(2-(k&1))*(2-(k>>1&1));
						else if((j>>2&1)!=(a[2]>>i&1))
							d[i][j]+=d[i+1][k]*(2-(k&1))*(2-(k>>1&1));
						continue;
					}

					if((j^k)&4)
					{
						if((j&1) && (j&2))
							d[i][j]+=d[i+1][k]*(!(a[0]>>i&1) || !(a[1]>>i&1));
						else if(j&1)
							d[i][j]+=d[i+1][k]*(!(a[0]>>i&1)+1);
						else if(j&2)
							d[i][j]+=d[i+1][k]*(!(a[1]>>i&1)+1);
						else
							d[i][j]+=3*d[i+1][k];
						continue;
					}
					for(l=0;l<2;l++)
						for(o=0;o<2;o++)
						{
							if((j&1) && l!=(a[0]>>i&1))
								continue;
							if((j&2) && o!=(a[1]>>i&1))
								continue;
							if(!(j&4))
								d[i][j]+=d[i+1][k];
							else if((l&o) == (a[2]>>i&1))
								d[i][j]+=d[i+1][k];
						}
				}
		ans=0;
		for(i=0;i<8;i++)
			ans+=d[0][i];
		printf("Case #%d: %lld\n",++ts,ans);
	}
	return 0;
}