#include <cstdio>
#include <cstdlib>
#include <cstring>

int check(int x, int y, char a[], char b[], int n){
	int i;
	char xx[20], yy[20];
	sprintf(xx, "%0*d", n, x);
	sprintf(yy, "%0*d", n, y);
	for(i = 0;i < n;i++){
		if(a[i] != '?' && xx[i] != a[i])
			return 0;
		if(b[i] != '?' && yy[i] != b[i])
			return 0;
	}
	return 1;
}

int main()
{
	int t, caseNum = 1, i, j, ans_a, ans_b, n, min;
	char a[20], b[20];
	scanf("%d", &t);
	while(t--){
		scanf("%s%s", a, b);
		n = 1;
		for(i = 0;i < strlen(a);i++)
			n *= 10;
		min = 2147483647;
		ans_b = ans_a = -1;
		for(i = 0;i < n;i++){
			for(j = 0;j < n;j++){
				if(check(i, j, a, b, strlen(a)) == 1){
					if(abs(i - j) <= min){
						if(ans_a == -1 || ans_b > j || min > abs(i - j)){
							ans_a = i;
							ans_b = j;
							min = abs(i - j);
						}
					}
				}
			}
		}
		printf("Case #%d: %0*d %0*d\n", caseNum++, strlen(a), ans_a, strlen(a), ans_b);
	}
	return 0;
}
