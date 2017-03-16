#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef __int64 ll;
const int MAXN = 10010;
int E, R, N;
int val[MAXN];
int ans;


void dfs(int d, int e, int v){
    if(d == N){
        ans = max(ans, v);
        return ;
	}
    dfs(d+1, min(e+R, E), v);
    for(int i = 1; i <= e; i++){
        dfs(d+1, min(e-i+R, E), v+i*val[d]);
	}
}
int main()
{
    int T, cas = 1;
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.out", "w", stdout);
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &E, &R, &N);
        for(int i = 0; i < N; i++)
            scanf("%d", &val[i]);
        ans = 0;
        if(R >= E){
            for(int i = 0 ; i <  N; i++)
                ans += val[i]*E;
		}else{
			int v = 0;
			dfs(0, E, v);
		}
		printf("Case #%d: %d\n", cas++, ans);
	}
    return 0;
}