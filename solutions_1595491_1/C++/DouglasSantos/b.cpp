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

pair<Tripla, Tripla> v[150];
int n, s, p;
int pontos[5];

int memo[150][150];

int surpresa(Tripla t) {
	if (fabs(t.a - t.b) == 2) return 1;
	if (fabs(t.a - t.c) == 2) return 1;
	if (fabs(t.b - t.c) == 2) return 1;
	return 0;
}

int maior(Tripla t) {
	return max(t.a, max(t.b, t.c));	
}

void calcula(int ind) {
	
	v[ind].first.a = -1;
	v[ind].first.b = -1;
	v[ind].first.c = -1;
	v[ind].second.a = -1;
	v[ind].second.b = -1;
	v[ind].second.c = -1;
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
				if (surpresa(t)) {
					if (maior(v[ind].second) < maior(t)) {
						v[ind].second = t;	
					}
				}
				else {
					if (maior(v[ind].first) < maior(t)) {
						v[ind].first = t;	
					}
				}	
			}	
		}	
	}	
}

int rec(int x, int y) {
	if (x == n && y == 0) {
		return 0;	
	}
	if (x == n) {
		return -500;	
	}
	
	if (memo[x][y] != -1) return memo[x][y];
	
	int res = -500;
	
	if (v[x].first.a != -1) {
		res = rec(x+1, y);
		if (res != -500) {
			if (maior(v[x].first) >= p) {
				res = res + 1;
			}		
		}
	}
	
	int res2 = -500;
	if (v[x].second.a != -1) {
		if (y > 0) {
			res2 = rec(x+1, y-1);
			if (res2 != -500) {
				if (maior(v[x].second) >= p) {
					res2 = res2 + 1;	
				}
			}	
		}
	}
	return memo[x][y] = max(res, res2);
}	

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d", &n);
		scanf("%d", &s);
		scanf("%d", &p);
		for (int i = 0; i < n; i++) {
			scanf("%d", &pontos[i]);
			calcula(i);
		}
		memset(memo, -1, sizeof(memo));
		int res;
		res = rec(0, s);
		printf("Case #%d: %d\n", k+1, res);
	}
	return 0;
}