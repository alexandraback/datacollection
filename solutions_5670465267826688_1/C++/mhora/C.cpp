// C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

/*table
	i	 i
	I	-i
	j	 j
	J	-j
	k	 k
	K	-k
	n	 1
	N	-1
*/

char text[11111];
char prefix[11111];
char sufix[11111];

int tabulka[4][4];


char miinus(char a){
	if (a < 'z' && a > 'a'){ return a + 'A' - 'a'; }
	else return a + 'a' - 'A';
}


char nasob(char a, char b){
	int aa, bb;
	if (a == 'n'){ aa = 0; }
	else if (a == 'i'){ aa = 1; }
	else if (a == 'j'){ aa = 2; }
	else if (a == 'k'){ aa = 3; }
	else { return miinus(nasob(miinus(a), b)); }

	if (b == 'n'){ bb = 0; }
	else if (b == 'i'){ bb = 1; }
	else if (b == 'j'){ bb = 2; }
	else if (b == 'k'){ bb = 3; }
	else { return miinus(nasob(a, miinus(b))); }

	return tabulka[aa][bb];
}

char na(char a, long long na){
	if (na == 0){ return 'n'; }
	long long zb = na % 4;
	if (zb == 1){ return a; }
	char tmp = nasob(a, a);
	if (zb == 2){ return tmp; }
	tmp = nasob(tmp, a);
	if (zb == 3){ return tmp; }
	tmp = nasob(tmp, a);
	if (zb == 0){ return tmp; }
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	tabulka[0][0] = 'n';
	tabulka[0][1] = 'i';
	tabulka[0][2] = 'j';
	tabulka[0][3] = 'k';
	tabulka[1][0] = 'i';
	tabulka[1][1] = 'N';
	tabulka[1][2] = 'k';
	tabulka[1][3] = 'J';
	tabulka[2][0] = 'j';
	tabulka[2][1] = 'K';
	tabulka[2][2] = 'N';
	tabulka[2][3] = 'i';
	tabulka[3][0] = 'k';
	tabulka[3][1] = 'j';
	tabulka[3][2] = 'I';
	tabulka[3][3] = 'N';

	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		long long l, x;
		scanf("%lld %lld", &l, &x);
		scanf("%s", text);
		prefix[0] = 'n';
		for (int i = 0; i < l; i++){
			prefix[i+1] = nasob(prefix[i], text[i]);
		}
		sufix[l] = 'n';
		for (int i = l - 1; i >= 0; i--){
			sufix[i] = nasob(text[i], sufix[i + 1]);
		}
		char cl = prefix[l];

		if (na(cl, x) == 'N'){
			long long firsti = 2*l*x;
			for (int i = 0; i < min((long long)4, x); i++){
				for (int j = 1; j <= l; j++){
					if (nasob(na(cl, i), prefix[j]) == 'i'){
						firsti = i*l + j;
						break;
					}
					if (firsti != 2 * l*x){ break; }
				}
			}
			long long lastk = -1;
			for (int i = 0; i < min((long long)4, x); i++){
				for (int j = l-1; j >= 0; j--){
					if (nasob(sufix[j], na(cl, i)) == 'k'){
						lastk = l*x - i*l -l + j;
						break;
					}
				}
				if (lastk != -1){ break; }
			}
			if (firsti < lastk){
				printf("Case #%d: YES\n", t + 1);
			}
			else{
				printf("Case #%d: NO\n", t + 1);
			}
		
		}
		else{
			printf("Case #%d: NO\n", t + 1);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

