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

int a[201][201];
int b[201], num[100001];

int c[201][201];
int n, tp = 0;
bool mark[201];
void Work()
{
	scanf("%d", &n);
	for (int i = 1; i <= 5000; i ++) num[i] = 0;
	for (int i = 1; i <= 2 * n - 1; i ++)
		for (int j = 1; j <= n; j ++)
			scanf("%d", &a[i][j]), num[a[i][j]] ++;
	int N = 0;
	for (int i = 1; i <= 5000; i ++)
		if (num[i] & 1) b[++ N] = i;
	sort(b + 1, b + 1 + N); 
	++ tp;
	printf("Case #%d:", tp);
	for (int i = 1; i <= N; i ++)
		printf(" %d", b[i]);
	printf("\n");

}
				

int main( )
{
	int T;
	scanf("%d", &T);
	while (T --)
	{
		Work();
	}
	return 0;
}
