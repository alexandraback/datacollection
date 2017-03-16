#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <cstring>
using namespace std;

typedef long long int64;

int n , m;
int64 a[110] , b[110];
int A[110] , B[110];
int64 best;

void Go(int i , int j , int64 res)
{
    if (i > n || j > m)
    {
        best = max(best , res);
        return ;
    }
    if (A[i] == B[j])
    {
        if (a[i] > b[j])
        {
            int64 tmp = a[i];
            a[i] -= b[j];
            Go(i , j + 1 , res + b[j]);
            a[i] = tmp;
        }
        else if (a[i] < b[j])
        {
            int64 tmp = b[j];
            b[j] -= a[i];
            Go(i+1, j, res+a[i]);
            b[j] = tmp;
        }
        else
            Go(i+1, j+1 , res+a[i]);
    }
    else
    {
        Go(i+1, j , res);
        Go(i, j+1 , res);
    }


}

void Solve(){
	scanf("%d %d", &n, &m);
    for (int i = 1 ; i <= n ; i ++) scanf("%lld %d", &a[i], &A[i]);
	for (int i = 1 ; i <= m ; i ++) scanf("%lld %d", &b[i], &B[i]);
    best = 0;
    Go(1 , 1 , 0);
	printf(" %lld\n", best);
}

int main()
{
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    int ctest;
    cin >> ctest;
    for (int test = 1 ; test <= ctest ; test ++)
    {
		printf("Case #%d:", test);
		Solve();
    }
}
