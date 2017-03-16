#include <stdio.h>
#include <iostream>
#include <memory.h>
#include <assert.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>
#include <math.h>

using namespace std;

typedef struct toybox 
{
	__int64 num;
	int id;
}tb;
tb toy[101];
tb box[101];
__int64 ab[101][101];
inline __int64 min(__int64 a,__int64 b)
{
	return a<b ? a: b;
}

int main()
{
	freopen( "C-small-attempt0.in", "r", stdin );
	freopen( "output.txt", "w", stdout );
	int T,N,M;
	int i,j,k;
	__int64 a;
	int b;
	scanf( "%d\n", &T);
	for (k = 1; k <= T; ++k)
	{
		scanf( "%d%d", &N,&M);
		for (j = 0; j < N; ++j)
		{
			scanf("%I64d%d", &a,&b);
			box[j].num = a;
			box[j].id = b;
		}
		for (j = 0; j < M; ++j)
		{
			scanf("%l64d%d", &a,&b);
			toy[j].num = a;
			toy[j].id = b;
		}
		ab[0][0] = 0; 
		for ( i=1; i <= N; ++i ) 
			ab[i][0] = 0; 
		for ( i=1; i <= M; ++i ) 
			ab[0][i] = 0; 
		for ( i=1; i <= N; ++i ) 
			for ( j=1; j <= M; ++j )
			{ 
				if(box[i-1].id == toy[j-1].id)
					ab[i][j] = ab[i-1][j-1]+min(box[i-1].num,toy[j-1].num); 
				else if(ab[i-1][j]>ab[i][j-1])
					ab[i][j]= ab[i-1][j]; 
				else ab[i][j] = ab[i][j-1]; 
			} 
		printf("Case #%d: ",k);
		printf("%I64d\n", ab[N][M]);
	}
	return 0;
}