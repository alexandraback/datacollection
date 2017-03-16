/*
 * C.cpp
 *
 *  Created on: 2012-4-14
 *      Author: jesliwang
 */

#include <stdio.h>
#include <string.h>

using namespace std;

int num[2000010];
int ans[2000010];
int T = 0;
void init()
{
	int list[100];
	int k = 1;
	for( int i = 1; i <= 2000; i++)
	{

		if( 0 == num[i] )
		{
			int j = 0;
			int tmp = i;
			while( tmp )
			{
				list[ j++ ] = tmp % 10;
				tmp /= 10;
			}

			for(int s = 0; s < j; s++)
			{
				list[s + j] = list[s];
			}

			for(int xy = j*2 - 1; xy >= j; xy --)
			{
				if(0 != list[xy])
				{
					int fuck = 0;
					for(int love = 0; love < j ; love++)
					{
						fuck = fuck*10 + list[xy - love];
					}
					num[fuck] = k;
				}
			}
			num[i] = k;
			k++;
		}
	}
	T = k;

}
int main(int argc, char* argv[])
{
	init();
	//printf("%d\n", T);

	int N = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++)
	{
		int l = 0, r = 0;
		scanf("%d %d", &l, &r);
		memset(ans, 0 ,sizeof(ans));
		for(int j = l; j <= r; j++)
		{
			ans[ num[j] ] ++;
		}
		int sum = 0;
		for(int j = 1; j <= T; j ++)
		{
			if( ans[j] > 1)
				sum += (ans[j] - 1) * ans[j] / 2;
		}
		printf("Case #%d: %d\n", i, sum);
	}

	return 0;
}


