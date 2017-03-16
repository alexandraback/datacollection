#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

int a[200];
double res[200];

int main()
{

	ifstream in("input.txt");
	ofstream out("output.txt");
	int T;
	in >> T;
	out << setprecision(6) << setiosflags(ios::fixed | ios::showpoint);
	for (int i = 0; i < T; i++)
	{
		//input
		int n = 0, sum = 0;
		in >> n; 
		for (int j = 0; j < n; j++)
		{
			in >> a[j];
			sum += a[j];
		}
		//alg begin
		for (int j = 0; j < n; j++)
		{
			double alpha = 2/(double)n;
			res[j] = alpha - (double)a[j]/(double)sum;
		}
		for (bool flag = true;flag;)
		{
			flag = false;
			double gamma = 0.0;
			int k = 0;
			for (int j = 0; j < n; j++)
			{
				if (res[j] < 0.0)
				{
					flag = true;
					k++;
					res[j] = 0.0;
					gamma += a[j]/(double)sum;
				}
			}
			if (!flag)
			{
				break;
			}
			double alpha = (2 - gamma)/(double)(n - k);
			for (int j = 0; j < n; j++)
			{
				if (res[j] != 0.0)
				{
					res[j] = alpha - (double)a[j]/(double)sum;
				}
			}

		}

		//alg end

		//output
		out << "Case #" << i + 1 << ":";
		for (int j = 0; j < n; j++)
		{
			res[j] *= 100.0;
			out << " " << res[j];
		}
		out << "\n";
	}

	return 0;
}