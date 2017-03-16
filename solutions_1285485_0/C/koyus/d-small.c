#include<stdio.h>
#include<string.h>

int x, y;
int D;
char pos[30][30];

// 符号抜きだし
int symbol(int a) {
	if (a == 0) return 0;
	else if (a > 0) return 1;
	else return -1;
}

// 絶対値
double abst(double a) {
	if (a>=0) return a;
	else return -a;
}

// 各向きのチェック
int checkEachDirection(int direct_x, int direct_y){
	int cur_x, cur_y;	//現在の位置
	int k = 0;			//中心通過回数
	int cost;				//距離
	int x_change = symbol(direct_x);	//進行方向x
	int y_change = symbol(direct_y);	//進行方向y

	int next_x;			//#判定用x
	int next_y;			//#判定用y
	double tmp_x;		//xの移動判定
	double tmp_y;		//xが.5の時のy
	double next_tmp_y;	//yの移動判定

	cur_x = x;
	cur_y = y;

	for(k = 1; ; k++){
		//中心通過位置判定

		//距離は二乗で判定
		cost = k * k * ((direct_x * direct_x) + (direct_y * direct_y));
		if (cost > D * D) break;

		//現在位置更新
		next_tmp_y = 0.5;
		for (tmp_x = 0.5; tmp_x < abst(direct_x); tmp_x+=1){	//中心にくるまでx移動
			tmp_y = abst((double)(tmp_x * direct_y) / (double)direct_x);

			while (tmp_y > next_tmp_y) {	//xが.5の時までにyが.5になってたらcur_y更新
				next_y = cur_y + y_change;

				//#-check
				if (pos[cur_x][next_y] != '#') cur_y = next_y;
				else y_change *= -1;

				next_tmp_y += 1;
			}

			if (tmp_y == next_tmp_y) {			//xの.5とyの.5が揃ったらcur_x, cur_y更新
				// x,y-move
				next_x = cur_x + x_change;
				next_y = cur_y + y_change;

				//#-check
				if (pos[next_x][next_y] == '#') {	//行き先が#だったら
					if (pos[cur_x][next_y] != '#' && pos[next_x][cur_y] != '#') {	//へこみ角だったらdestroy
						return 0;
					}
					if (pos[cur_x][next_y] == '#') {	//yに壁があったらcur_yはそのままで向き変更
						next_y = cur_y;
						y_change *= -1;
					}
					if (pos[next_x][cur_y] == '#') {	//xに壁があったらcur_xはそのままで向き変更
						next_x = cur_x;
						x_change *= -1;
					}
				}
				//cur_x, cur_y更新
				cur_x = next_x;
				cur_y = next_y;

				next_tmp_y += 1;

			}else{		//xだけで.5になったらcur_x更新
				// x-move
				next_x = cur_x + x_change;

				//#-check
				if (pos[next_x][cur_y] != '#') cur_x = next_x;
				else x_change *= -1;

			}
		}

		for ( ; next_tmp_y < abst(direct_y); next_tmp_y += 1) {	//中心にくるまでy移動

			next_y = cur_y + y_change;

			//#-check
			if (pos[cur_x][next_y] != '#') cur_y = next_y;
			else y_change *= -1;
		}

		// position-check
		if (x == cur_x && y == cur_y) {	//現在の中心位置がスタートと同じだったら成功
			return 1;
		}
	}
	return 0;
}

int checkFourDirection(int direct_x, int direct_y){
	int count = 0;
	count += checkEachDirection(direct_x, direct_y);
	count += checkEachDirection(direct_x, direct_y * (-1));
	count += checkEachDirection(direct_x * (-1), direct_y);
	count += checkEachDirection(direct_x * (-1), direct_y * (-1));

	return count;
}

int checkAllCombi(int direct_x, int direct_y) {
	int count = 0;
	count += checkFourDirection(direct_x, direct_y);
	if (direct_x != direct_y)
		count += checkFourDirection(direct_y, direct_x);
	return count;
}

int checkEachZeroDirection(int direct_x, int direct_y){
	int cur_x, cur_y;
	int next_x, next_y;
	int x_change, y_change;
	int k = 0;
	int cost;

	x_change = symbol(direct_x);
	y_change = symbol(direct_y);

	cur_x = x;
	cur_y = y;

	for(k = 1; ; k++){
		cost = k * k * ((direct_x * direct_x) + (direct_y * direct_y));
		if (cost > D * D) break;

		// move
		next_x = cur_x + x_change;
		next_y = cur_y + y_change;

		// #-check
		if (pos[next_x][next_y] == '#') {
			x_change *= -1;
			y_change *= -1;
		}else{
			cur_x = next_x;
			cur_y = next_y;
		}

		// position-check
		if (x == cur_x && y == cur_y){
			return 1;
		}
	}
	return 0;
}

int minimum(int a, int b) {
	if (a < b) return a;
	else return b;
}

int checkCommonDivisor(int a, int b){
	int i;
	int min = minimum(a,b);
	for (i = 2; i <= min; i++) {
		if (a % i == 0 && b % i == 0) return 1;
	}
	return 0;
}

int main() {
	int T, H, W;
	int i, j, k;
	int direct_x, direct_y;
	int count;
	FILE *in, *out;

	in = fopen("D-small-attempt5.in", "r");
	out = fopen("output.txt", "w");

	fscanf(in, "%d", &T);
	for (i = 0; i < T; i++) {
		fscanf(in, "%d %d %d", &H, &W, &D);

		for (j = 0; j < H; j++) {
			fscanf(in, "%s", pos[j]);
			for (k = 0; k < W; k++){
				if (pos[j][k] == 'X'){
					x = j;
					y = k;
					break;
				}
			}
		}

		count = 0;
		
		// 0check
		count += checkEachZeroDirection(0, 1);
		count += checkEachZeroDirection(0, -1);
		count += checkEachZeroDirection(1, 0);
		count += checkEachZeroDirection(-1, 0);

		// other check
		for (direct_x = 1; direct_x < D; direct_x++) {
			for (direct_y = 1; ; direct_y++) {

				// check common divisor
				if (checkCommonDivisor(direct_x, direct_y)) continue;

				// cost-check
				if ((direct_x * direct_x) + (direct_y * direct_y) > D * D) break;

				count += checkFourDirection(direct_x, direct_y);
			}
		}
		fprintf(out, "Case #%d: %d\n", i+1, count);
	}
	fclose(in);
	fclose(out);

}
