#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
#include<algorithm>
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
typedef long long LL;
using namespace std;


void solve()
{
    int arr[3000];
    memset(arr, 0, sizeof(int) * 3000);

    int n, tmp;

    scanf("%d", &n);

    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &tmp);
            arr[tmp]++;
        }
    }
    for (int i = 0; i < 3000; i++)
        if (arr[i] % 2)
            printf(" %d", i);
    printf("\n");

}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("data.txt","r",stdin);
    freopen("out.txt","w",stdout);
#endif

    int cases;
    scanf("%d\n", &cases);

    for(int i = 1; i <= cases; i++)
    {
        printf("Case #%d:", i);
        solve();        
    }
	return 0;

}
