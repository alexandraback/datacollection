#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef unsigned long long int uint64;
#define MAXN   1010

int N;
int isok[ MAXN ];

struct GAME{
	int s;
	int b;
};
GAME g[ MAXN ];

int solve(){
	int answer = 0;
	int solve_num = 0;
	int nowstar = 0;
	while( solve_num < N ){
		int level;
		int choose = -1;

		int max_big = 0;
		for( int i = 0;i < N; i++ ){
			if( isok[ i ] == 2 ) continue;
			if( g[i].b <= nowstar ){
				level = 2;
				choose = i;
				break;
			}
			if( isok[ i ] == 0 ){
				if( g[i].s <= nowstar ){
					if( max_big < g[i].b ){
						max_big = g[i].b;
						level = 1;
						choose = i;
					}
				}
			}
		}

		if( choose == -1 ) return -1;
		if( level == 2 ) solve_num++;

		//printf("%d %d %d, solve = %d\n", choose, level, nowstar, answer);

		nowstar += level - isok[ choose ];
		isok[ choose ] = level;
		answer++;
	}
	return answer;
}

int main() {
	int cases;		// number of cases
	int caseID = 1;	// case ID, start from 1

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &cases);
	while (cases--) {
		memset(isok, 0, sizeof(isok));

		scanf("%d", &N);
		for(int i = 0;i < N; i++){
			scanf("%d%d", &g[i].s, &g[i].b);
		}

//		for(int i = 0;i < N; i++){
//			printf("%d %d\n", s[i].v, s[i].index);
//		}
//		for(int i = 0;i < N; i++){
//			printf("%d %d\n", b[i].v, b[i].index);
//		}


		int ans = solve();
		if( ans == -1 ){
			printf("Case #%d: Too Bad\n", caseID++);
		} else {
			printf("Case #%d: %d\n", caseID++, ans);
		}
		fflush(stdout);
	}
	return 0;
}
