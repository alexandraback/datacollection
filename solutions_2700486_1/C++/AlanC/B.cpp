#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <set>
#include <cstring>
#include <string>
#define LL long long int

#define FOR(i, s, e) for (int i=(s); i<(e); i++)
#define FOE(i, s, e) for (int i=(s); i<=(e); i++)
#define FOD(i, s, e) for (int i=(s)-1; i>=(e); i--)
#define CLR(x, a) memset(x, a, sizeof(x))
#define N 6005
using namespace std;

int test, n, X, Y, layer, R, fail, inside, need, x, y;
double dp[N][N], ret;

int main(){
	scanf("%d", &test);
	
	
	FOR(TC, 0, test){
		scanf("%d%d%d", &n, &X, &Y);
		layer = 0;
		while ((layer + 1) * (2 * layer + 1) <= n) layer++;
		R = n - layer * (2 * layer - 1);
		//printf("layer = %d\n", layer);
		
		inside = 0;
		fail = 0;
		
		if (X >= 0){
			if (X + Y <= 2 * (layer - 1)) inside = 1;
		}
		else {
			if (Y - X <= 2 * (layer - 1)) inside = 1;
		}
		
		if (inside) printf("Case #%d: 1.0\n", TC + 1);
		else {
			
			layer++;
			if (X >= 0){
				if (X + Y <= 2 * (layer - 1))
					need = Y;
				else fail = 1;
			}
			else {
				if (Y - X <= 2 * (layer - 1)) need = Y;
				else fail = 1;
			}
			
			if (fail) printf("Case #%d: 0.0\n", TC + 1);
			else {
				//printf("TC[%d] : Layer = %d, X = %d, Y = %d\n", TC + 1, layer, X, Y);
				FOR(i, 0, N) FOR(j, 0, N) dp[i][j] = 0.0;
				
				dp[0][0] = 1.0;
				FOE(i, 0, R)
					FOE(j, 0, i){
						x = j;
						y = i - j;
						if (x == 2 * (layer - 1)) dp[x][y + 1] += dp[x][y];
						else if (y == 2 * (layer - 1)) dp[x + 1][y] += dp[x][y];
						else {
							dp[x + 1][y] += dp[x][y] * 0.5;
							dp[x][y + 1] += dp[x][y] * 0.5;
						}
					}
				
				ret = 0.0;
				FOE(i, need + 1, 2 * (layer - 1)) if (R - i >= 0) ret += dp[i][R - i];
				printf("Case #%d: %.8f\n", TC + 1, ret);
			}
			
		}
		
		
	}
	
	return 0;
}
