#include<stdio.h>
void main(){
	
	int number_of_times;
	scanf("%d",&number_of_times);
	
	int times=0;
	int i,j;
	char final_result[number_of_times][500];
	
	for(i=0;i<number_of_times;i++)
		for(j=0;j<500;j++)
			final_result[i][j]=' ';	
	
	double xoriginal,yoriginal,xposition,yposition;
	double xtemporary,ytemporary;
	
	while(times<number_of_times){
	
	scanf("%lf %lf",&xoriginal,&yoriginal);
	
	xposition=xoriginal;
	yposition=yoriginal;
	
	xtemporary=ytemporary=0;
	
	if(xposition<0)
		xposition*=-1;
	if(yposition<0)
		yposition*=-1;
	
	int count_store=0;
	
	while(xtemporary!=xposition || ytemporary!=yposition){
		if(xtemporary!=xposition){
			if(xtemporary+(count_store+1)<=xposition){
				xtemporary+=count_store+1;
				if(xoriginal>=0)
					final_result[times][count_store]='E';
				else
					final_result[times][count_store]='W';
			}	
			else{
				xtemporary-=count_store+1;
				if(xoriginal>=0)
					final_result[times][count_store]='W';
				else	
					final_result[times][count_store]='E';					
			}		
			++count_store;
		}
		if(ytemporary!=yposition){	
			if(ytemporary+count_store+1<=yposition){
				ytemporary+=count_store+1;
				if(yoriginal>=0)
					final_result[times][count_store]='N';
				else
					final_result[times][count_store]='S';
			}	
			else{
				ytemporary-=count_store+1;
				if(yoriginal>=0)
					final_result[times][count_store]='S';
				else
					final_result[times][count_store]='N';
			}	
			++count_store;
		}
			
	 }
	++times;	
	}
	for(i=0;i<number_of_times;i++){
		printf("Case #%d: ",i+1);
		for(j=0;j<500;j++){
			if(final_result[i][j]!=' ')
				printf("%c",final_result[i][j]);
			}
		printf("\n");
	}			
				
	
}	