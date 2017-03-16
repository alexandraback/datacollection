#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int c;
	for(c = 1; c<=tc; c++){
		printf("Case #%d:\n", c);

		int r, c, m;
		scanf("%d%d%d", &r, &c, &m);

		int i, j;
		char res[55][55];
		bool flag = 0;
		for(i = 1; i<=r; i++){
			for(j = 1; j<=c; j++){
				res[i][j] = '.';
			}
		}

		if(m == r*c-1){
			flag = 1;

			for(i = 1; i<=r; i++){
				for(j = 1; j<=c; j++){
					res[i][j] = '*';
				}
			}
			res[1][1] = 'c';
		} else if(r == 1 || c == 1){
			flag = 1;

			for(i = 1; i<=m; i++){
				if(r == 1) res[1][i] = '*';
				else res[i][1] = '*';
			}

			if(r == 1) res[1][c] = 'c';
			else res[r][1] = 'c';
		} else if(r == 2 || c == 2){
			if(m%2 == 0 && r*c-m > 2){
				flag = 1;

				for(i = 1; i<=m/2; i++){
					if(r == 2) res[1][i] = res[2][i] = '*';
					else res[i][1] = res[i][2] = '*';
				}

				res[r][c] = 'c';
			}
		} else {
			int w, h;
			for(h = 2; h<=r; h++){
				for(w = 2; w<=c; w++){
					int remain = r*c - m - (w+h-1);
					if(w-1 + h-1 - 1 <= remain && remain <= (w-1)*(h-1)){
						flag = 1;

						remain -= w-1 + h-1 - 1;
						for(i = 1; i<=c; i++){
							int start;
							if(i == 1 || i == 2) start = h+1;
							else if(i > w) start = 1;
							else {
								int q = remain / (w-2), s = remain % (w-2);
								if(i-2 <= s) start = q+4;
								else start = q+3;
							}

							for(j = start; j<=r; j++){
								res[j][i] = '*';
							}
						}
						res[1][1] = 'c';

						break;
					}
				}
				if(flag) break;
			}
		}

		if(flag){
			for(i = 1; i<=r; i++){
				for(j = 1; j<=c; j++)
					putchar(res[i][j]);
				puts("");
			}
		} else puts("Impossible");
	}

	return 0;
}