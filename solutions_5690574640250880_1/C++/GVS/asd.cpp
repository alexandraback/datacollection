#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int i , j , n, m , k , t ;

int check(vector< vector<int> > a)
{
	int  i , j , k , p , n , m , x , y;
	int d = 1;
	n = a.size();
	m = a[0].size();
	while (d)
	{
		d = 0;
		for (i = 0; i < a.size(); i++)
			for (j = 0; j < a[i].size(); j++)
				if (a[i][j] == 2)
				{
					int isgood = 1;
					int changed = 0;
					for (k = -1; k <= 1; k++)
						for (p = -1; p <= 1; p++)
						{
							x = i + k;
							y = j + p;

							if (x >= 0 && x < n && y >= 0 && y < m)
							{
								if (a[x][y] == 1)
									isgood = 0;
								if (a[x][y] == 0)
									changed = 1;
							}
						}

					 if (isgood && changed)
					 {
						 d = 1;
						 for (k = -1; k <= 1; k++)
							for (p = -1; p <= 1; p++)
							{
								x = i + k;
								y = j + p;

								if (x >= 0 && x < n && y >= 0 && y < m)
									a[x][y] = 2;
							}
					 }
				}

	}

	for (i = 0; i < n ; i++)
		for (j = 0; j < m; j++)
			if (a[i][j] == 0)
				return 0;

	return 1;

}


int main()
{
	freopen("c:/input.txt" , "r" ,stdin);
	freopen("c:/output.txt" , "w" , stdout);

	cin>>t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n>>m>>k;
		int swapped = 0;
		if (n > m)
		{
			swap(n,  m);
			swapped = 1;
		}

		vector< vector<int> > ans(n);
		for (i = 0; i < n; i++)
			ans[i].resize(m);

		int ansfound = 0;

		if (k == n * m - 1)
		{
			ansfound = 1;
			for (i = 0; i <n ; i++)
				for (j = 0; j < m; j++)
					ans[i][j] = 1;
			ans[0][0] = 2;
		}  else
		if (n == 1)
		{
			ansfound = 1;
			for (i = m - 1; i >= m - k; i--)
				ans[0][i] =  1; 
			ans[0][0] = 2;

		} else
		if (n == 2)
		{
			if (k % 2 == 1 || k == n * m  - 2)
				ansfound = 0;
			else
			{
				ansfound = 1;
				for (i = m - 1; i >= m - k/2; i--)
					ans[0][i] = ans[1][i] = 1;

				ans[0][0] = 2;
			}
		} else
		{
			int rem = n * m - k;
			
			int h , w;
			for (h = 2; h <= n && !ansfound; h++)
			{
				for (w = h; w <= m && !ansfound; w++)
				{
					if (h * w - h >= rem)
						break;
					if (h * w >= rem)
					{
						if (h * w == rem)
						{
							ansfound = 1;
							for (i = 0; i < n; i++)
								for (j = 0; j < m; j++)
								{
									if (i >= h || j >= w)
										ans[i][j] = 1;
								}
							ans[0][0] = 2;
						} else
						{
							int shouldadd = h * w - rem;
							if (shouldadd != w - 1 && h > 2)
							{
								ansfound = 1;
								for (i = 0; i < n; i++)
									for (j = 0; j < m; j++)
									{
										if (i >= h || j >= w)
											ans[i][j] = 1;
									}

								for (j = w - 1; j >= w - shouldadd; j--)
									ans[h-1][j] = 1;

								ans[0][0] = 2;
							} else
							if (shouldadd == w-1 && h > 3)
							{
								ansfound = 1;
								shouldadd--;
								for (i = 0; i < n; i++)
									for (j = 0; j < m; j++)
									{
										if (i >= h || j >= w)
											ans[i][j] = 1;
									}

								for (j = w - 1; j >= w - shouldadd; j--)
									ans[h-1][j] = 1;

								ans[h-2][w-1] = 1;

								ans[0][0] = 2;
							}

						}

						break;
					}
				}
			}
		}

		cout<<"Case #"<<tt<<":\n";

		if (ansfound == 0)
		{
			cout<<"Impossible\n";
		} else
		{
			
			//if (!check(ans))
			//{
			//	while (1)
			//	cout<<"wrong answer!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n";
			//}

			if (!swapped)
			{
				for (i = 0; i < n; i++)
				{
					for (j = 0; j < m; j++)
						if (ans[i][j] == 0)
							cout<<'.';
						else
						if (ans[i][j] == 1)
							cout<<'*';
						else cout<<'c';

					cout<<endl;
				}
			} else
			{
				for (j = 0; j < m; j++)
				{
					for (i = 0; i < n; i++)
				
						if (ans[i][j] == 0)
							cout<<'.';
						else
						if (ans[i][j] == 1)
							cout<<'*';
						else cout<<'c';

					cout<<endl;
				}
			}
		}

	}

	return 0;
}
