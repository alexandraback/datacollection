#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int cmp(const void* x, const void* y)
{
	if (*((int*)x) > *((int*)y))
		return 1;
	return -1;
}
int main()
{
	ifstream inf("1.in", ios::in);
	ofstream outf("1.out", ios::out);

	int t;
	inf >> t;
	int i, j, k;
	int n;
	int s[210];
	int tmp[210];
	double p[210];
	double sum[210] = {0};
	for (i = 1; i <= t;i++)
	{
		inf >> n;
		int Min = 999;
		sum[0] = 0;
		for (j = 0;j < n;j++)
		{
			inf >> s[j];
			tmp[j] = s[j];
		}
		qsort(tmp, n, sizeof(int), cmp);
		tmp[n] = 9999;

		for (j = 0;j < n;j++)
			sum[j] = j > 0 ? sum[j-1] + tmp[j] : tmp[0];

		for (k = 0;k < n;k++)
		{
			if (2 * sum[n-1] - (sum[n-1] - sum[k]) >= (k+1)*tmp[k] && 2 * sum[n-1] - (sum[n-1] - sum[k]) <= (k+1)*tmp[k+1])
				break;
		}


		outf << "Case #" << i <<":";
		for (j = 0;j < n;j++)
		{
			if (s[j] <= (2 * sum[n-1]- (sum[n-1] - sum[k])) / (k+1))
				outf <<" "<< setprecision(6) << fixed << 100*((2 * sum[n-1]- (sum[n-1] - sum[k])) / (k+1) - s[j]) / sum[n-1];
			else
				outf <<" "<< setprecision(6) << fixed << 0.0;
		}
		outf <<  endl;
	}
	return 0;
}