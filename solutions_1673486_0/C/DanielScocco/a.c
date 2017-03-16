#include <stdio.h>

int main(){
	int i,t;
	int a,b;
	float probs[10];
	float keepTyping;
	float pressEnter;
	float backSpace;
	float backSpace2;

	scanf("%d",&t);

	for (i=0;i<t;i++){
		if (i>0)
			printf("\n");
		printf("Case #%d: ",i+1);

		scanf("%d %d",&a,&b);
		if (a==1){
			scanf("%f",&probs[0]);
			keepTyping = probs[0]*(b-a+1) + (1-probs[0])*(b-a+1+b+1);
			pressEnter = 1 + b + 1;
			if (pressEnter<keepTyping)
				printf("%f",pressEnter);
			else
				printf("%f",keepTyping);
		}
		else if(a==2){
			scanf("%f %f",&probs[0],&probs[1]);
			keepTyping = probs[0]*probs[1]*(b-a+1) + (1 - (probs[0]*probs[1])) * (b-a+1+b+1);
			pressEnter = 1 + b + 1; 
			backSpace = 2*((probs[0]*probs[1]) * (1-probs[0]*probs[1]) * (1 + a - b + 1)) + 
				2 * ((1-(probs[0]*probs[1]) * (1-probs[0]*probs[1]))*(1 + a - b + 1 + b + 1));
			if (keepTyping<backSpace){
				if (keepTyping<pressEnter)
					printf("%f",keepTyping);
				else
					printf("%f",pressEnter);
			}
			else{
				if (backSpace<pressEnter)
					printf("%f",backSpace);
				else
					printf("%f",pressEnter);
			}
		}
		else{
			scanf("%f %f %f",&probs[0],&probs[1],&probs[2]);
			pressEnter = 1 + b + 1; 
			keepTyping = (probs[0]*probs[1]*probs[2])*(b-a+1) + (1 - (probs[0]*probs[1]*probs[2])) * (b-a+1+b+1);
			backSpace = (1-probs[0]*probs[1]) * (1 + 1 + b - a + 1 + b + 1) + (probs[0]*probs[1]) * (1 + 1 + b - a +1 );
			backSpace2 = (1-probs[0])*(2+2+b-a+1+b+1) + (probs[0]*(2+2+b-a+1));
			if (backSpace2<backSpace)
				backSpace=backSpace2;
			if (keepTyping<backSpace){
				if (keepTyping<pressEnter)
					printf("%f",keepTyping);
				else
					printf("%f",pressEnter);
			}
			else{
				if (backSpace<pressEnter)
					printf("%f",backSpace);
				else
					printf("%f",pressEnter);
			}
		}
	}

return 0;
}
