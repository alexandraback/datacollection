#include <stdio.h>

int missing(int levels, int level2[]){
	int i;

	for (i=0;i<levels;i++)
		if (level2[i]!=-1)
			return 1;
	return 0;
}

int possible(int levels, int stars, int level2[]){
	int i;

	for (i=0;i<levels;i++)
		if((level2[i]!=-1)&&(level2[i]<=stars))
			return i;
	return -1;
}

int match(int levels, int stars, int level1[],int level2[]){
	int i,best;
	best = -1;
	
	for (i=0;i<levels;i++){
		if ((level1[i]!=-1)&&(level1[i]<=stars)){
			if(best==-1){
				//fprintf(stderr,"caso base\n");
				best=i;
			}
			else{
				//fprintf(stderr,"caso secundario\n");
				if (level2[i]>level2[best])
					best=i;
			}
		}
	}

	return best;
}

int main(){
	int i,t,j;
	int levels;
	int stars;
	int level1[1000];
	int level2[1000];
	int result;
	int impossible;
	int completes;
		
	scanf("%d",&t);

	for (i=0;i<t;i++){
		if (i>0)
			printf("\n");
		printf("Case #%d: ",i+1);
				
		stars = 0;
		completes = 0;
		impossible = 0;

		scanf("%d",&levels);
		for (j=0;j<levels;j++)	
			scanf("%d %d",&level1[j], &level2[j]);

		while (missing(levels,level2)){
			//fprintf(stderr,"tentando no level2\n");
			result = possible(levels,stars,level2);
			if (result!=-1){
				if (level1[result]==-1)
					stars+=1;
				else
					stars+=2;
				completes++;
				level2[result]=-1;
				level1[result]=-1;
			}
			else{
				//fprintf(stderr,"tentando no level1\n");
				result = possible(levels,stars,level1);
				if (result!=-1){
					result = match(levels,stars,level1,level2);
					//fprintf(stderr,"result=%d\n",result);
					stars+=1;
					completes++;
					level1[result]=-1;
				}
				else{
					impossible=1;
					goto here;
				}
			}
		}	
		here:	
		if (impossible)
			printf("Too Bad");
		else
			printf("%d",completes);						
	}

return 0;
}
