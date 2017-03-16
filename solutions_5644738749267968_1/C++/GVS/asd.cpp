#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int i , j , n, m , k , t ;
double a[10000] , b[10000];
int u[10000];
int main()
{
	freopen("c:/input.txt" , "r" ,stdin);
	freopen("c:/output.txt" , "w" , stdout);

	cin>>t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>n;
		for (i = 0; i < n; i++)
			cin>>a[i];

		for (i = 0 ;i < n; i++)
			cin>>b[i];

		for (i = 0; i < n; i++)
			u[i] = 0;

		sort(a , a + n);
		sort(b , b + n);

		int ans1 = 0 , ans2 = 0;

		for (i = 0; i < n ; i++)
		{
			double mn = 1000;
			int nom = -1;
			for (j = 0; j < n; j++)
			{
				if (!u[j] && b[j] > a[i] && b[j] < mn)
				{
					mn = b[j];
					nom = j;
				}
			}

			if (nom == -1)
			{
				ans2++;
				for (j = 0; !u[j]; j++);

				u[j] = 1;
			}
			else
				u[nom] = 1;
		}

		for (i = 0; i < n; i++)
			u[i] = 0;

		for (i = 0; i < n ; i++)
		{
			double mn = 1000;
			int nom = -1;
			for (j = 0; j < n; j++)
			{
				if (!u[j] && a[j] >b[i] && a[j] < mn)
				{
					mn = a[j];
					nom = j;
				}
			}

			if (nom == -1)
			{
				ans1++;
				for (j = 0; !u[j]; j++);

				u[j] = 1;
			}
			else
				u[nom] = 1;
		}

		cout<<"Case #"<<tt<<": "<<n - ans1<<" "<<ans2<<endl;

		

	}

	return 0;
}
