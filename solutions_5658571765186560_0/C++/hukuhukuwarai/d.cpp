#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

#define REP(i,n) for (int i=0;i<(n);i++)

/*グローバル変数は0で初期化される*/
/*テストケース変数*/
int T;

int main() {
	scanf("%d", &T);
	/*繰り返す時の変数初期化忘れに気を付ける*/
	for (int Case = 1; Case<= T; Case++){
		int X, R,C;
		scanf("%d", &X);
		scanf("%d", &R);
		scanf("%d", &C);

		if (X >= 7) { printf("Case #%d: RICHARD\n", Case); }//囲み
		else if (X >= (min(R, C) + 1) * 2 - 1) {
			printf("Case #%d: RICHARD\n", Case);//Ｌ字
		}
		else if (X > max(R, C)) {
			printf("Case #%d: RICHARD\n", Case);//縦棒
		}
		else if ((R*C) % X != 0) {
			printf("Case #%d: RICHARD\n", Case);
		}
		//最小幅がmin(R,C)を超えてきたら気を付ける。
		//L字は端っこに寄せるだけ
		else if(min(R,C) == 2 && X>=4){//3は長方形作れる
			printf("Case #%d: RICHARD\n", Case);
		}
		//2の場合は余った領域の偶奇が確定するのでわかりやすかった。
		//５ミノで作れる最少の長方形は15（最大公倍数）
		//６ミノの時はt形の時に両側のmod3が合わない
		else if (min(R, C) == 3 && X==5 && R*C % 15 == 0){ //X=4なら最小幅は2
			printf("Case #%d: RICHARD\n", Case);
		}
		else if (min(R, C) == 3 && X == 6){
			printf("Case #%d: RICHARD\n", Case);
		}
		else {
			printf("Case #%d: GABRIEL\n", Case);
		}
	}
	return 0;
}

/* printf("Case #%d:",C); */