#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char map[2000001];
int main(int argc, char *argv[])
{
	int num, a, b, count;
	int temp, temp_count, ten, dnum;
	int i, j, k;
	scanf("%d", &num);
	for(i = 0; i < num; ++i)
	{
		scanf("%d %d", &a, &b);
		
		count = 0;
		memset(map, 0, 2000010*sizeof(char));
		for(j = a; j <= b; ++j)
		{
			//printf("%d\n", map[j]);
			if(map[j] == 0)
			{
				temp_count = 0;
				temp = j;
				ten = 1;
				for(k = 0; temp > 0; ++k, temp/=10, ten *= 10);
				ten/=10;
				
				dnum = k;
				
				temp = j;
				//printf("\n%d ", j);
				for(k = 0; k < dnum; ++k){
					//printf("%d\n", temp);
					
					if(temp >= a && temp <= b && map[temp] != 1)
					{
						//printf("xddd\n");
						//printf("%d ", temp);
						map[temp] = 1;
						++temp_count;
					}
					
					temp = temp/10 + temp%10*ten;
				}
				//printf("%d\n", temp_count);
				//printf(":%d", temp_count);
				count += temp_count*(temp_count-1)/2;
				
			}
		}
		printf("Case #%d: %d\n", i+1, count);	
	}

	return 0;
}