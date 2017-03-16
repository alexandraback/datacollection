#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;

char str[2001], a[2001], b[2001];
char ans[2001];
int tp = 0;

int judge(int m)
{
	for (int i = 1; i <= m; i ++)
	{
		if (a[i] < b[i]) return 2;
		if (a[i] > b[i]) return 1;
	}
	return 1;
}

void Work()
{
	scanf("%s", str + 1);
	int len = (int )strlen(str + 1);
	for (int i = 1; i <= len; i ++)
	{
		for (int j = 1; j < i; j ++)
			a[j + 1] = ans[j], b[j] = ans[j];
		a[1] = str[i];
		b[i] = str[i];
		if (judge(i) == 1)
		{
			for (int j = 1; j <= i; j ++)
				ans[j] = a[j];
		}
		else
		{
			for (int j = 1; j <= i; j ++)
				ans[j] = b[j];
		}
	}
	printf("Case #%d: ", tp);
	for (int i = 1; i <= len; i ++)
		printf("%c", ans[i]);
	printf("\n");
}

int main( )
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		++ tp;
		Work();
	}
	return 0;
} 
