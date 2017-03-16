#include <stdio.h>
#include <math.h>

int process(int cm, int liters){
	int area1, area2;
	int ink;
	int count = 1;

	area1 = pow(cm,2);
	area2 = pow(cm+1,2);
	ink = area2-area1;
	liters-=ink;

	cm+=3;
	while(1){
		area1 = pow(cm-1,2);
		area2 = pow(cm,2);
		ink = area2-area1;
		if(liters>=ink){
			liters -=ink;
			count++;
			cm+=2;
		}
		else
			break;
	}
	
	return count;
}

int main(){
    int k,t;
    int result;
	int cm, liters;
  
    scanf("%d",&t);
  
    for(k=0;k<t;k++){
		scanf("%d %d",&cm,&liters);		

        result = process(cm,liters);    

        if(k>0)
          printf("\n");
        printf("Case #%d: %d",k+1,result);
    }

  return 0;
}
