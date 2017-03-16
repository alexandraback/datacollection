#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

#define MAX_M 10

struct Class{
	int M;
	int point[MAX_M];
	bool solved;
};

int N;
Class classes[1000]; //放棄0

bool recursive( int index )
{
	if( classes[index].solved == true ){
		//printf( "where index %d happened", index );
		return true; // true 代表有迴圈
	}
	classes[index].solved = true;

	for( int i=0; i < classes[index].M; i++ ){
		if( recursive( classes[index].point[i] ) ){
			//printf( "where index %d happened", index );
			return true;
		}
	}

	return false;
}

void reset()
{
	for( int i=1; i<=N; i++ ){
		classes[i].solved = false;
	}
}

bool solver()
{
	scanf("%d", &N );
	for( int i=1; i<=N; i++ ){
		cin >> classes[i].M;
		for( int j=0; j<classes[i].M; j++ ){
			cin >> classes[i].point[j];
		}
	}

	for( int i=1; i<=N; i++ ){
		reset();
		if ( recursive( i ) ) return true;
	}

	return false;
}

int main()
{
	freopen( "A-small-attempt1.in", "r", stdin );
	freopen( "A-small-attempt1.out", "w", stdout );
	//freopen( "A-large-practice.in", "r", stdin );
	//freopen( "A-large-practice.out", "w", stdout );

	int T;
	scanf("%d", &T );
	for( int i=1; i<=T; i++ ){
		printf("Case #%d: ", i);
		if( solver() ) printf("Yes");
		else printf("No");
		printf("\n");
	}
}

