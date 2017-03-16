#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int tst, t , i , j , k , n,  m , h;
int a[101][101] , b[101][101];

int main()
{
	freopen("B-large.in" , "r" , stdin);
	freopen("output.txt" , "w" , stdout);
	cin>>tst;
	for (int t = 1; t <= tst; t++)
	{
		cout<<"Case #"<<t<<": ";
		cin>>n>>m;
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
			{
				cin>>a[i][j];
				b[i][j] = a[i][j];
			}
		

		string ans = "YES";
		for (h = 1; h < 100; h++)
		{
			for (i = 0; i < n; i++)
			{
				if (a[i][0] == h)
				{
					int d = 0;
					for (j = 0; j < m; j++)
						if (a[i][j] != h)
						{
							d = 1;
						}

					if (!d)
					{
						for (j = 0; j < m; j++)
							b[i][j] = h + 1;
					}
				}

			}

			for (j = 0; j < m; j++)
			{
				if (a[0][j] == h)
				{
					int d = 0;
					for (i = 0; i < n; i++)
						if (a[i][j] != h)
						{
							d = 1;
						}

					if (!d)
					{
						for (i = 0; i < n; i++)
							b[i][j] = h + 1;
					} 
				}
			}

			for (i = 0; i < n; i++)
			{
				for (j = 0; j < m; j++)
				{
					if (b[i][j] <= h)
						ans = "NO";

					a[i][j] = b[i][j];
				}
			}

		}

		cout<<ans<<endl;
	}
	return 0;
}