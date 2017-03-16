// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int mince[111];
bool pole[111];
//bool hodnoty[1000000111];
int c, d, v;

int pokryti(int pridano){
	for (int i = 0; i < v; i++){
		pole[i] = false;
	}
	pole[0] = true;
	vector<int> stavy;
	stavy.push_back(0);
	for (int i = 0; i < d+pridano; i++){
		int mez = (int)stavy.size();
		for (int s = 0; s < mez; s++){
			for (int j = 1; j <= c; j++){
				if (stavy[s] + j*mince[i] <= v+1 && (!pole[stavy[s] + j*mince[i]])){
					pole[stavy[s] + j*mince[i]] = true;
					stavy.push_back(stavy[s] + j*mince[i]);
				}
			}
		}
	}
	for (int i = 1; i <= v; i++){
		if (!pole[i]){ return i; }
	}
	return v+1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("vstup.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	for (int t = 1; t <= T; t++){
		int rslt;
		scanf("%d %d %d", &c, &d, &v);
		for (int i = 0; i < v; i++){
			pole[i] = false;
			//hodnoty[i] = false;
		}
		for (int i = 0; i < d; i++){
			scanf("%d", &mince[i]);
			//hodnoty[mince[i]] = true;
		}
		int add = 0;
		int ans;
		while ((ans = pokryti(add)) <= v){
			mince[d + add] = ans;
			add++;
		}


		printf("Case #%d: %d\n", t, add);
	}
	return 0;
}
