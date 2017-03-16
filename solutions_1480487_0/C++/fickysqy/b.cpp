#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
using namespace std;
int main()
{
	freopen("A-small-attempt3.in","r",stdin);
	freopen("a.out","w",stdout);
	int t, sum , map[250],n , i , j , nn,go[250] ;
	double re[250] , tmp ,ss;
	scanf("%d",&t);
	for(i = 1 ; i <= t ; i ++)
	{
		memset(go,0,sizeof(go));
		scanf("%d",&n);
		sum = 0;
		for(j = 0 ; j < n; j ++)
		{
			scanf("%d",&map[j]);
			sum += map[j];
		}
		tmp = 2.0 * sum / n;
		nn = n;
		ss = sum*2;
		for(j = 0 ; j < n ; j ++)
		{
			if(map[j]- tmp >= 1e-6)
			{
				//printf("%d ", j);
				re[j] = 0;
				go[j] = 1;
				ss -= map[j];
				nn--;
			}
		}
		//printf("%lf",re[0]);
		printf("Case #%d:",i);
		tmp =ss/nn;
		for(j = 0 ; j < n ; j ++)
		{
			if(go[j] == 0)
			{
				//printf("%d ",j);
				re[j] = (tmp-map[j])*100/sum;
			}
		}
		for(j = 0 ; j < n ; j ++)
			printf(" %lf",re[j]);
		printf("\n");
	}
	return 0;
}
