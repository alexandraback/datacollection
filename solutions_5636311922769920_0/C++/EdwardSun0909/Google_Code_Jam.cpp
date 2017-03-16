#include<stdio.h>
#include<string.h>
#define MAXN 120
#define MAXANS 20
class ANSWER {
private:
	int n[MAXANS];
public:
	void sort() {
		int tmp = 0;
		for (int i = 0; i < MAXANS; i++) {
			if (n[i] < 0) {
				n[i] += 10;
				n[i + 1] -= 1;
			}
			n[i] += tmp;
			tmp = n[i] / 10;
			n[i] %= 10;
		}
	}
	ANSWER(){}
	ANSWER(int x) {
		memset(n, 0, sizeof(n));
		n[0] = x;
		sort();
	}
	ANSWER& operator-(int x) {
		n[0] -= x;
		sort();
		return *this;
	}
	ANSWER& operator*(int x) {
		for (int i = 0; i < MAXANS; i++)
			n[i] *= x;
		sort();
		return *this;
	}
	ANSWER& operator+(int x) {
		n[0] += x;
		sort();
		return *this;
	}
	void print() {
		int p = MAXANS - 1;
		while (p > 0 && n[p] == 0) p--;
		for (int i = p; i >= 0; i--)
			printf("%d", n[i]);
	}
};
int main() {
	int T;
	ANSWER ans[MAXN];
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		for (int i = 1; i <= K; i++)
			ans[i] = i;
		for (int j = 1; j < C; j++)
			for (int i = 1; i <= K; i++) {
				ans[i] = (ans[i] - 1)*K + i;
			}
		printf("Case #%d:", k);
		for (int i = 1; i <= K; i++) {
			printf(" ");
			ans[i].print();
		}
		printf("\n");
	}
}