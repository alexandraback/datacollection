#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <queue>
#include <stdlib.h>
#include <set>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stack>
#include <sstream>
#include <list>
#include <bitset>
#define ff first
#define ss second

using namespace std;

typedef long long ll;

bool ans[55][55];
int cont,m;

int pot(int a, int b){
	int r = 1;
	while(b){
		if(b&1) r*= a;
		a*=a;
		b/=2;
	}
	return r;
}

bool build(int i, int b, int tam, int aux){
	if(cont == m) return true;
	
	if(aux == tam){
		ans[i][b] = 1;
		cont++;
		return false;
	}

	for(int j = i+1; j < b; j++){
		if(build(j,b,tam,aux+1))
			return true;
		ans[i][j] = 1;
	}
	return false;
}

int main() {
	int t,n,tc=1,j,i;

	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		if(m > pot(n,n-2)){
			printf("Case #%d: IMPOSSIBLE\n", tc++);
			continue;
		}
		memset(ans,0,sizeof(ans));
		cont = 1;
		ans[1][n] = 1;
		for(i = 1; i < n-1; i++){
			if(build(1,n,i,0)) break;
		}
		printf("Case #%d: POSSIBLE\n", tc++);
		for(i = 1; i <= n; i++){
			for(j = 1; j <= n; j++){
				printf("%d", ans[i][j]);
			}
			printf("\n");
		}
	}

	return 0;
}
