/*************************************************************************
    > File Name: a.cpp
    > Author: james47
    > Mail: 
    > Created Time: Sun May  1 00:26:37 2016
 ************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

char buf[3000];
int ct[30];
int num[30];
int T;
int main()
{
	scanf("%d", &T);
	int cas = 0;
	while(T--){
		memset(ct, 0, sizeof(ct));
		scanf("%s", buf);
		int n = strlen(buf);
		for (int i = 0; i < n; i++)
			ct[buf[i]-'A'] ++;
		num[0] = ct['Z'-'A'];
		num[2] = ct['W'-'A'];
		num[4] = ct['U'-'A'];
		num[6] = ct['X'-'A'];
		num[7] = ct['S'-'A'] - num[6];
		num[5] = ct['V'-'A'] - num[7];
		num[3] = ct['R'-'A'] - num[0] - num[4];
		num[8] = ct['H'-'A'] - num[3];
		num[1] = ct['O'-'A'] - num[0] - num[2] - num[4];
		num[9] = (ct['N'-'A'] - num[1] - num[7]) / 2;
		printf("Case #%d: ", ++cas);
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < num[i]; j++)
				printf("%d", i);
		puts("");
	}
	return 0;
}
