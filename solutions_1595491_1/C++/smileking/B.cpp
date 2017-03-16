/*
 * B.cpp
 *
 *  Created on: 2012-4-14
 *      Author: jesliwang
 */

#include <stdio.h>

using namespace std;

int main(int argc, char* argv[])
{
	int T = 0;
	int i = 0;
	scanf("%d", &T);
	for( i = 1; i <= T; i++)
	{
		int N = 0, S = 0, P = 0;
		int L = 0, R = 0;
		int Headline = 0;

		scanf("%d %d %d", &N, &S, &P);
		if( P >= 2 )
			L = P + 2 * (P - 2);
		else
			L = P;
		if( P >= 2)
			R = P + 2 * (P - 1);
		else
			R = P;

		Headline = 3*10 - 1;


		int OverWithmust = 0;
		int OverWithSur = 0;
		int OverWithOutSur = 0;
		int BelowWithSur = 0;
		int BelowWithOutSur = 0;
	//	printf("L=%d R=%d\n", L, R);

		for(int j = 0; j < N ;j ++)
		{
			int tmp = 0;
			scanf("%d", &tmp);
			if( tmp >= R)
			{
				if(tmp >= Headline)
					OverWithOutSur += 1;
				else
					OverWithSur += 1;

			}
			else if( tmp >= L)
				OverWithmust += 1;
			else
			{
				if(tmp <= 1)
					BelowWithOutSur += 1;
				else
					BelowWithSur += 1;
			}
		//	printf("Sur=%d unSur=%d must=%d\n", OverWithSur, OverWithOutSur, OverWithmust);
		}
		printf("Case #%d: ", i);
		if( S < OverWithmust)
			printf("%d\n", OverWithSur + OverWithOutSur + S);
		else
			printf("%d\n", OverWithSur + OverWithOutSur + OverWithmust);


	}
	return 0;
}



