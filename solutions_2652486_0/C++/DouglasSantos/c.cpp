#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cctype>
#include <stack>
using namespace std;

typedef long long int int64;

#define EPS 10e-9
#define INF 0x3f3f3f3f
#define REP(i,n) for(int i=0; i<(n); i++)

int n, m, x;
int v[10];

double p[10];
bool used[10];
int bi, bj, bk;
double res;

void get(int mask, int a, int b, int c) {
	int prod = 1;
	if (mask & 1) prod = prod*a;
	if (mask & 2) prod = prod*b;
	if (mask & 4) prod = prod*c;
	REP(i, x) {
		if (prod == v[i]) {
			used[i] = true;
			p[i] += (pow(0.5, __builtin_popcount(mask)) * pow(0.5, n - __builtin_popcount(mask)));
		}
	}
}

void calcula() {
	bi = 2;
	bj = 2;
	bk = 2;
	res = 0;
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= m; j++) {
			for (int k = 2; k <= m; k++) {
				memset(p, 0, sizeof(p));
				memset(used, false, sizeof(used));
				for (int mask = 0; mask < (1 << n); mask++) {
					get(mask, i, j, k);
				}
				double soma = 0;
				bool erro = false;
				for (int a = 0; a < x; a++) {
					if (!used[a]) {
						erro = true;
						break;
					}
					soma += p[a];
				}
				if (erro) continue;
				if (soma > res) {
					res = soma;
					bi = i;
					bj = j;
					bk = k;
				} 
			}	
		}
	}
	printf("%d%d%d\n", bi, bj, bk);
}

int main()
{	
	int t;
	scanf("%d", &t);
	printf("Case #1:\n");
	int r;

	scanf("%d %d %d %d", &r, &n, &m, &x);
	REP(k, r) {
		REP(i, x) {
			scanf("%d", &v[i]);
		}
		calcula();
	}
	return 0;
}