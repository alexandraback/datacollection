#include <cstdio>
#include <cmath>

using namespace std;

const int sys[4][4] = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};

int cases, casei, L;
long long X;
char st[10010];


inline int sgn(int now) {
	if (now > 0) return 1;
	return -1;
}

inline int abs(int now) {
	return now * sgn(now);
}

inline int multiply(int x, int y) {
	return sys[abs(x) - 1][abs(y) - 1] * sgn(x) * sgn(y);
}

bool minus1() {
	int res = 1;
	for (int i = 0; i < L; ++i) {
		res = multiply(res, st[i] - 'g');
	}
	//printf("res %d\n", res);
	
	int now = res;
	int rX = int((X + 3LL) % 4LL) + 1;
	for (int i = rX - 1; i > 0; --i) {
		res = multiply(res, now);
	}
	
	return (res == -1);
}

int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d%lld", &L, &X);
		scanf(" %s", st);
		bool ans = false;
		
		if (minus1()) {
			//printf("-1!\n");
			int res = 1;
			
			int iPosi = -1;
			for (int i = 0; i < X && i < 4 && iPosi == -1; ++i) {
				for (int j = 0; j < L; ++j) {
					res = multiply(res, st[j] - 'g');
					//printf("%d %d: %d;\t", i, j, res);
					
					//printf("---> %d %d\n", res==2, (i * L + j + 1 <= rX * L - 2));
					//printf("%d %d\n", i * L + j + 1, rX * L - 2);
					if (res == 2) {
						iPosi = i * L + j + 1;
						break;
					}
				}
			}
			
			res = 1;
			int kPosi = -1;
			for (int i = 0; i < X && i < 4 && kPosi == -1; ++i) {
				for (int j = L - 1; j >= 0; --j) {
					res = multiply(st[j] - 'g', res);
					if (res == 4) {
						kPosi = i * L + L - j;
						break;
					}
				}
			}
			
			//printf("iPost: %d kPosi: %d\n", iPosi, kPosi);
			int rX = int((X + 15LL) % 16LL) + 1;
			if (X > 16LL) rX += 16;
			//printf("%d %d\n", iPosi + kPosi, rX * L);
			ans = (iPosi != -1 && kPosi != -1 && iPosi + kPosi < rX * L);
		}
		
		if (ans) printf("Case #%d: YES\n", casei);
		else printf("Case #%d: NO\n", casei);
	}
	
	return 0;
}
