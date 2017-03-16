#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 210
int J[MAXN];
int CJ[MAXN];

int main ()
{
	int T, N, i, sumj, bval, k, tsj;
	scanf("%d",&T);
	
	for ( int cnt = 1; cnt <= T; cnt++ )
	{
		scanf("%d",&N);
		sumj = 0;
		
		for ( i = 0; i < N; i++ ) 
		{
			scanf("%d",&J[i]);
			CJ[i] = J[i];
			sumj += J[i];
		}
		
		tsj = 0;
		sort(CJ,CJ+N);
		bval = CJ[0];
		k = 1;
		
		for ( i = 1; i < N; i++ )
		{
			if ( tsj + (CJ[i]-bval)*k > sumj ) break;
			tsj += (CJ[i]-bval)*k;
			k++;
			bval = CJ[i];
		}
			
		printf("Case #%d: ",cnt);
		
		for ( i = 0; i < N; i++ )
		{
			if ( J[i] > bval ) printf("0 ");
			else printf("%lf ",((bval-J[i])+(sumj-tsj)*1.0/k)/sumj*100);
		}
		
		printf("\n",bval);
	}
}