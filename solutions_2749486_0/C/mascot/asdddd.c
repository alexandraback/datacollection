#include<stdio.h>
#include<string.h>
#include<math.h>

int test,x,y,k;
char s[60][510];

int main()
{
	
	scanf("%d",&test);
	for(k=1;k<=test;k++)
	{  scanf("%d %d", &x, &y);
	   printf("Case #%d: ",k);
	   if(x<=0&&y>=0){
            while(x++){
                printf("EW");
            }
            while(y--){
                printf("SN");
            }
        }
        else if(x<=0&&y<=0){
            while(x++){
                printf("EW");
            }
            while(y++){
                printf("NS");
            }
        }
        else if(x>=0&&y<=0){
            while(x--){
                printf("WE");
            }
            while(y++){
                printf("NS");
            }
        }
        else{
            while(x--){
                printf("WE");
            }
            while(y--){
                printf("SN");
            }
        }
        printf("\n");
	}



	return 0;
}


