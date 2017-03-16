#include<stdio.h>
int main()
{
	FILE *fp2=freopen("output.txt","w",stdout);
	int i,n,x,y,z;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d",&x,&y,&z);
		if(x>=7||(y*z)%x!=0||(x>y&&x>z))
			printf("Case #%d: RICHARD\n",i+1);
		else if(x<=2)
			printf("Case #%d: GABRIEL\n",i+1);
		else if(x==3)
			if(y==1||z==1)
				printf("Case #%d: RICHARD\n",i+1);
			else
				printf("Case #%d: GABRIEL\n",i+1);
		else if(x==4)
			if(y<=2||z<=2)
				printf("Case #%d: RICHARD\n",i+1);
			else
				printf("Case #%d: GABRIEL\n",i+1);
		else if(x==5)
			if(y<=2||z<=2||(y==3&&z==5)||(y==5&&z==3))
				printf("Case #%d: RICHARD\n",i+1);
			else
				printf("Case #%d: GABRIEL\n",i+1);
		else if(x==6)
			if(y<=3||z<=3)
				printf("Case #%d: RICHARD\n",i+1);
			else
				printf("Case #%d: GABRIEL\n",i+1);
	}
	scanf(" ");
}

