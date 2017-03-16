#include <cstdio>

double pass[100050];
double backSpace[100050];
double reType, contType,backBest;
double curProb;
bool backSeen;
int num,numTyped,numTot;

void printOut(){
	double curOne;
	if(reType<contType){
		curOne=reType;
	} else{
		curOne=contType;
	}
	if(curOne>backBest){
		curOne=backBest;
	}
	printf("%.6lf\n",curOne);
	return;
}



int main(){
	freopen("q1.in","r",stdin);
	freopen("q1.out","w",stdout);
	scanf("%d",&num);
	for(int i=1;i<=num;i++){
		scanf("%d %d",&numTyped,&numTot);
		reType=numTot+2.0;
		curProb=1.0000;
		backSeen=false;
		for(int p=1;p<numTyped;p++){
			scanf("%lf",&pass[p]);
			curProb*=pass[p];
			//printf("%lf\n",curProb);
			backSpace[p]=curProb*(numTyped-p+numTot-p+1)+((1.0-curProb)*(numTyped-p+numTot-p+1+numTot+1));
			if(backSpace[p]<backBest || !backSeen){
				backSeen=true;
				backBest=backSpace[p];
			}
		}
		scanf("%lf",&pass[numTyped]);
		curProb*=pass[numTyped];
		contType=curProb*(numTot-numTyped+1)+((1.0-curProb)*(numTot-numTyped+1+numTot+1));
		if(numTyped==1){
			backBest=contType;
		}
		//printf("%lf %lf %lf\n",backBest,contType,reType);
		printf("Case #%d: ",i);
		printOut();
	}
	return 0;
}
