#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
int g(int x,int y)//求最大公约数
{
	int r;
	while(y>0)
	{
		r=x%y;
		x=y;
		y=r;
	}
	return x;
}
int how(int q)//求是否为2的幂
{
	int i=0;
	while(q > 1)
	{
		int a = q%2;
		if (a!=0) return -1;
		else 
		{
			q = q/2;
			i++;
		}
	}
	return i;
}
int main()
{
	int T;
	int P,Q;
	FILE *inf = fopen("A-small-attempt0.in","r");
	FILE *outf = fopen("test.out","w");
	fscanf(inf,"%d",&T);
	for(int m=1; m<=T; m++)
	{
		fscanf(inf,"%d/%d\n",&P,&Q);
		int temp = g(P,Q);
		P = P/temp;
		Q = Q/temp;
		int ho = how(Q);
		if (ho == -1)
		{
			fprintf(outf,"Case #%d: impossible\n",m);
			continue;
		}
		bool flag = false;
		for (int i=ho;i>0;i--)
		{
			if(P >= pow((float)2,i-1))
			{
				fprintf(outf,"Case #%d: %d\n",m,(ho -i+1));
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			fprintf(outf,"Case #%d: impossible\n",m);
		}
	
	}
	printf("OK!");
	getchar();
	fclose(inf);
	fclose(outf);

	return 0;
}
