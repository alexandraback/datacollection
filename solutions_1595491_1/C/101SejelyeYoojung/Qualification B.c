#include <stdio.h>

int main()
{
	int test_case, surprising, googlers, score;
	int max_googlers;
	int i, j, p;
	FILE* fp;
	
	fp = fopen("output.txt","w");

	scanf("%d",&test_case);

	for(i=1; i<=test_case; i++) {
		max_googlers=0;
		scanf("%d %d %d",&googlers,&surprising,&p);
		for(j=0; j<googlers; j++) {
			scanf("%d",&score);
			if(score >= p) {
				if(score >= (3*p)-2) max_googlers++;
				else if(score >= (3*p)-4) {
					if(surprising) {
						max_googlers++;
						surprising--;
					}
				}
			}
		}
		fprintf(fp,"Case #%d: %d\n",i,max_googlers);
	}
	return 0;
}