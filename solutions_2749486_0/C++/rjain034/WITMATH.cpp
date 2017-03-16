#include<stdio.h>

int main(){
	char dir[4][3]={"NS","SN","WE","EW"};
	int t;
	int x,y;
	scanf("%d",&t);

	for (int j = 1; j <=t; j++)
	{
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",j);
		if(x<0){

			for (int i = 0; i< (-x); i++)
			{
				printf("EW");
			}
		
		}else for (int i = 0; i< x; i++)
			{
				printf("WE");
			}

		if(y<0){

			for (int i = 0; i< (-y); i++)
			{
				printf("NS");
			}
		
		}else for (int i = 0; i< y; i++)
			{
				printf("SN");
			}
	
		printf("\n");
	}

		
		
		
	


}