#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL ;

int N ;
int cost[1000][2] ;
int check[1000];


void input() {
	cin >> N;
	for ( int i=0;i<N*2;++i ) {
		cin >> cost[i/2][i%2];
	}
}

int select ( int star, int& level ) { // return gameid, return by reference level
	int bestGame = -1, diff = 0;
	level = 0 ;
	for ( int i=0;i<N;++i ) {
		if ( check[i] == 2 ) continue ;
		
		if ( cost[i][1] <= star ) {
			bestGame = i;
			level = 2;
			return i ;
		}
		
		if ( check[i] == 0 ) {
			// level <= 1
			if ( cost[i][0] <= star ) {
				int ndiff = cost[i][1] - cost[i][0] ;
				// printf ( "(%d %d %d), (%d %d %d)\n", bestGame, level, diff, i, 1, ndiff ) ;
				if ( ndiff > diff ) {
					diff = ndiff ;
					bestGame = i ;
					level = 1;
				}
			}
		}
	}
	return bestGame ;
}

int solv() {
	memset ( check, 0, sizeof check ) ;
	int star = 0, cnt = 0 ;
	int complete = 0 ;
	while ( complete < N ) {
		int level;
		int game = select ( star, level ) ;
//		printf ( "%d -> (%d %d)\n", star, game, level ) ;
		if ( game == -1 ) return -1 ;
		if ( level == 2 ) ++ complete ;
		star += level-check[game];
		check[game] = level ;
		++cnt ;
	}
	return cnt ;
}

int main()
{
	int T, nCase = 1 ;
	cin >> T;
	while ( T-- ) {
		input();		
		int ans = solv();
		if ( ans == -1 ) printf ( "Case #%d: Too Bad\n", nCase++ );
		else printf ( "Case #%d: %d\n", nCase++, ans );
	}
	return 0;
}
