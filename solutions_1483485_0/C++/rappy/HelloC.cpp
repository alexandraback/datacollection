#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int main()
{
	const char* gWord[3] = {
			"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
			"de kr kd eoya kw aej tysr re ujdr lkgc jv",
	};
	const char* eWord[3] = {
			"our language is impossible to understand",
			"there are twenty six factorial possibilities",
			"so it is okay if you want to just give up",
	};
	char table[256];
	memset(table, 0, sizeof(table));
	for(int i = 0; i < 3; ++i){
		int len = strlen(gWord[i]);
		for(int j = 0; j < len; ++j){
			char g = gWord[i][j];
			char e = eWord[i][j];
			if(table[g] && table[g] != e){
				cout << "error" << endl;
			}
			table[g] = e;
		}
	}
	table['q'] = 'z';
	table['z'] = 'q';

//	freopen("input.in", "r", stdin);
//	freopen("output.out", "w", stdout);
	int T;
	scanf("%d", &T);
	char str[1000];
	gets(str);
	for(int cas = 1; cas <= T; ++cas){
		gets(str);
		for(int i = 0, len = strlen(str); i < len; ++i){
			str[i] = table[str[i]];
		}
		cout << "Case #" << cas << ": " << str << endl;
	}

	return 0;
}
