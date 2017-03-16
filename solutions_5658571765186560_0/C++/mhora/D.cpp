// D.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		int x, r, c;
		scanf("%d %d %d", &x, &r, &c);
		if ((r*c) % x != 0 || (x + 1) / 2 > min(r, c) || x >= 7){
			printf("Case #%d: RICHARD\n", t + 1);
		}
		else{
			if (x <= 3){
				printf("Case #%d: GABRIEL\n", t + 1);
			}
			if (x == 4){
				if (min(r, c) == 2){
					printf("Case #%d: RICHARD\n", t + 1);
				}
				else{
					printf("Case #%d: GABRIEL\n", t + 1);
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
}

