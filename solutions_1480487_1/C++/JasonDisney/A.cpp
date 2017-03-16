#include <queue>
#include <bitset>
#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

double s, v, os;
int TTTTT, TI, a[201], ac, rmq, i, t, h[201];

int main()
{
	//This is a comment
	scanf("%d", &TTTTT);
	for(TI=1; TI<=TTTTT; TI++)
	{
		scanf("%d", &ac);
		os = 0;
		//HelloWorld
		for(i=0;i<ac;i++)
		{
			scanf("%d", a+i);
			h[i] = 1;
			os += a[i];
		}
		
		for(;;) 
		{
			s = 0; rmq = 0;
			for(i=0;i<ac;i++)
				if(h[i]) s+=a[i], rmq++;
			s += os;
			v = s/rmq;
			
			t = 0;
			for(i=0;i<ac;i++)
				if(h[i] && a[i]>=v)
					h[i] = 0, t=1;
			if(!t) break;
		}
		
		printf("Case #%d:", TI);
		if(ac > 1)
			for(i=0; i<ac; i++)
				if(h[i]) {
					printf(" %.6lf", (v-a[i])*100/os);
				} else {
					printf(" %.6lf", 0.0);
				}
		else printf(" %.6lf", 0.0);
		printf("\n");
	}
	
	return 0;
}
