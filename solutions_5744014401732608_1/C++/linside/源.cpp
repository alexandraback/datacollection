#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("result.txt");
int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		long long int r,m;
		cin >> r >> m;
		fout << "Case #" << i << ": ";
		if (pow(2, r-2) < m)
		{
			fout << "IMPOSSIBLE" << endl;
		}
		else
		{
			fout << "POSSIBLE" << endl;
			int a[51], j = r-1;
			do
			{
				if (m - pow(2, j - 2) >= 0)
				{
					m -= pow(2, j - 2);
					a[j] = 1;
				}
				else
				{
					a[j] = 0;
				}
				j--;
			} while (j > 0);
			for (int j = 1;j <= r ;j++)
			{
				for (int k = 1;k <= j;k++)
				{
					fout << "0";
				}
				for (int k = j+1;k <= r-1;k++)
				{
					fout << "1";
				}
				if(j!=r)fout << a[j]<<endl;
			}
			fout << endl;

		}
	}
	system("pause");
	return 0;
}