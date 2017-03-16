#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<assert.h>

// N:残りダイヤモンド数 l:左にスライドできる数　r:右にスライドしないとならない個数
double F(int N, int l, int r){
	if(!r)return 1;
	if(!N)return 0;
	if(l==0)return F(N-1, l, r-1);
	else return (F(N-1,l-1,r) + F(N-1,l,r-1))/2;
}

double Solve(int N, int x, int y){
	// 三角数個無ければ不可能　あれば必ず可能
	if(x==0){
		return (N >= (((y+2)*(y+1)/2)));
	}
	// 確定で埋まるピラミッド分の高さ(天頂部分のy座標)
	int h=1;
	while( (h*(h+1))/2 <= N){
		h+=2;
	}
	h-=2;
	int z = abs(x)+abs(y);
	if(z < h)return 1;
	int rest = N-(h*(h+1))/2;
	// 残りrest個落ちるので、それがx,yにかぶさるか判定
	return F(rest, (h+1), (h+1)-x+1);

#if 0
	// 満点会法を狙った残骸
	const int DP_SIZE = 1024;
	static double dp[DP_SIZE][DP_SIZE] = {};	//[今まで何個つまれた][左に積まれている個数]になる確立
	for(int i=0; i<DP_SIZE; ++i)
		for(int j=0; j<DP_SIZE; ++j)
			dp[i][j] = 0;
	dp[0][0] = 1;
	dp[1][0] = dp[1][1] = 0.5;
	for(int i=1; i<=rest; ++i){
		for(int j=0; j<i; ++j){
			//左にもう詰めない
			if(j>=h){
				dp[i][j] = dp[i-1][j];
			}
			// もう右に詰めない
			else if((i-j)>=h){
				dp[i][j] = dp[i-1][j-1];
			}
			// どちらにもスライドする可能性がる
			else{
				if(j==0) dp[i][0] = dp[i-1][0]/2;
				else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j])/2;
			}
		}
	}
	return dp[rest][y];
#endif
}

int main() {
	int T, caseNum;
	scanf("%d",&T);
	for(caseNum=1; caseNum<=T; ++caseNum) {
		int N, x, y;
		scanf("%d%d%d",&N,&x,&y);
		assert(N<=20);

		printf("Case #%d: %.9f\n", caseNum, Solve(N, abs(x), y));
	}
	return 0;
}
