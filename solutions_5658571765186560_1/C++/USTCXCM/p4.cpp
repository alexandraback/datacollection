using namespace std;
#include <iostream>
int main()
{
	FILE *fp1,*fp2;
	if((fp1=fopen("D-large.in","r"))==NULL)
	{
		printf("cannot open this file\n");
		exit(0);
	}
	fp2=fopen("D-large.out","w");
	int x,r,c,n,i;
	fscanf(fp1,"%d",&n);
	for(i=0;i<n;i++)
	{
	fscanf(fp1,"%d%d%d",&x,&r,&c);
	if((x>r&&x>c)||(x>2*r)||(x>2*c)||(r*c%x!=0)||x>6)
		{printf("Case #%d: RICHARD\n",i+1);
		fprintf(fp2,"Case #%d: RICHARD\n",i+1);}
	else
		switch(x)
		{	
			case 4:
				if(r==2||c==2)
					{printf("Case #%d: RICHARD\n",i+1);
					fprintf(fp2,"Case #%d: RICHARD\n",i+1);}
				else
					{printf("Case #%d: GABRIEL\n",i+1);
					fprintf(fp2,"Case #%d: GABRIEL\n",i+1);}
				break;
			case 6:
				if(r==3||c==3)
					{printf("Case #%d: RICHARD\n",i+1);
					fprintf(fp2,"Case #%d: RICHARD\n",i+1);}
				else
					{printf("Case #%d: GABRIEL\n",i+1);
					fprintf(fp2,"Case #%d: GABRIEL\n",i+1);}
				break;
			default:{printf("Case #%d: GABRIEL\n",i+1);
					fprintf(fp2,"Case #%d: GABRIEL\n",i+1);}
		}
	}
	fclose(fp1);
	fclose(fp2);
	getchar();
	getchar();
	return 0;
}