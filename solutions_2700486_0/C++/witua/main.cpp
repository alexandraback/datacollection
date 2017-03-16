#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility> 
using namespace std;
 
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))
 
#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UInt;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1010000000;
const int MAX = 1<<13;
const long long INFF = 100000000000000000LL;

#define BASE 1000000000

int T, n, x, y;
double P[MAX];
double C[MAX][MAX];

int main()
{
	FOR (i,0,MAX)
		C[i][0] = 1.0;
	FOR (i,1,MAX)
		FOR (j,1,i+1)
			C[i][j] = C[i-1][j] + C[i-1][j-1];
	P[0] = 1.0;
	FOR (i,1,MAX)
		P[i] = P[i-1] / 2.0;

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);



	scanf("%d", &T);
	FOR (test,0,T)
	{
		scanf("%d %d %d", &n, &x, &y);
		int xx = x, yy = y, p, q = 1;
		if (x < 0)
		{
			while (yy > 0)
			{
				yy --;
				xx --;
				q ++;
			}
		}
		else
		{
			while (yy > 0)
			{
				yy --;
				xx ++;
				q ++;
			}
		}
		p = abs(xx) / 2;
		int sum = 0, cur = 2*p - 1;
		FOR (i,0,2*p - 1)
		{
			sum += cur;
			cur --;
		}
		int c = 2 * (2*p + 1) - 1;
		int r = n - sum;
	//	cout << sum << ' ' << r << ' ' << ' ' << c << ' ' << q << endl;
		double res = 0.0;
		if (r < 0)
			res = 0.0;
		else
		{
			if (x == 0)
			{
				if (r >= c)
				{
					res = 1.0;
				}
				else
				if (r < c)
				{
					res = 0.0;
				}
				else
				{
					res = 0.0;
					FOR (j,c/2,r+1)
					{
						double w = P[j] * C[j-1][c/2-1];
						//cout << j << '-' << i << ' ' << P[j] << ' ' << C[j][i] << endl;
						res += w;
					}
				}
			}
			else
			{
				if (r < q)
					res = 0.0;
				else
				{
					if (r >= c)
						res = 1.0;
					else
					{
						res = 0.0;
						FOR (i,q,c/2+1)
						{
							//cout << q << endl;
							int d = r - i;
							if (d < 0)
								break;
							double f;
							if (i == c/2)
							{
								if (d > c/2+1)
									f = 0;
								else
								if (d == c/2)
								{
									f = 0.0;
									FOR (j,i,r)
									{
										double w = P[j] * C[j-1][i-1];
										//cout << j << '-' << i << ' ' << P[j] << ' ' << C[j][i] << endl;
										f += w;
									}
									FOR (j,i,r)
									{
										double w = P[j] * C[j-1][i-1];
										//cout << j << '-' << i << ' ' << P[j] << ' ' << C[j][i] << endl;
										f += w;
									}
								}
								else
								{
									f = 0.0;
									FOR (j,i,r+1)
									{
										double w = P[j] * C[j-1][i-1];
										//cout << j << '-' << i << ' ' << P[j] << ' ' << C[j][i] << endl;
										f += w;
									}
									
								}
							}						
							else
							{
								f = P[i + d] * C[r][i];
								if (d > c/2)
									f = 0;
							}
							//cout << f << endl;
							res += f;
						}
					}
				}
			}
		}
		printf("Case #%d: %0.9f\n", test+1, res);
	}
	


		
	return 0;
}