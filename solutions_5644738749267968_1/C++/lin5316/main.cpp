//#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
using namespace std;

ifstream cin("input.txt");
ofstream cout("output.txt");

int main(){
	int T, n;
	double a[1000], b[1000];
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		double tmp;
		for (int i = n - 1; i > 0; i--)
		{
			tmp = -1;
			for (int j = 0; j < i; j++)
			{
				if (a[j] > a[j + 1])
				{
					tmp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = tmp;
				}
			}
			if (tmp < 0)
				break;
		}
		for (int i = n - 1; i > 0; i--)
		{
			tmp = -1;
			for (int j = 0; j < i; j++)
			{
				if (b[j] > b[j + 1])
				{
					tmp = b[j];
					b[j] = b[j + 1];
					b[j + 1] = tmp;
				}
			}
			if (tmp < 0)
				break;
		}
		int i, j = 0, win = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] > b[j])
			{
				j++;
				win++;
			}
		}
		j = 0;
		int win1 = 0;
		for (i = 0; i < n; i++)
		{
			if (a[i] < b[j])
			{
				j++;
				if (j == n)
					break;
			}
			else
			{
				while (j < n && a[i] > b[j])
				{
					j++;
					win1++;
				}
				if (j == n)
					break;
				j++;
				if (j == n)
					break;
			}
		}
		cout << "Case #" << t << ": " << win << " " << win1 << endl;
	}
	return 0;
}