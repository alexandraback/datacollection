#include<stdio.h>
#include<string.h>
#define MAXN 33
#define MAXP 100000
#define MAXP_100000 10000
int Prime[MAXP_100000];
int N, T, J;
void Init() {
	memset(Prime, 0, sizeof(Prime));
	for (int i = 2; i < MAXP; i++) {
		bool flag = true;
		for (int j = 1; j <= Prime[0]; j++)
			if (i % Prime[j] == 0) {
				flag = false;
				break;
			}
		if (flag)
			Prime[++Prime[0]] = i;
	}
}
class NUMBER {
private:
	int n[MAXN];
	int base;
public:
	NUMBER():base(2) {
		n[0] = n[N - 1] = 1;
		for (int i = 1; i < N - 1; i++)
			n[i] = 0;
	}
	bool empty() {
		for (int i = 0; i < N; i++)
			if (n[i]) return false;
		return true;
	}
	int remainder(int Base) {
		int ans = 0;
		for (int i = N - 1; i >= 0; i--) {
			ans = ans*base + n[i];
			while (ans >= Base)
				ans -= Base;
		}
		return ans;
	}
	void division(int Base) {
		int tmp = 0;
		for (int i = N - 1; i >= 0; i--) {
			tmp = tmp*base + n[i];
			n[i] = tmp / Base;
			tmp = tmp % Base;
		}
	}
	NUMBER(NUMBER Number, int Base):base(Base) {
		for (int i = 0; i < MAXN; i++)
			n[i] = Number.n[i];
	}
	bool zero() {
		for (int i = N - 1; i > 0; i--)
			if (n[i]) return false;
		if (n[0] != 1)
			return false;
		return true;
	}
	int factor() {
		for (int i = 1; i < Prime[0]; i++) {
			if ((*this).remainder(Prime[i]) == 0) {
				division(Prime[i]);
				while  (Prime[i] == 32833) {
					break;
				}
				return (zero()) ? 0 : Prime[i];
			}
		}
		return 0;
	}
	bool print() {
		int fac[11];
		for (int base = 2; base <= 10; base++) {
			NUMBER Num(*this, base);
			fac[base] = Num.factor();
			if (fac[base] == 0)
				return false;
		}
		for (int i = N - 1; i >= 0; i--)
			printf("%d", n[i]);
		for (int base = 2; base <= 10; base++)
			printf(" %d", fac[base]);
		printf("\n");
		return true;
	}
	NUMBER& operator++() {
		int i = 1;
		n[i]++;
		while (n[i]>1) {
			n[i] = 0;
			n[++i]++;
		}
		return *this;
	}
};

int main() {
	Init();
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d%d", &N, &J);
		printf("Case #%d:\n", k);
		NUMBER Num;
		for (int i = 0; i < (1 << N - 2); i++)
			if ((++Num).print() && --J == 0)
				break;
	}
}