#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

typedef long long int i64;

int main()
{
	int noCase;
	int R , C , W , ANS ;
	scanf("%d",&noCase);

	for( int nCase = 1 ; nCase <= noCase; nCase++ )
	{
		scanf("%d %d %d",&R,&C,&W);
		ANS = (( C + W - 1) / W ) + min( C , W - 1 ) ;
		ANS += ( R - 1 ) * (C / W);
		printf("Case #%d: %d\n",nCase,ANS);
	}

	return 0;
}