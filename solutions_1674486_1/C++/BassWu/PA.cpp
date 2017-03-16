#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
using namespace std;
int map[1005][1005];
int head[1005];
int v[1005];
int top;
int N, M;

int main()
{
	int T;
	int B;
	scanf("%d", &T);
	for ( int t = 1 ; t <= T ; t++ ) {
		scanf("%d", &N);
		memset(map,0,sizeof(map));
		top = 0;
		for ( int i = 1 ; i <= N ; i++ ) {
			scanf("%d", &M);
			for ( int j = 0 ; j < M ; j++ ) {
				scanf("%d", &B);
				map[i][B] = 1;
			}
		}
		int key = 0;
		for ( int k = 1 ; k <= N ; k++ ) {
			for ( int i = 1 ; i <= N ; i++ ) {
				for ( int j = 1 ; j <= N ; j++ ) {
					if (map[i][k] && map[k][j]) {
						map[i][j]++;
					}
					if ( map[i][j] >= 2 ) {
						key = 1;
						break;
					}
				}
				if ( key ) break;
			}
			if ( key ) break;
		}
		if ( key )	
			printf("Case #%d: Yes\n", t);	
		else
			printf("Case #%d: No\n", t);
	}
	return 0;
}
