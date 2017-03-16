#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include <string>
#define MAXN 20

using namespace std;

long long absLL (long long a)
{
	if (a < 0LL) return -1LL * a;
	else return a;
}

int main ()
{
	int T, iT;
	scanf("%d",&T);
	static char a[MAXN];
	static char b[MAXN];
	static char f[100];
	static char fd[100];
	for (iT = 0; iT < T; iT++)
	{
		scanf("\n%s %s",a,b);
		int N = strlen(a);
		int pos = 0;
		long long A = 0LL;
		long long B = 0LL;
		long long resA = 0LL;
		long long resB = 1000000000000000000LL;
		while (1)
		{
			long long nowA;
			long long nowB;
			char isOK;

			//A < B
			isOK = 1;
			nowA = A; nowB = B;
			if ((a[pos] == '?') && (b[pos] == '?'))
			{
				nowA = nowA * 10LL;
				nowB = nowB * 10LL + 1LL;
			}
			else if (a[pos] == '?')
			{
				int d = (int)(b[pos] - '0');
				if (d > 0)
				{
					nowA = nowA * 10LL + (long long)(d-1);
					nowB = nowB * 10LL + (long long)(d);
				}
				else isOK = 0;
			}
			else if (b[pos] == '?')
			{
				int d = (int)(a[pos] - '0');
				if (d < 9)
				{
					nowA = nowA * 10LL + (long long)(d);
					nowB = nowB * 10LL + (long long)(d+1);
				}
				else isOK = 0;
			}
			else
			{
				int da = (int)(a[pos] - '0');
				int db = (int)(b[pos] - '0');
				if (da < db)
				{
					nowA = nowA * 10LL + (long long)(da);
					nowB = nowB * 10LL + (long long)(db);
				}
				else isOK = 0;
			}
			if (isOK)
			{
				for (int j = pos+1; j < N; j++)
				{
					if (a[j] == '?') nowA = nowA * 10LL + 9LL;
					else nowA = nowA * 10LL + (long long)(a[j] - '0');
					if (b[j] == '?') nowB = nowB * 10LL;
					else nowB = nowB * 10LL + (long long)(b[j] - '0');
				}
				if (absLL(nowA - nowB) < absLL(resA - resB))
				{
					resA = nowA;
					resB = nowB;
				}
				else if (absLL(nowA - nowB) == absLL(resA - resB))
				{
					if (nowA < resA)
					{
						resA = nowA;
						resB = nowB;
					}
					else if (nowA == resA)
					{
						if (nowB < resB)
						{
							resA = nowA;
							resB = nowB;
						}
					}
				}
			}

			//A > B
			isOK = 1;
			nowA = A; nowB = B;
			if ((a[pos] == '?') && (b[pos] == '?'))
			{
				nowA = nowA * 10LL + 1LL;
				nowB = nowB * 10LL;
			}
			else if (a[pos] == '?')
			{
				int d = (int)(b[pos] - '0');
				if (d < 9)
				{
					nowA = nowA * 10LL + (long long)(d+1);
					nowB = nowB * 10LL + (long long)(d);
				}
				else isOK = 0;
			}
			else if (b[pos] == '?')
			{
				int d = (int)(a[pos] - '0');
				if (d > 0)
				{
					nowA = nowA * 10LL + (long long)(d);
					nowB = nowB * 10LL + (long long)(d-1);
				}
				else isOK = 0;
			}
			else
			{
				int da = (int)(a[pos] - '0');
				int db = (int)(b[pos] - '0');
				if (da > db)
				{
					nowA = nowA * 10LL + (long long)(da);
					nowB = nowB * 10LL + (long long)(db);
				}
				else isOK = 0;
			}
			if (isOK)
			{
				for (int j = pos+1; j < N; j++)
				{
					if (a[j] == '?') nowA = nowA * 10LL;
					else nowA = nowA * 10LL + (long long)(a[j] - '0');
					if (b[j] == '?') nowB = nowB * 10LL + 9LL;
					else nowB = nowB * 10LL + (long long)(b[j] - '0');
				}
				if (absLL(nowA - nowB) < absLL(resA - resB))
				{
					resA = nowA;
					resB = nowB;
				}
				else if (absLL(nowA - nowB) == absLL(resA - resB))
				{
					if (nowA < resA)
					{
						resA = nowA;
						resB = nowB;
					}
					else if (nowA == resA)
					{
						if (nowB < resB)
						{
							resA = nowA;
							resB = nowB;
						}
					}
				}
			}

			if (pos == N)
			{
				if (absLL(A - B) < absLL(resA - resB))
				{
					resA = A;
					resB = B;
				}
				else if (absLL(A - B) == absLL(resA - resB))
				{
					if (A < resA)
					{
						resA = A;
						resB = B;
					}
					else if (A == resA)
					{
						if (B < resB)
						{
							resA = A;
							resB = B;
						}
					}
				}
			}

			if ((a[pos] == '?') && (b[pos] == '?'))
			{
				A = A * 10LL;
				B = B * 10LL;
			}
			else if (a[pos] == '?')
			{
				int d = (int)(b[pos] - '0');
				A = A * 10LL + (long long)(d);
				B = B * 10LL + (long long)(d);
			}
			else if (b[pos] == '?')
			{
				int d = (int)(a[pos] - '0');
				A = A * 10LL + (long long)(d);
				B = B * 10LL + (long long)(d);
			}
			else
			{
				int da = (int)(a[pos] - '0');
				int db = (int)(b[pos] - '0');
				if (da == db)
				{
					A = A * 10LL + (long long)(da);
					B = B * 10LL + (long long)(db);
				}
				else break;
			}

			pos++;
		}
		memset(f,0,sizeof(f));
		memset(fd,0,sizeof(fd));
		itoa(N, fd, 10);
		strcat(f, "Case #%d: %0");
		strcat(f, fd);
		strcat(f, "lli %0");
		strcat(f, fd);
		strcat(f, "lli\n");
		printf(f,iT+1,resA,resB);
	}
	return 0;
}
