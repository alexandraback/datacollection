#include <iostream>
#include <ctime>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define read(a) scanf("%d", &(a))

int n, j;
int qz;
char s[10000];

void init()
{
	gets(s);
	//cout <<"["<< s << "]"<<endl;
	int len = strlen(s);
	s[len] = '+';
	s[len + 1] = 0;
}

void doit()
{
	int ans = 0;
	int len = strlen(s);
	for (int i = 1; i != len; ++ i)
		if (s[i] != s[i - 1]) ++ ans;
	printf("%d\n", ans);
}


int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int sb;
	read(sb);
	getchar();
	for (int i = 1; i <= sb; ++ i)
	{
		printf("Case #%d: ", i);
		init();
		doit();
	}
	return 0;
}

