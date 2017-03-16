#include<cstdio>

int t;

int main(){
	scanf("%d", &t);
	for (int c = 1; c <= t; c++){
		int n;
		scanf("%d", &n);

		if (n == 0){
			printf("Case #%d: INSOMNIA\n", c);
			continue;
		}else {
			int tmp = 0, cf = 0;
			while (tmp != (1 << 10) - 1){
				int tn = (++cf) * n;
				while (tn != 0){
					tmp |= (1 << (tn % 10));
					tn /= 10;
				}
			}
			printf("Case #%d: %d\n", c, cf * n);
		}
	}
	return 0;
}
