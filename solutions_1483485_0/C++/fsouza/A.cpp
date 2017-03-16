#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

string samples[5][2] = 
{
	{"y qee", "a zoo"},
	{"ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand"},
	{"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities"},
	{"de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up"},
	{"z", "q"},
};
int nsample = 5;

int main(int argc, char ** argv)
{
	map <char, char> m;

	for (int s = 0; s < nsample; s++)
		for (int i = 0; i < samples[s][0].size(); i++)
			m[samples[s][0][i]] = samples[s][1][i];

	int ntest;

	scanf("%d", &ntest);
	while (getchar() != '\n');

	for (int test = 0; test < ntest; test++) {
		int c;
		printf("Case #%d: ", test+1);
		while ((c = getchar()) != '\n')
			printf("%c", m[c]);
		printf("\n");
	}

	return 0;
}
