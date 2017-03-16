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


int cost[1000][2] ;
int check[1000];

int select ( int star, int& level ,int N) { // return gameid, return by reference level
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
				int ndiff = cost[i][1] - star ;
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



int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
	int T, nCase = 1 ;
	int N ;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> N;
        for ( int i=0;i<N*2;++i ) {
            cin >> cost[i/2][i%2];
        }
        	memset ( check, 0, sizeof(check) ) ;
        int star = 0,count = 0 ;
        int complete = 0 ;
        while ( complete < N ) {
            int level;
            int game = select ( star, level,N ) ;
            if ( game == -1 ) {count =  -1 ; break;}
            if ( level == 2 ) ++ complete ;
            star += level-check[game];
            check[game] = level ;
            count++ ;
        }
		if ( count == -1 ) printf ( "Case #%d: Too Bad\n", i );
		else printf ( "Case #%d: %d\n", i, count );
	}
	return 0;
}
