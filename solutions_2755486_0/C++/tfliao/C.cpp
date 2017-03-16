#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

#define INF (1<<29)

int T, nCase = 1;
int N ;

struct Tribe
{
	int D, N, W, E, S;
	int dd, dp, ds ;
};

Tribe tribe[10];

void input()
{
	cin >> N;
	for (int i=0;i<N;++i) {
		Tribe& t = tribe[i];
		cin >> t.D >> t.N >> t.W >> t.E >> t.S >> t.dd >> t.dp >> t.ds;
		-- t.N ;
		t.W += 250 ;
		t.E += 250 ;
	}
}

int h[500];
int patch[500];


int solv()
{
	memset ( h, 0, sizeof h);
	memset ( patch, 0, sizeof patch);
	int ans = 0 ;
	while ( true ) {
		int d = INF;
		for ( int i=0;i<N;++i ) {
			Tribe& t = tribe[i];
			if ( t.D < d ) d = t.D;
		}
		if ( d == INF ) break;
		
		for ( int i=0;i<N;++i ) {
			Tribe& t = tribe[i];
			if ( t.D == d ) {
				//printf("%d: day(%d), (%d, %d), strength(%d)\n", i, t.D, t.W-250, t.E-250, t.S);
				bool succ = false ;
				for ( int p=t.W; p<t.E; ++p ) {
					if ( t.S > h[p] ) succ = true;
				}
				if ( succ ) {
					++ ans ;
					for ( int p=t.W; p<t.E; ++p ) {
						if ( patch[p] < t.S ) patch[p] = t.S;
					}
				}
				if ( t.N ) {
					t.D += t.dd;
					t.W += t.dp;
					t.E += t.dp ;
					t.S += t.ds;
					-- t.N;
				} else {
					t.D = INF+1 ;
				}
				
			}
		}
		memcpy(h, patch, sizeof h);
	}
	return ans ;
}

int main()
{
	cin >> T;
	while ( T-- ) {
		input();
		cout << "Case #" << nCase ++ << ": " << solv() << endl;
	}
	return 0;
}