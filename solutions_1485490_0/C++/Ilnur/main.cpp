#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

typedef long long LL;

using namespace std;

pair<LL, LL> P1[105], P2[105];

LL solve(){
	memset( P1, 0, sizeof(P1) );
	memset( P2, 0, sizeof(P2) );
	int N, M;
	scanf( "%d%d", &N, &M );
	//line 1
	for( int i = 0; i < N; ++ i ){
		LL t, cnt;
		scanf( "%lld%lld", &cnt, &t );
		P1[i] = make_pair( t, cnt );
	}
	//line 2
	for( int i = 0; i < M; ++ i ){
		LL t, cnt;
		scanf( "%lld%lld", &cnt, &t );
		P2[i] = make_pair( t, cnt );
	}

	LL best = 0;

	for( int c = 0; c < ( 1 << N); ++ c ){
		LL ans = 0;
		int k = 0;
		LL cnt1 = 0, cnt2 = 0;
		
		for( int i = 0; i < N; ++i, cnt1 = 0 ){
			if ( c & ( 1 << i ) ){
				
				for( int j = k; j < M; ++j, cnt2 = 0 ){
					if( P1[i].first == P2[j].first ){
						if ( P1[i].second - cnt1 < P2[j].second - cnt2 ){
							ans += P1[i].second - cnt1;
							cnt2 += P1[i].second - cnt1;
							k = j;
							break;
						}
						else{
							if ( P1[i].second - cnt1 > P2[j].second - cnt2 ){
								ans += P2[j].second - cnt2;
								cnt1 += P2[j].second - cnt2;
								k = j;
							}
							else{
								if ( P1[i].second - cnt1 == P2[j].second - cnt2 ){
									ans += P2[j].second - cnt2;
									cnt1 = 0;
									cnt2 = 0;
									k = j;
									break;
								}
							}
						}

					}
				}
			}
		}
		best = max( best, ans );
	}

	return best;
}

void input_output(){
	int T;
	scanf( "%d\n", &T );
	for( int t = 1; t <= T; ++t ){		
		printf("Case #%d: %lld\n", t, solve() );
	}
}

int main(){
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	input_output();

	return 0;
}