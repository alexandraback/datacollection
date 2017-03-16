#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
#define MM(a , x) memset(a , x , sizeof(a))
#define sqr(x) ((x) * (x))
#define abs(x) ((x > 0) ? (x) : -(x))
#define REP(i , n) for ((i) = 0; (i) < (n); ++(i))
#define FOR(i , a , b) for ((i) = (a); (i) <= (b); ++(i))
#define FORD(i , a , b) for ((i) = (a); (i) >= (b); --(i))
typedef long long LL;

const int maxn = 108;

int n , m , testcase , T;
LL f[maxn][maxn] , sum_a[maxn][maxn] , sum_b[maxn][maxn];
int type_a[maxn] , type_b[maxn];

void init()
{
	cin >> n >> m;
	int i , j , k , type;
	LL num;
	MM(sum_a , 0); MM(sum_b , 0);
	FOR (i , 1 , n)
	{
		cin >> num >> type;
		type_a[i] = type;
		FOR (j , 1 , 100)
		{
			if (j == type) sum_a[i][j] = sum_a[i - 1][j] + num;
			else sum_a[i][j] = sum_a[i - 1][j];
		}
	}
	FOR (i , 1 , m)
	{
		cin >> num >> type;
		type_b[i] = type;
		FOR (j , 1 , 100)
		{
			if (j == type) sum_b[i][j] = sum_b[i - 1][j] + num;
			else sum_b[i][j] = sum_b[i - 1][j];
		}
	}
}

void work()
{
	int i , j , k , i1 , j1;
	MM(f , 0);
	FOR (i , 1 , n)
	{
		FOR (j , 1 , m)
		{
			FOR (i1 , 0 , i)
			{
				FOR (j1 , 0 , j)
				{
					FOR (k , 1 , 100)
					{
						LL tp = min(sum_a[i][k] - sum_a[i1][k] , sum_b[j][k] - sum_b[j1][k]);
						f[i][j] = max(f[i][j] , f[i1][j1] + tp);
					}
				}
			}
		}
	}
	/*
	FOR (i , 1 , n)
	{
		FOR (j , 1 , m)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	*/
	cout << "Case #" << T << ": " << f[n][m] << endl;
}

int main()
{
	freopen("c.in" , "r" , stdin);
	freopen("c.out" , "w" , stdout);
	cin >> testcase;
	FOR (T , 1 , testcase)
	{
		init();
		work();
	}
	return 0;
}
