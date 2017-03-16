// RecycledNumbers.cpp : 定义控制台应用程序的入口点。
//

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <list>
#include <math.h>
using namespace std;


int val[200];
int N;

bool bValid(double p, int idx, int sum_val)
{
	double sort_val[200];

	for (int i=0; i<N; i++)
	{
		sort_val[i] = val[i];
	}
	sort_val[idx] = -100;

	sort(sort_val, sort_val+N,greater<double>());

	double curVal = p * sum_val + val[idx];

	double r = sum_val * (1-p);

	bool bFlag = true;
	for (int i=0; i<N; i++)
	{
		if (sort_val[i] >= 0 )
		{
			if (sort_val[i] < curVal)
			{
				if (sort_val[i]+r>=curVal)
				{
					r -= (curVal - sort_val[i]);
				}
				else
				{
					bFlag = false;
				}
			}

		}
	}
	return bFlag;
}

void run()
{

	cin >> N;

	for (int i=0; i<N; i++)
	{
		cin >> val[i];
	}

	int sumVal = 0;
	for (int i=0; i<N; i++)
	{
		sumVal+= val[i];
	}

	int i;
	for ( i=0; i<N; i++)
	{
		double startVal = 0.0;
		double endVal = 1.0;

		double minVal;
		while (true)
		{
			minVal = (endVal + startVal) / 2;
			if (bValid(minVal, i, sumVal))
			{
				//minVal = (minVal+endVal)/2;
				startVal = minVal;
			}
			else
			{
				//minVal = (startVal+minVal)/2;
				endVal = minVal;
			}
			if (fabs(endVal-startVal) < 1e-7) 
				break;

		}
		if (minVal<1e-13)
		{
			minVal = 0;
		}
		printf("%f ", minVal*100);

	}

	cout << "\n";
}

int main()
{
	//freopen("small.in", "r", stdin);
	//	freopen("small.out", "w", stdout);

		freopen("large.in", "r", stdin);
		freopen("large.out", "w", stdout);
	int T;
	cin >> T;

	for (int i=1; i<=T; i++)
	{
		cout << "Case #" << i << ": ";
		run();
	}
	return 0;
}
