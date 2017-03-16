#include <cstdio>

using namespace std;

int main()
{
	int T , R , N , M , K , set[7] , max;
	int matrix[5][5][5] , index = 0;
	/*for(int i=2 ; i<=5  ; i++)
	{
		for(int j=2 ; j<=5 ; j++)
		{
			for(int k=2 ; k<=5 ; k++)
			{
				matrix[i][j][k] = i*j*k;
			}
		}

	}*/
	scanf("%d" , &T);
	for(int a=1 ; a<=T ; a++)
	{
		printf("Case #%d:\n" , a);
		scanf("%d %d %d %d" , &R , &N , &M , &K);
		while(R--)
		{
			max = 0;
			for(int i=0 ; i<K ; i++)
			{
				scanf("%d" , &set[i]);
				if(set[i] > max)
					max = set[i];
			}
			int flag = 0;
			for(int i=2 ; i<=5 && flag == 0 ; i++)
			{
				for(int j=2 ; j<=5 && flag == 0 ; j++)
				{
					for(int k=2 ; k<=5 ; k++)
					{
						if(i*j*k == max)
						{
							flag = 1;
							printf("%d%d%d\n" , i , j , k);
							break;
						}
					}
				}

			}
			if(flag == 0)
				printf("222\n");
		}
		
	}
	return 0;
}
