// B.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

char klavesnice[111];
char slovo[111];
int cetnost[26];
double sance[26];

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("vstup.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	int k, l, s;
	for (int t = 1; t <= T; t++){
		bool hotovo = false;
		scanf("%d %d %d", &k, &l, &s);
		scanf("%s", klavesnice);
		scanf("%s", slovo);
		for (int i = 0; i < 26; i++){
			cetnost[i] = 0;
		}
		for (int i = 0; i < k; i++){
			cetnost[klavesnice[i] - 'A']++;
		}
		for (int i = 0; i < 26; i++){
			if (cetnost[i] == 0){ sance[i] = 0; }
			else{
				sance[i] = (double)cetnost[i]/k;
			}
		}
		int bananu = 0;
		int prekryv = l;
		
		for (int i = 1; i < l; i++){
			bool funguje = true;
			for (int j = 0; j < l - i; j++){
				if (slovo[i+j] != slovo[j]){ funguje = false; break; }
			}
			if (funguje){
				prekryv = i;
				break;
			}
		}
		bananu = max(0, (s - l) / prekryv + 1);
		double uspech = 1;
		for (int i = 0; i < l; i++){
			uspech *= sance[slovo[i] - 'A'];
			if (cetnost[slovo[i] - 'A'] == 0){ printf("Case #%d: 0.0\n", t); hotovo = true; break; }
		}
		if (!hotovo){
			printf("Case #%d: %5.8llf\n", t, (double)bananu - (double)uspech*(s - l + 1));
		}
	}
	return 0;
}
