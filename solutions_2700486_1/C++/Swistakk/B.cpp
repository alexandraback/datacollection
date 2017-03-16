#include <iostream>
#include <cstdio>
#include <cmath>
#define N 5005
#define uint long long int
#define ld long double
using namespace std;
ld newt[N][N];
int main()
{
	for (int i = 0; i <= N - 2; i++)
	{
		newt[i][0] = newt[0][i] = 1;
	}
	for (int i = 1; i <= N - 2; i++)
	{
		for (int j = 1; j <= N - 2; j++)
		{
			newt[i][j] = newt[i][j - 1] + newt[i - 1][j];
		}
	}
	int t;
	cin>>t;
	for (int z = 1; z <= t; z++)
	{
		cout<<"Case #"<<z<<": ";
		uint n, x, y;
		cin>>n>>x>>y;
		uint k = (abs(x) + y) / 2;
		uint akt = (2 * k + 1) * (k + 1);
		uint pop = (2 * k - 1) * k;
		if (n < pop + y + 1)
		{
			cout<<"0.0"<<endl;
			continue;
		}
		if (n >= akt)
		{
			cout<<"1.0"<<endl;
			continue;
		}
		if (x == 0)
		{
			cout<<"0.0"<<endl;
			continue;
		}
		uint r = n - pop;
		int need = y + 1;
		if(r >= need + 2 * k)
		{
			cout<<"1.0"<<endl;
			continue;
		}
		ld sumall = 0;
		ld sumgood = 0;
		for (int i = 0; i <= r; i++)
		{
			sumall += newt[r - i][i];
			if (i >= need)
			{
				sumgood += newt[r - i][i];
			}
		}
		printf("%.7Lf\n", sumgood / sumall);
	}
	return 0;
}
		
		
		
		
		
		