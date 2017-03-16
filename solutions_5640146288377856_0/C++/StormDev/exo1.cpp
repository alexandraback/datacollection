#include<cstdio>
#include<vector>
#include<stack>
#include<utility>
#include<map>
#include<algorithm>

inline int calculate( const int R , const int C , const int W )
{
	if( C%W > 0 )
		return (C/W)*R +W;
	else
		return (C/W)*R + W - 1;
}


int main()
{
	int T;
	std::scanf("%d", &T );

	int R, C , W ;

	for( int i(1) ; i <= T ; ++i )
	{
		std::scanf("%d%d%d", &R , &C , &W );
		std::printf("Case #%d: %d\n", i , calculate( R , C , W ));
	}

	return 0;
}
