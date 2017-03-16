#include<cstdio>

char a[5000], s[2000];
int l = 2500, r = 2500;
int n;

int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
		scanf("%s", s);

		for (int j = 0; s[j]; j++){
			if (j == 0){
				a[l] = s[j];
			}else if (a[l] <= s[j]){
				a[--l] = s[j];
			}else {
				a[++r] = s[j];
			}
		}

		printf("Case #%d: ", i);
		for (int j = l; j <= r; j++){
			printf("%c", a[j]);
		}
		printf("\n");

		l = r = 2500;;
	}
	return 0;
}
