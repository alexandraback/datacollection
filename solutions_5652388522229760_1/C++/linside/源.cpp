#include <iostream>
#include <fstream>
using namespace std;
ofstream fout("output.out");
int main()
{
	int n;
	int a[100];
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> a[i];
		if (a[i])
		{
			int x[10];
			for (int j = 0;j < 10;j++)
			{
				x[j] = 0;
			}
			int flag = 1, tmp, t = 1;
			tmp = a[i];
			do
			{
				t++;
				flag = 1;
				do
				{
					x[a[i] % 10] = 1;
					a[i] /= 10;
				} while (a[i] != 0);
				for (int j = 0;j < 10;j++)
				{
					if (x[j] == 0) flag = 0;
				}
				if (flag == 0) a[i] = tmp*t;
			} while (flag == 0);
			fout << "Case #" << i+1 << ": " << tmp*(t - 1) << endl;
		}
		else
		{
			fout << "Case #" << i+1 << ": INSOMNIA"<<endl;
		}
	}
	return 0;
}