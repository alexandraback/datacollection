// A.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int  pole[1111];
char text[1111];

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt","r", stdin );
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	
	for (int t = 0; t < T; t++){
		int smax;
		int chybi = 0;
		int tleska = 0;
		scanf("%d", &smax);
		scanf("%s", text);
		for (int i = 0; i <= smax; i++){

			pole[i] = text[i] - '0';
			if (tleska < i){
				int pridat = i - tleska;
				tleska += pridat;
				chybi += pridat;
			}
			tleska += pole[i];
		}
		printf("Case #%d: %d\n", t + 1, chybi);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}

