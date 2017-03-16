#include <stdio.h>
#include <stdlib.h>

int array[1005][1005];

int main(void){
	int r, state, num, in;
	int i, j, k, a,b,c;
	int flag;

	scanf("%d", &r);
	for(i=0; i<r; i++){
		flag = 0;
		scanf("%d", &state);

		for(j = 0; j<state; j++)
			for(k=0; k<state; k++)
				array[j][k] = 0;

		for(j=0; j<state; j++){
			scanf("%d", &num);
			for(k=0; k<num; k++){
				scanf("%d", &in);
				array[j][in-1] += 1;

			//	printf("--- array[%d][%d]+=1\n", j, in-1);
			}


		}

		for(a=0; a<state; a++)
			for(c=0; c<state; c++){
				for(b =0; b<state; b++){
					if((array[a][b]>0) && (array[b][c]>0)){
						array[a][c]+=1;
						//printf("--- cross array[%d][%d]+=1\n", a, c);
					}

				}

			}



		for(a=0; a<state; a++){
			for(c=0; c<state; c++){
				if(array[a][c]>=2){	
					printf("Case #%d: Yes\n", i+1);
					flag = 1;
					break;
				}

			}

			if(flag == 1)	break;
		}

		if(flag == 0)	
			printf("Case #%d: No\n", i+1);
	}

}	
