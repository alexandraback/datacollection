#include<stdio.h>
#include<string.h>
int Num[10];
void fall_asleep(int N) {
	while (N > 0) {
		Num[N % 10]++;
		N /= 10;
	}
}
bool asleep() {
	bool flag = true;
	for (int i = 0; i < 10; i++)
		if (!Num[i])
			flag = false;
	return flag;
}
int main() {
	int N, T;
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &N);
		bool flag = false;
		memset(Num, 0, sizeof(Num));
		int i = 0;
		while (!flag && i < 100) {
			fall_asleep(N*(++i));
			flag = asleep();
		}
		printf("Case #%d: ", k);
		if (flag)
			printf("%d\n", N*i);
		else
			printf("INSOMNIA\n");
	}
}