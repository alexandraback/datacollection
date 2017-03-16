#include <stdio.h>

int main(int argc, char* argv[])
{
	int T;
	char cadena[200];
	scanf("%d\n",&T);
	for (int t=1;t<=T;t++)
	{
		int N,S,p;
		scanf("%d %d %d",&N,&S,&p);
		int total=0;
		int seguro = (3*p)-2;
		int sorpresa = (3*p)-4;
		for (int i=0;i<N;i++)
		{
			int puntos;
			scanf("%d", &puntos);
			if (puntos>=seguro)
				total++;
			else if ((puntos>=sorpresa)&&(S>0)&&(p>1))
			{
				total++;
				S--;
			}
		}
		printf("Case #%d: %d\n",t,total);
	}
	return 0;
}
