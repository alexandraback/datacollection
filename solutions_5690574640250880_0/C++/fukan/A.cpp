#include<cstdio>
#include<cstring>

char a[100][100];

int main(){
	freopen("3.txt", "r", stdin);
	freopen("33.out", "w", stdout);
	int t;
	scanf("%d" , &t);
	for (int ii = 1;ii <= t;ii++){
		int m, n, k;
		scanf("%d%d%d" , &m, &n, &k);
		printf("Case #%d:\n",ii);
		if (k == m * n)
        {
			printf("Impossible\n");
			continue;
		} else if (m * n == k + 1) {
			memset(a, '*', sizeof(a));
			a[0][0] = 'c';
		} else if (m == 1){
			memset(a, '.', sizeof(a));
			a[0][0] = 'c';
			for (int i = 0;i < k;i++){
				a[0][n - 1 - i] = '*';
			}
		} else	if (n == 1){
			memset(a, '.', sizeof(a));
			a[0][0] = 'c';
			for (int i = 0;i < k;i++){
				a[m - 1 - i][0] = '*';
			}
		} else if (m == 2) {
			if (k % 2 == 1) {

				printf("Impossible\n");
				continue;
			}
			if (n * 2 - k == 2){

				printf("Impossible\n");
				continue;
			}
			for(int i = 0;i < n;i++){
				memset(a, '.', sizeof(a));
				a[0][0] = 'c';
				for (int i = 0;i < k / 2;i++){
					a[0][n - 1 - i] = a[1][n - 1 - i] =  '*';
				}
			}
		} else if (n == 2) {
			if (k % 2 == 1) {

				printf("Impossible\n");
				continue;
			}
			if (m * 2 - k == 2){

				printf("Impossible\n");
				continue;
			}
			for(int i = 0;i < n;i++){
				memset(a, '.', sizeof(a));
				a[0][0] = 'c';
				for (int i = 0;i < k / 2;i++){
					a[m - 1 - i][0] = a[m - 1 - i][1] =  '*';
				}
			}
		} else {
			if (n * m - k <= 3 && n * m - k != 1) {

				printf("Impossible\n");
				continue;
			}
			if (n * m - k == 5) {

				printf("Impossible\n");
				continue;
			}
			if (n * m - k == 7) {

				printf("Impossible\n");
				continue;
			}
			memset(a, '*', sizeof(a));
			a[0][0] = 'c';
			if (n * m - k != 1) {
				k = n * m - k - 4;
				a[1][0] = a[0][1] = a[1][1] = '.';
				int left = 3;
				int right = 2;

				if (k != 0){
					k -= 2;
					a[2][0] = a[2][1] = '.';
				}
				while (k >= 2 && right < n) {
					a[0][right] = '.';
					a[1][right] = '.';
					right++;
					k -= 2;
				}
				while (k >= 2 && left < m) {
					a[left][0] = '.';
					a[left][1] = '.';
					left++;
					k -= 2;
				}
				if (k == 0){
				} else if (k == 1){
					a[2][2] = '.';
				} else {
					left = 2;
					while (k != 0){
						right = 2;
						while(k != 0 && right < n){
							a[left][right] = '.';
							right ++;
							k--;
						}
						left++;
					}
				}
			}
		}
		for(int i = 0;i < m;i++){
			for(int j = 0;j < n;j++){
				printf("%c", a[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
