// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;


int p[1111];
int optimum[1111];

bool comp(int a, int b){
	return a > b;
}

int pamet[1111][1111];
int getbest(int reseno, int snezeno){
	if (pamet[reseno][snezeno] != -1){ return pamet[reseno][snezeno]; }
	if (p[reseno] <= snezeno){ return pamet[reseno][snezeno] = 0; }
	int ans = p[reseno] - snezeno;
	for (int i = 1; i <= optimum[p[reseno]]; i++){
		ans = min(ans, i + max((p[reseno] + i) / (i + 1) - snezeno, 0) + getbest(reseno + 1, max(snezeno , (p[reseno]  + i) / (i + 1))));
	}
	return pamet[reseno][snezeno] = ans;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	for (int i = 0; i < 1111; i++){
		int tmp = i;
		for (int j = 1; j < i; j++){
			//optimum[i] = min(optimum[i], 1 + max(optimum[j], optimum[i - j]));
			int tmp2 = min(tmp, j + (i + j) / (j + 1));
			//optimum[i] = min(optimum[i], j + (i + j) / (j + 1));
			if (tmp2 < tmp){ tmp = tmp2; optimum[i] = j; }
		}
		//printf("%d %d %d\n", i, optimum[i].first, optimum[i].second);
	}
	
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		int d;
		scanf("%d", &d);
		//while (!Q.empty){ Q.pop(); }
		memset(p, 0, sizeof(p));
		memset(pamet, -1, sizeof(pamet));
		for (int i = 0; i < d; i++){
			scanf("%d", &p[i]);
		}
		sort(p, p+d, comp);
		
		int ans = getbest(0, 0);
		printf("Case #%d: %d\n", t+1, ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

