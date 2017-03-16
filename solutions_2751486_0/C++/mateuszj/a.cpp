//Mateusz Janczura
#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <set>
using namespace std;
set <pair<int, int> > zbior;
int main()
{
	int Z, li, wynik = 0, n, i, t[101], size, q, p;
	char tab[101];
	scanf("%d", &Z);
	for(li = 1; li <= Z; li++)
	{
		scanf("%s %d", tab, &n);
		t[0] = 0;
		size = strlen(tab);
		for(i = 0; i < size; i++)
		{
			if(tab[i] == 'a' || tab[i] == 'e' || tab[i] == 'i' || tab[i] == 'o'  || tab[i] == 'u') t[i + 1] = t[i]; 
			else t[i + 1] = t[i] + 1;
		}
		wynik = 0;
		for(i = n; i <= size; i++)
		{
			if(t[i] - t[i - n] >= n) 
			{
				//i-1, i-n
				for(p = i - 1; p < size; p++)
				{
					for(q = i - n; q >= 0; q--)
					{
						if(zbior.find(make_pair(q, p)) == zbior.end())
						{
							wynik++;
							zbior.insert(make_pair(q, p));
						}
					}
				}
			}
		}
		printf("Case #%d: %d\n", li, wynik);
		/*for(set<pair<int, int> >::iterator it = zbior.begin(); it != zbior.end(); it++)
		{
			printf("%d %d\n", it -> first, it -> second);
		}*/
		zbior.clear();
	}
	return 0;
}
