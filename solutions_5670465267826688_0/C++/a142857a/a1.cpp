#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

const int MAXN = 400005;

int a[MAXN];
int n;

int opr(int x, int y)
{
	int t = 1;
	if(x < 0) t = -t, x = -x;
	if(y < 0) t = -t, y = -y;
	int z;
	if(x == 1) z = y;
	else if(y == 1) z = x;
	else
	{
		if(x == y) z = -1;
		else
		{
			if(x > y) t = -t, swap(x, y);
			if(x == 2 && y == 3) z = 4;
			if(x == 2 && y == 4) z = -3;
			if(x == 3 && y == 4) z = 2;
		}
	}
	return t * z;
}

int main()
{
//	freopen("a.in", "r", stdin);
//	freopen("a.out", "w", stdout);
	int T = 0;
	long long m;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d%I64d", &n, &m);
	//	scanf("%d%d", &n, &m);
	//	getchar();
		for(int i = 1; i <= n; i++)
		{
			char tmp;
			scanf("%c", &tmp);
			while(tmp < 'i') scanf("%c", &tmp);
			if(tmp == 'i') a[i] = 2;
			if(tmp == 'j') a[i] = 3;
			if(tmp == 'k') a[i] = 4;
		}
	//	cout<<n<<' '<<m<<endl;
	
		bool ok = 1;
		int s = 1;
		for(int i = 1; i <= n; i++)
			s = opr(s, a[i]);
		if((s == -1 && m % 2 != 1) || ((s >= 2 || s <= -2) && m % 4 != 2) || s == 1)
			ok = 0;
		if(ok)
		{
			if(m > 40)
			{
				m %= 8;
				m += 40;
			}
			while(m > 30) m -= 8;
			for(int i = 2; i <= m; i++)
			{
				for(int j = 1; j <= n; j++)
					a[(i - 1) * n + j] = a[(i - 2) * n + j];
			}
			int N = n * m;
			int now = 1;
			int f = N + 1, b = 0;
			for(int i = 1; i <= N; i++)
			{
				now = opr(now, a[i]);
				if(now == 2)
				{
					f = i;
					break;
				}
			}
			now = 1;
			for(int i = N; i >= 1; i--)
			{
				now = opr(a[i], now);
				if(now == 4)
				{
					b = i;
					break;
				}
			}
		//	cout<<f<<' '<<b<<endl;
			if(f < b)
				ok = 1;
			else ok = 0;
		}
		if(ok)
			printf("Case #%d: YES\n", t);
		else
			printf("Case #%d: NO\n", t);
	}
	
	return 0;
}

