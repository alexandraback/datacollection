//Przemysław Jakub Kozłowski
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 103;

int t;
int rozmiar, n;
int tab[N];

int main()
{
	scanf("%d", &t);

	for(int ti = 1;ti <= t;ti++)
	{
		scanf("%d%d", &rozmiar, &n);

		for(int i = 1;i <= n;i++)
			scanf("%d", &tab[i]);

		sort(tab+1,tab+n+1);

		int wyn = n;

		if(rozmiar != 1)
			for(int i = 1, twyn = 0;i <= n;i++)
			{
				while(rozmiar <= tab[i])
				{
					rozmiar += (rozmiar-1);
					twyn++;
				}
				rozmiar += tab[i];
				wyn = min(wyn, twyn+n-i);
			}

		printf("Case #%d: %d\n", ti, wyn);
	}
	return 0;
}
