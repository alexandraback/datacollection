#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>

using namespace std;

int g[1005][1005];
int used[1005];
int N;

void clear(){
	N = 0;
	memset( g, 0 , sizeof(g) );
	memset( used, 0 , sizeof(used) );
}

int DFS( int v ){
	int ans = 0;
	used[v] = 1;

	for( int i = 0; i < N; ++i ){
		if ( g[v][i] ){
			if ( !used[i] ){
				ans += DFS( i );
			}
			else{				
				ans++;
			}
		}
	}

	return ans;
}

string solve(){
	bool ans = false;
	scanf( "%d", &N );

	// build graph
	for( int i = 0; i < N; ++i ){
		int M;
		scanf( "%d", &M );
		for( int j = 0; j < M; ++j ){
			int v;
			scanf( "%d", &v );
			g[i][v - 1] = 1;
		}
	}

	for( int i = 0; i < N; ++i ){
		memset( used, 0 , sizeof(used) );
		if ( DFS( i ) > 0 ){
			ans |= true; 
		}
		else{
			ans |= false;
		}
	}

	if ( ans )
		return "Yes";
	else
		return "No";

}

void input_output(){
	int T;
	scanf( "%d\n", &T );
	for( int t = 1; t <= T; ++t ){
		clear();
		printf("Case #%d: %s\n", t, solve().c_str() );
	}
}

int main(){
	freopen( "input.txt", "r", stdin );
	freopen( "output.txt", "w", stdout );
	input_output();

	return 0;
}