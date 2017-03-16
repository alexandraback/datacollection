// TestA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <map>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	map<char,char> maps;
	{
		freopen("dataIn.txt", "r", stdin);
		char A[110], B[110];

		for(int i = 0; i < 3; i ++) {
			gets(A);
			gets(B);

			for(int j = 0; A[j]; j ++) {
				if(A[j]==' ')	continue;
				maps[A[j]] = B[j];
			}
		}
		maps['z'] = 'q';
		maps['q'] = 'z';
		maps[' '] = ' ';
		for(map<char,char>::iterator iter = maps.begin(); iter != maps.end(); iter ++) {
			printf("%c: %c\n", iter->first, iter->second);
		}
	}

	compute : {
		freopen("A-small-attempt0.in", "r", stdin);
		freopen("data.out", "w", stdout);
		int n;
		char str[110];
		scanf("%d\n", &n);
		for(int i = 1; i <= n; i ++) {
			gets(str);
			for(int j = 0; str[j]; j ++) {
				str[j] = maps[str[j]];
			}
			printf("Case #%d: %s\n", i, str);
		}
	}
	return 0;
}

