#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

bool YN;
char c;
int T, L, num[10000], t, multiplier;
long long X, mod;
int mul[][4] = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};
int target[] = {2, 4, -1};

int quate(int a, int b){
	int temp = a * b;
	int val = mul[abs(a) - 1][abs(b) - 1];
	if (temp < 0) val *= -1;
	return val;
}

int main (){
	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);
	scanf("%d", &T);
	for (int i = 1; i <= T; i++){
		scanf("%d %I64d\n", &L, &X);
		t = 0;
		YN = false;
		mod = (X - 1) % 4 + 1;
		for (int j = 0; j < L; j++){
			scanf("%c", &c);
			num[j] = c - 'i' + 2;
			if (j)
				num[j] = quate(num[j - 1], num[j]);
			if (t < 2 && num[j] == target[t])
				t++;
		}
		multiplier = num[L - 1];
		if (mod == 1 && num[L - 1] == -1)
			YN = true;
		for (long long j = 2; j <= min((long long)8, X); j++){
			for (int k = 0; k < L; k++){
				num[k] = quate(multiplier, num[k]);
				if (t < 2 && num[k] == target[t])
					t++;
			}
			if (mod == j && num[L - 1] == -1)
				YN = true;
		}
		printf("Case #%d: %s\n", i, (t == 2 && YN) ? "YES" : "NO");
	}
	return 0;
}
