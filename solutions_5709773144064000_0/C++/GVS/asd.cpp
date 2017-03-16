#include<iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <map>
#include <cmath>
using namespace std;

int i , j , n, m , k , t ;
double X , C , F;
int main()
{
	freopen("c:/input.txt" , "r" ,stdin);
	freopen("c:/output.txt" , "w" , stdout);

	cin>>t;
	for (int tt = 1; tt <= t; tt++)
	{
		cin>>C>>F>>X;

		double ans = X / 2;

		double curregen = 2;
		double timespent = 0;

		while (1)
		{
			timespent += C / curregen;
			curregen += F;
			if (timespent + X / curregen <= ans)
			{
				ans = timespent + X / curregen;
			} else
				break;
		}

		cout<<"Case #"<<tt<<": ";
		printf("%.7lf\n" , ans);

	}

	return 0;
}
