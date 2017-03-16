#include<stdio.h>
void main(){
	
	int times;
	scanf("%d",&times);
	
	int t=0;
	int i,j;
	char result[times][500];
	
	for(i=0;i<times;i++)
		for(j=0;j<500;j++)
			result[i][j]=' ';	
	
	double xorg,yorg,x,y;
	double x1,y1;
	
	while(t<times){
	
	scanf("%lf %lf",&xorg,&yorg);
	
	x=xorg;
	y=yorg;
	
	x1=y1=0;
	
	if(x<0)
		x*=-1;
	if(y<0)
		y*=-1;
	
	int cnt=0;
	
	double n=1;
	
	
	while(x1!=x || y1!=y){
		if(x1!=x){
			if(x1+n<=x){
				x1+=n;
				if(xorg>=0)
					result[t][cnt]='E';
				else
					result[t][cnt]='W';
			}	
			else{
				x1-=n;
				if(xorg>=0)
					result[t][cnt]='W';
				else	
					result[t][cnt]='E';					
			}		
			++n;
			++cnt;
		}
		if(y1!=y){	
			if(y1+n<=y){
				y1+=n;
				if(yorg>=0)
					result[t][cnt]='N';
				else
					result[t][cnt]='S';
			}	
			else{
				y1-=n;
				if(yorg>=0)
					result[t][cnt]='S';
				else
					result[t][cnt]='N';
			}	
			++n;
			++cnt;
		}
			
	 }
	++t;	
	}
	for(i=0;i<times;i++){
		printf("Case #%d: ",i+1);
		for(j=0;j<500;j++){
			if(result[i][j]!=' ')
				printf("%c",result[i][j]);
			}
		printf("\n");
	}			
				
	
}	