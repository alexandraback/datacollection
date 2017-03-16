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

int a, b;

int calcula(int n) {
	vector<int> num;
	int aux = n;
	while (aux != 0) {
		num.push_back(aux % 10);
		aux = aux / 10;
	}
	int x = 0;
	int res = 0;
	map<int, int> mapa;
	reverse(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		x = 0;
		for (int j = 0; j < num.size(); j++) {
			x = x * 10 + num[((i+j) % num.size())];
		}
		if (x > n && x <= b) {
			if (mapa.find(x) == mapa.end()) {
				//printf("%d %d\n", n, x);
				res++;
				mapa[x] = 1;	
			}
		}
	}
	return res;	
}

int main()
{	
	int t;
	scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		scanf("%d %d", &a, &b);
		int64 res = 0;
		for (int i = a; i < b; i++) {
			res += calcula(i);
		}
		printf("Case #%d: %lld\n", k+1, res);
	}	
	return 0;
}