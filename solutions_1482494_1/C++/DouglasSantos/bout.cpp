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
#define MAXN 1500
int n;
int v[MAXN][2];

typedef struct Elemento {
	int x, y, ind;	
}Elemento;

Elemento a[MAXN];
Elemento b[MAXN];

bool comp1(Elemento a, Elemento b) {
	if (a.x == b.x) {
		return a.y > b.y;	
	}
	return a.x < b.x;
}

bool comp2(Elemento a, Elemento b) {
	return a.y < b.y;
}
bool used[MAXN][2];

bool completo() {
	for (int i = 0; i < n; i++) {
		if (!used[i][1]) return false;
	}
	return true;	
}


int calcula() {
	int res = 0;
	int stars = 0;
	memset(used, false, sizeof(used));
	int x, ind;
	while (1) {
		
		if (completo()) return res;
		
		ind = -1;
		x = -1;	
		for (int i = 0; i < n; i++) {
			if (!used[i][1]) {
				if (v[i][1] <= stars) {
					
					res++;
					ind = -2;
					used[i][1] = true;
					if (used[i][0]) stars += 1;
					else {
						used[i][0] = true;
						stars += 2;
					}
					break;	
				}
			}
			if (!used[i][0]) {
				if (v[i][0] <= stars) {
					if (v[i][1] > x) {
						x = v[i][1];
						ind = i;
					}
				}	
			}
		}
		if (ind == -2) continue;
		if (ind == -1) return INF;
		
		used[ind][0] = true;
		stars++;
		res++;	
	}
		
}

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d", &n);
		for (int i = 0 ;i < n; i++) {
			scanf("%d %d", &v[i][0], &v[i][1]);
			a[i].x = v[i][0];
			a[i].y = v[i][1];
			a[i].ind = i;
			b[i] = a[i];
		}
		sort(a, a + n, comp1);
		sort(b, b + n, comp2);
		int res;
		res = calcula();
		if (res == INF) {
			printf("Case #%d: Too Bad\n", k+1);	
		}
		else
			printf("Case #%d: %d\n", k+1, res);
	}
	return 0;
}