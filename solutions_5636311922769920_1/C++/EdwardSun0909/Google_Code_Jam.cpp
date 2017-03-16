#include<stdio.h>
#include<string.h>
#define MAXN 120
#define MAXANS 20
//FILE* fin = fopen("input.in", "r+");
//FILE* fout = fopen("output.out", "w+");
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
	ANSWER& operator-=(int x) {
		n[0] -= x;
		sort();
		return *this;
	}
	ANSWER& operator*=(int x) {
		for (int i = 0; i < MAXANS; i++)
			n[i] *= x;
		sort();
		return *this;
	}
	ANSWER operator*(int x) {
		ANSWER ans(*this);
		for (int i = 0; i < MAXANS; i++)
			ans.n[i] *= x;
		ans.sort();
		return ans;
	}
	ANSWER& operator+=(int x) {
		n[0] += x;
		sort();
		return *this;
	}
	void print() {
		int p = MAXANS - 1;
		while (p > 0 && n[p] == 0) p--;
		for (int i = p; i >= 0; i--)
			printf("%d", n[i]);
			//fprintf(fout, "%d", n[i]);
	}
	ANSWER& operator+=(ANSWER x) {
		for (int i = 0; i < MAXANS; i++)
			n[i] += x.n[i];
		sort();
		return *this;
	}
	void generate(int C) {
		*this = 0;
		ANSWER tmp(1);
		for (int i = 1; i < C; i++) {
			*this += (tmp *(C - i));
			tmp *= C;
		}
	}
};
int main() {
	int T;
	ANSWER ans[MAXN];
	//fscanf(fin, "%d", &T);
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		int K, C, S;
		//fscanf(fin, "%d%d%d", &K, &C, &S);
		scanf("%d%d%d", &K, &C, &S);
		//fprintf(fout, "Case #%d:", k);
		printf("Case #%d:", k);
		if (S*C < K)
			//fprintf(fout, " IMPOSSIBLE\n");
			printf(" IMPOSSIBLE\n");
		else {
			ANSWER metadrome;
			metadrome.generate(C);
			for (int i = 1; i <= K; i++)
				ans[i] = i;
			for (int j = 1; j < C; j++)
				for (int i = 1; i <= K; i++) {
					((ans[i] -= 1) *= K) += i;
				}
			for (int i = 0; i < K/C; i++) {
				//fprintf(fout, " ");
				printf(" ");
				ans[i*C + 1] += metadrome;
				ans[i*C + 1].print();
			}
			if (K - (K / C)*C > 0) {
				metadrome.generate(K - (K / C)*C);
				//fprintf(fout, " ");
				printf(" ");
				ans[(K / C)*C + 1] += metadrome;
				ans[(K / C)*C + 1].print();
			}
			//fprintf(fout, "\n");
			printf("\n");
		}										
	}
	//fclose(fin);
	//fclose(fout);
}