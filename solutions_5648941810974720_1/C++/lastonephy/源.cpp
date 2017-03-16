#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define LL __int64
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define zero(x) ((x > +eps) - (x < -eps))
#define MAX 2010
using namespace std;

int num[26];
int no[10];
char str[MAX];
char name[10][15] =  {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char ch[20] = "ZOWHUFXSGE";

int main()
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int ii = 1; ii <= t; ii ++)
	{
		scanf("%s",str);
		mem(num,0);
		mem(no,0);
		for(int i = 0; str[i]; i ++)
		{
			num[str[i] - 'A'] ++;
		}
		for(int i = 0; i < 10; i += 2)
		{
			int x = num[ch[i] - 'A'];
			no[i] += x;
			for(int j = 0; name[i][j]; j ++)
			{
				int y = name[i][j] - 'A';
				num[y] -= x;
			}
		}
		for(int i = 1; i < 10; i += 2)
		{
			int x = num[ch[i] - 'A'];
			no[i] += x;
			for(int j = 0; name[i][j]; j ++)
			{
				int y = name[i][j] - 'A';
				num[y] -= x;
			}
		}
		printf("Case #%d: ",ii);
		for(int i = 0; i <= 9; i ++)
		{
			for(int j = 0; j < no[i]; j ++)
			{
				printf("%d",i);
			}
		}
		printf("\n");
	}
	return 0;
}
