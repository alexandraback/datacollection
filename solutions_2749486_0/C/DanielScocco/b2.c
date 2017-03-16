#include <stdio.h>

int path[500];
int x;
int y;
int nJumps;

int process(int curX, int curY, int jump){
	int i;
	int jumps;
	int dir;

	while(1){
		curX = 0;
		curY = 0;
		for(i=0;i<500;i++){
			if(curX==x&&curY==y)
				break;
			dir = rand() % 4;
			path[i]=dir;
			if(dir==0)
				curY+=i+1;
			else if(dir==1)
				curX+=i+1;
			else if(dir==2)
				curY-=(i+1);
			else
				curX-=(i+1);		
		}
		if(i<500)
			break;
	}

	nJumps=i;
	
}

void printDir(int i){
	if(path[i]==0)
		printf("N");
	if(path[i]==1)
		printf("E");
	if(path[i]==2)
		printf("S");
	if(path[i]==3)
		printf("W");
}

int main(){
	int t,k;
	int jumps;
	int i;

	scanf("%d",&t);

   for(k=0;k<t;k++){

		scanf("%d %d",&x,&y);
	
		process(0,0,0);	
      
       	if(k>0)
			printf("\n");
		printf("Case #%d: ",k+1);
		for(i=0;i<nJumps;i++)
			printDir(i);
	}

return 0;
}
