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

typedef struct Tripla {
	int a, b, c;
}Tripla;

vector<Tripla> v[5];
int n, s, p;
int pontos[5];

int surpresa(int i, int j) {
	if (fabs(v[i][j].a - v[i][j].b) >= 2) return 1;
	if (fabs(v[i][j].a - v[i][j].c) >= 2) return 1;
	if (fabs(v[i][j].b - v[i][j].c) >= 2) return 1;
	return 0;
}

int maior(int i, int j) {
	return max(v[i][j].a, max(v[i][j].b, v[i][j].c));	
}

void calcula(int ind) {
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			if (pontos[ind] - i - j >= 0 && pontos[ind] - i - j <= 10) {
				Tripla t;
				t.a = i;
				t.b = j;
				t.c = pontos[ind] - i - j;
				if (fabs(t.a - t.b) > 2) continue;
				if (fabs(t.a - t.c) > 2) continue;
				if (fabs(t.b - t.c) > 2) continue;
				v[ind].push_back(t);	
			}	
		}	
	}	
}

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d", &n);
		for (int i = 0; i < 3; i++) v[i].clear();
		scanf("%d", &s);
		scanf("%d", &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &pontos[i]);
			calcula(i);
		}
		int res = 0;
		int surp;
		if (n == 1) {
			for (int a = 0; a < v[0].size(); a++) {
				int x = 0;
				surp = surpresa(0, a);
				if (surp != s) continue;
				if (maior(0, a) >= p) x++;
				res = max(res, x);
			}
		}
		else if (n == 2) {
			for (int a = 0; a < v[0].size(); a++) {
				for (int b = 0; b < v[1].size(); b++) {
					int x = 0;
					surp = surpresa(0, a) + surpresa(1, b);
					if (surp != s) continue;
					if (maior(0, a) >= p) x++;
					if (maior(1, b) >= p) x++;
					res = max(res, x);
				}
			}		
		}
		else if (n == 3) {
			for (int a = 0; a < v[0].size(); a++) {
				for (int b = 0; b < v[1].size(); b++) {
					for (int c = 0; c < v[2].size(); c++) {
						int x = 0;
						surp = surpresa(0, a) + surpresa(1, b) + surpresa(2, c);
						if (surp != s) continue;
						if (maior(0, a) >= p) x++;
						if (maior(1, b) >= p) x++;
						if (maior(2, c) >= p) x++;
						res = max(res, x);
					}	
				}	
			}
		}
		printf("Case #%d: %d\n", k+1, res);
	}
	return 0;
}