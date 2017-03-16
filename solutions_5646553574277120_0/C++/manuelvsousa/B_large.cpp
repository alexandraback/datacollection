#include <cstdio>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int t,cas=0;
	scanf("%d",&t);
	while(t--)
	{
		int c,d,v,soma=0,soma1=0,soma2=0,soma3=0,soma4=0;
		scanf("%d %d %d",&c,&d,&v);
		int den[d];
		for(int i=0;i<d;i++)
			scanf("%d",&den[i]);
		int guarda[v+1];
		for(int i=0;i<=v;i++)
			guarda[i]=0;
		for(int i=0;i<d;i++)
		{

			soma+=den[i];
			for(int j=i+1;j<d;j++)
			{
				soma1+=den[j] + soma;
				for(int k=j+1;k<d;k++)
				{
					soma2+=den[k] + soma1;
					for(int l=k+1;l<d;l++)
					{
						soma3+=den[l] + soma2;
						for(int y=l+1;y<d;y++)
						{
							soma4+=den[y] + soma3;
							if(soma4 <= v)
								guarda[soma4]=1;
							soma4=0;
						}
						if(soma3 <= v)
								guarda[soma3]=1;
						soma3=0;
					}
					if(soma2 <= v)
								guarda[soma2]=1;
					soma2=0;
				}
				if(soma1 <= v)
								guarda[soma1]=1;
				soma1=0;
			}
			if(soma <= v)
				guarda[soma]=1;
			soma=0;
		}

		int count = 0;

		for(int i=1;i<=v;i++)
		{
			if(guarda[i]==0)
			{
				guarda[i]=1;
				for(int j=1;j<=v-i;j++)
				{
					if(guarda[j]==1 && j!=i)
					{
						guarda[j+i] = 1;

					}
				}
				count++;
			}
		}

		printf("Case #%d: %d\n",++cas,count);
	}
	return 0;
}
