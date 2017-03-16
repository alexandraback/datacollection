#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

void search(int i,int E,int e,int R,int N,int *v,int prev_gain,int *result)
{
	int euse;
	int total_gain;
	if (i==N){
		if (*result<prev_gain)*result=prev_gain;
		return;
	}
	for (euse=0;euse<=e;euse++){
		total_gain=prev_gain+euse*v[i];
		int enext;
		enext=e-euse+R;
		if (enext>E)enext=E;
		search(i+1,E,enext,R,N,v,total_gain,result);
	}
}

int main(void)
{
	int tc,T;
	scanf("%d\n",&T);
	for (tc=1;tc<=T;tc++){
		int i;
		int E,R,N;
		int v[10];
		int maxgain=0;
		scanf("%d %d %d\n",&E,&R,&N);
		for (i=0;i<N;i++){
			scanf("%d ",&v[i]);
		}
		//安直に全数探索
		search(0,E,E,R,N,v,0,&maxgain);
		printf("Case #%d: %d\n",tc,maxgain);
	}
	return 0;
}
