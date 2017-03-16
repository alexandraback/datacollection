#include <stdio.h>

int T;
int A, N;
int mSizeArr[100];
int ans, cSize;

int myfind( int index, int cSize );

int main()
{
	scanf( "%d", &T );
	for( int p = 0; p < T; ++p )
	{
		scanf( "%d %d", &A, &N );
		for( int i = 0; i < N; ++i )
		{
			scanf( "%d", &mSizeArr[i] );
		}
		for( int i = 0; i < N-1; ++i )
			for( int j = N-1; j > i; --j )
				if( mSizeArr[i] > mSizeArr[j] )
				{
					mSizeArr[i] = mSizeArr[i] ^ mSizeArr[j];
					mSizeArr[j] = mSizeArr[i] ^ mSizeArr[j];
					mSizeArr[i] = mSizeArr[i] ^ mSizeArr[j];
				}
		ans = 0;
		cSize = A;
		ans = myfind( 0, cSize );
		printf( "Case #%d: %d\n", p+1, ans );
	}
	return 0;
}

int myfind( int _index, int _cSize )
{
	int ans = 0;
	int aans;

	if( _index == N )
		return 0;
	while( _cSize > mSizeArr[_index] )
	{
		_cSize += mSizeArr[_index];
		++_index;
		if( _index == N )
			return 0;
	}
	if( _cSize != 1 )
	{
		while( _cSize <= mSizeArr[_index] )
		{
			_cSize *= 2;
			--_cSize;
			++ans;
		}
		aans = myfind( _index, _cSize )+ans;
	}
	else
	{
		return N;
	}
	return aans < N-_index ? aans : N-_index;
}