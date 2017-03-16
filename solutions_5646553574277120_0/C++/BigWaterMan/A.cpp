#pragma error(disable:4996)
#include<iostream>
#include<iomanip>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;
typedef long long LL;
const LL MAXSIZE = 10000000;
int a[1000000];
LL L;


int main()
{
	errno_t err1;
	errno_t err2;
	FILE *fin, *fout;
	err1 = freopen_s(&fin, "C-small-attempt0.in", "r", stdin);
	//err1 = freopen_s(&fin, "A-small-attempt0 (1).in", "r", stdin);
	err2 = freopen_s(&fout, "out.txt", "w", stdout);
	LL T;
	cin >> T;
	memset(a, 0, sizeof(a));

	for (LL z = 1; z <= T; ++z)
	{
		int n, m, k;
		cout << "Case #" << z << ": ";
		int c, d, v;
		cin >> c >> d >> v;
		/*		if (k == 1)
					cout << m*n << endl;
					else if (m == k)
					cout << k << endl;
					else if (m == k + 1)
					cout << k + 1 << endl;*/
		int a[1000];
		memset(a, 0, sizeof(a));
		a[0] = 1;
		for (int i = 0; i < d; ++i)
		{
			int x;
			cin >> x;
			for (int j = 1000 - x; j >= 0; --j)
			{
				if (a[j] == 1)
					a[j + x] = 1;
			}
		}
		bool flag = true;
		int count = 0;
		while (flag == true)
		{
			flag = false;
			for (int i = 0; i <= v; ++i)
			{
				if (a[i] == 0)
				{
					flag = true;
					for (int j = 1000 - i; j >= 0; --j)
					{
						if (a[j] == 1)
							a[j + i] = 1;
					}
					break;
				}
			}
			if (flag == true)
			{
				++count;
				continue;
			}
				
		}
		cout << count << endl;



	}

}
