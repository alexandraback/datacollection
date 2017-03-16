#include<stdio.h>
#include<queue>
using namespace std;
int T,N,M,map[1005][1005],color[1005];
void input()
{
	int a;
	scanf(" %d",&N);
	for( int i = 0; i < N; i++ )
		for( int j = 0; j < N; j++ )
			map[i][j] = 0;
	for( int i = 0; i < N; i++ ){
		scanf(" %d",&M);
		while( M-- ){
			scanf(" %d",&a);
			map[i][a-1] = 1;
		}
	}
}
bool bfs()
{
	queue<int> qu;
	int now;
	for( int st = 0; st < N; st++ ){
		for( int i = 0; i < N; i++ )
			color[i] = 0;
		while( !qu.empty() )	qu.pop();
		qu.push(st);
		color[st] = 1;
		while( !qu.empty() ){
			now = qu.front();
			qu.pop();
			color[now] = 2;
			for( int i = 0; i < N; i++ ){
				if( map[now][i] > 0 ){
					if( color[i] == 0 ){
						qu.push(i);
						color[i] = 1;
					}
					else{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
    freopen("pa.txt","w",stdout);
	scanf(" %d",&T);
	for( int x = 1; x <= T; x++ ){
		input();
		printf("Case #%d: ",x);
		if( bfs() )	printf("Yes\n");
		else		printf("No\n");
	}
	return 0;
}
