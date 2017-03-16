#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;

const int A = 110;
struct node{
	long long id, len;
}one[A], two[A];
long long total[A][A], dp[A][A], D[A][A], up[A][A];
inline void init()
{
    memset(total, 0, sizeof(total));
    memset(dp, 0, sizeof(dp));
    memset(up, 0, sizeof(up));
    memset(D, 0, sizeof(D));
}
void ans(int n,int m)
{
        for(int i = 1;i <= n; ++ i)
			scanf("%lld%lld", &one[i].len, &one[i].id);
		for(int i = 1;i <= m; ++ i)
			scanf("%lld%lld", &two[i].len, &two[i].id);
		for(int i = 1;i <= n; ++ i)
			for(int j = 1;j <= m; ++ j){
				total[one[i].id][j] = total[one[i].id][j - 1];
				if(one[i].id == two[j].id){
					total[one[i].id][j] += two[j].len;
				}
			}
		for(int i = 1;i <= n; ++ i)
			for(int j = 1;j <= m; ++ j){
				dp[i][j] = dp[i - 1][j];
				D[i][j] = D[i - 1][j];
				up[i][j] = up[i - 1][j];
				for(int k = 1;k <= j; ++ k){
					long long dd = 0, temp = total[one[i].id][j] - total[one[i].id][k - 1];
					if(D[i - 1][k - 1] == one[i].id)
						temp += up[i - 1][k - 1];
					if(temp > one[i].len)
						dd = temp - one[i].len;
					temp = dp[i - 1][k - 1] + min(temp, one[i].len);
					if(temp > dp[i][j]){
						dp[i][j] = temp;
						D[i][j] = one[i].id;
						up[i][j] = dd;
					}
				}
			}

}
int main()
{
	//freopen("1.in", "r", stdin);
	//freopen("2.txt", "w", stdout);
	int n, m, t;
	scanf("%d", &t);
	for(int ca = 1;ca <= t; ++ ca)
	{
		scanf("%d%d", &n, &m);
		ans(n,m);
		printf("Case #%d: %lld\n", ca, dp[n][m]);
	}
}
