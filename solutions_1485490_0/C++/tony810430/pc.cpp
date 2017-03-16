#include<stdio.h>
int T,N,M;
int package[5],p_num[5],gift[105],g_num[105];
int gap[10],cnt;
void input()
{
	scanf(" %d %d",&N,&M);
	int a,b,tail=0;
	for( int i = 0; i < N; i++ ){
		scanf(" %d %d",&a,&b);
		if( i > 0 && package[i-1] == b ){
			p_num[i-1] += a;
			i--, N--;
		}
		else{
			p_num[i] = a;
			package[i] = b;
		}
	}
	for( int i = 0; i < M; i++ ){
		scanf(" %d %d",&a,&b);
		if( i > 0 && gift[i-1] == b ){
			g_num[i-1] += a;
			i--, M--;
		}
		else{
			g_num[i] = a;
			gift[i] = b;
		}
	}
}
void dfs(int d,int f)
{
	int sum = 0,tmp;
	if( d == N-1 ){
		for( int i = 0; i < N; i++ ){
			tmp = 0;
			for( int j = gap[i]; j <= gap[i+1] && j < M; j++ ){
				if( gift[j] == package[i] )
					tmp += g_num[j];
			}
			sum += (p_num[i]<tmp?p_num[i]:tmp);
		}
		if( sum > cnt )
			cnt = sum;
	}
	else{
		for( int i = f; i < M; i++ ){
			gap[d+1] = i;
			gap[d+2] = M;
			dfs(d+1,i);
		}
	}
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("pc.txt","w",stdout);
	scanf(" %d",&T);
	for( int x = 1; x <= T; x++ ){
		input();
		cnt = 0;
		gap[0] = 0;
		gap[1] = M;
		dfs(0,0);
		printf("Case #%d: %d\n",x,cnt);
	}
	return 0;
}
