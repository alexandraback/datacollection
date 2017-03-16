#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define REP(i,n) for (int i=0;i<(n);i++)

#define MAX_N 1000
#define INF 2000

/*グローバル変数は0で初期化される*/
/*テストケース変数*/
int T;

int main() {
	scanf("%d", &T);
	/*繰り返す時の変数初期化忘れに気を付ける*/
	for (int C = 1; C<= T; C++){
		int n;
		scanf("%d", &n);

		int num[MAX_N];
		int max = 0;

		REP(i, n){
			scanf("%d", &num[i]);
			if (max < num[i]) max = num[i];
		}

 		int mint = INF;

		for (int j = 1; j <= max; j++){//食い始めた時の最大値
			int divide = 0;
			for (int k = 0; k < n; k++){
				divide += num[k] / j;
				if (num[k] % j == 0) divide -= 1;
			}
			if (divide + j < mint) mint = divide + j;
		}

		printf("Case #%d: %d\n", C, mint);
	}
	return 0;
}

/* printf("Case #%d:",C); */