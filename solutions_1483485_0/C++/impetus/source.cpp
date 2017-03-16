#pragma comment (linker, "/STACK:256000000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <complex>
#include <bitset>
#include <sstream>
#include <set>
#include <map>

using namespace std;
template <class T> T sqr(T a) { return a * a; }

char s[140];
string code = "yhesocvxduiglbkrztnwjpfmaq";

/*
ejp mysljylc kd kxveddknmc re jsicpdrysi
our language is impossible to understand

rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
there are twenty six factorial possibilities

de kr kd eoya kw aej tysr re ujdr lkgc jv
so it is okay if you want to just give up*/

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int testNum;
	scanf("%d", &testNum);
	gets(s);
	for (int testCount = 0; testCount < testNum; testCount++)
	{
		gets(s);
		printf("Case #%d: ", testCount + 1);
		int len = strlen(s);
		for (int i = 0; i < len; i++)
			printf("%c", isalpha(s[i]) ? code[s[i] - 'a'] : s[i]);
		printf("\n");
	}
	return 0;
}