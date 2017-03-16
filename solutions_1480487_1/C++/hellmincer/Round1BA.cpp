#include <cmath>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <iterator>
#include <iostream>
#include <algorithm>
using namespace std;

const double EPS = 1E-12;

bool Possibru(const std::vector<double> & point, double sum, int now, double yNow)
{
	double nowScore = point[now] + sum * yNow;
	double left = 1 - yNow;
	for(int i = 0; i < static_cast<int>(point.size()); i++)
	{
		if(i != now && point[i] < nowScore)
		{
			double need = (nowScore - point[i]) / sum;
			if(need > left)
			{
				return false;
			}

			left -= need;
		}
	}

	return left > EPS;
}

double Solve(const std::vector<double> & point, double sum, int now)
{
	double left = 0;
	double right = 1;
	while(abs(left - right) > EPS)
	{
		double mid = (left + right) / 2;
		if(Possibru(point, sum, now, mid))
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	return right;
}

int main(int argc, char * argv[])
{

	freopen("in.txt", "r", stdin);
	int n;
	int testCount;
	std::cin >> testCount;
	std::vector<double> point; 
	for(int test = 1; test <= testCount; test++)
	{
		std::cin >> n;
		point.assign(n, 0);
		for(size_t i = 0; i < point.size(); i++)
		{
			std::cin >> point[i];
		}

		double sum = std::accumulate(point.begin(), point.end(), 0);

		std::cout.setf(std::cout.fixed);
		std::cout.precision(6);
		std::cout << "Case #" << test << ":" ;
		for(int i = 0; i < n; i++)
		{
			std::cout << " " << Solve(point, sum, i) * 100;
		}

		std::cout << std::endl;
	}

	return 0;
}