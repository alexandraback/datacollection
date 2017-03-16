#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main()
{
	double *Naomi = new double[1010];
	double *Ken = new double[1010];
	int T,n;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> Naomi[i];
		for (int i = 0; i < n; i++)
			cin >> Ken[i];
		sort(Naomi, Naomi + n);
		sort(Ken, Ken + n);
		int optdeceit=0;
		for (int i = 0; i < n; i++)
		{
			if (Naomi[i]>Ken[optdeceit])
				optdeceit++;		
		}
		int optwar = 0;
		int klast = n - 1;
		for (int i = n - 1; i >= 0; i--)
		{
			if (Naomi[i] < Ken[klast])
				klast--;
			else
				optwar++;
		}
		printf("Case #%d: %d %d\n", tt, optdeceit, optwar);
	}
}