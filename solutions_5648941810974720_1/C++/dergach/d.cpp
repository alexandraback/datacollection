#pragma	comment(linker, "/STACK:100000000")
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
using namespace std;

typedef long long ll;
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-9

char a[2005];
int cnt[300];
int res[10];
string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int order[] = {0, 2, 6, 7, 4, 1, 5, 8, 3, 9};
string letter = "ZWXSUOVGHI";

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		memset(cnt, 0, sizeof(cnt));
		scanf("%s", a);
		for(int i = 0; a[i]; i++)
			cnt[a[i]]++;
		memset(res, 0, sizeof(res));

		for(int j = 0; j < 10; j++)
		{
			res[order[j]] = cnt[letter[j]];
			for(int i = 0; i < digits[order[j]].size(); i++)
				cnt[digits[order[j]][i]] -= res[order[j]];
		}

		printf("Case #%d: ", t);
		for(int j = 0; j < 10; j++)
			while(res[j]--)
				printf("%d", j);
		puts("");
	}
	return 0;
}
