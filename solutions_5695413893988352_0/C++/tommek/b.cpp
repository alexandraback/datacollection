#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;

string c, j, cp, jp;
int n;

pair<long long int, pair<string, string> > Wyniczek;

void Solve()
{
	cin >> c >> j;
	n = (int) c.size();

	bool czyRowne = true;
	for (int i = 0; i < n; ++ i)
	{
		if (c[i] != '?' && j[i] != '?' && c[i] != j[i])
		{
			czyRowne = false;
		}
	}
	
	Wyniczek = make_pair(-1, make_pair("", ""));
	
	if (czyRowne)
	{
		for (int i = 0; i <n; ++ i)
		{
			if (c[i] != '?')
			{
				j[i] = c[i];
			}
			if (j[i] != '?')
			{
				c[i] = j[i];
			}
			if (c[i] == '?')
			{
				c[i] = j[i] = '0';
			}
		}
		cout << c << " " << j << endl;
		return;
	}
	
	for (int d = 0; d < n; ++ d)
	{
		bool czySieDa = true;
		
		cp = c; jp = j;
			
		/* sprawdzanie gory */
				
		for (int i = 0; i < d; ++ i)
		{
			if (cp[i] != '?' && jp[i] != '?')
			{
				if (cp[i] != jp[i])
				{
					czySieDa = false;
				}
			}
			else
			{
				if (cp[i] == '?' && jp[i] == '?')
				{
					cp[i] = jp[i] = '0';
				}
				if (cp[i] == '?')
				{
					cp[i] = jp[i];
				}
				if (jp[i] == '?')
				{
					jp[i] = cp[i];
				}
			}
		}
	
		if (!czySieDa)
		{
			continue;		
		}
	
		/* sprawdzanie srodka */
		
		if (cp[d] == '?')
		{
			if (jp[d] != '?')
			{
				if (jp[d] == '0')
				{
					cp[d] = '1';
				}
				else
				{
					cp[d] = jp[d] - 1;
				}
			}
			else
			{
				cp[d] = '0';
				jp[d] = '1';
			}
		}
		
		if (jp[d] == '?')
		{
			if (cp[d] == '0')
			{
				jp[d] = '1';
			}
			else
			{
				jp[d] = cp[d] - 1;
			}
		}
	
		/* sprawdzanie dolu */
	
		bool kto = 1;
		if (cp[d] > jp[d])
		{
			kto = 0;
		}	
		else
		{
			kto = 1;
		}
		for (int i = d+1; i < n; ++ i)
		{
			if (cp[i] == '?')
			{
				if (kto == 1)
				{
					cp[i] = '9';
				}
				else
				{
					cp[i] = '0';
				}
			}
			if (jp[i] == '?')
			{
				if (kto == 1)
				{
					jp[i] = '0';
				}
				else
				{
					jp[i] = '9';
				}
			}
		}
		
		/* sprawdzic */
		
		long long liczba1 = 0, liczba2 = 0, pot = 1;
		for (int i = n-1; i >= 0; -- i)
		{
			liczba1 += (cp[i] - '0') * pot;
			liczba2 += (jp[i] - '0') * pot;
			pot  *= 10LL;
		}
		
		if (Wyniczek.first == -1)
		{
			Wyniczek = make_pair(abs(liczba1 - liczba2), make_pair(cp, jp));
		}
		else
		{
			Wyniczek = min(Wyniczek, make_pair(abs(liczba1 - liczba2), make_pair(cp, jp)));
		}
	}
	
	for (int d = 0; d < n; ++ d)
	{
		bool czySieDa = true;
		
		cp = c; jp = j;
			
		/* sprawdzanie gory */
				
		for (int i = 0; i < d; ++ i)
		{
			if (cp[i] != '?' && jp[i] != '?')
			{
				if (cp[i] != jp[i])
				{
					czySieDa = false;
				}
			}
			else
			{
				if (cp[i] == '?' && jp[i] == '?')
				{
					cp[i] = jp[i] = '0';
				}
				if (cp[i] == '?')
				{
					cp[i] = jp[i];
				}
				if (jp[i] == '?')
				{
					jp[i] = cp[i];
				}
			}
		}
	
		if (!czySieDa)
		{
			continue;		
		}
	
		/* sprawdzanie srodka */
		
		if (cp[d] == '?')
		{
			if (jp[d] != '?')
			{
				if (jp[d] == '9')
				{
					cp[d] = '8';
				}
				else
				{
					cp[d] = jp[d] + 1;
				}
			}
			else
			{
				cp[d] = '1';
				jp[d] = '0';
			}
		}
		
		if (jp[d] == '?')
		{
			if (cp[d] == '9')
			{
				jp[d] = '8';
			}
			else
			{
				jp[d] = cp[d] + 1;
			}
		}
	
		/* sprawdzanie dolu */
	
		bool kto = 1;
		if (cp[d] > jp[d])
		{
			kto = 0;
		}	
		else
		{
			kto = 1;
		}
		for (int i = d+1; i < n; ++ i)
		{
			if (cp[i] == '?')
			{
				if (kto == 1)
				{
					cp[i] = '9';
				}
				else
				{
					cp[i] = '0';
				}
			}
			if (jp[i] == '?')
			{
				if (kto == 1)
				{
					jp[i] = '0';
				}
				else
				{
					jp[i] = '9';
				}
			}
		}
		
		/* sprawdzic */
		
		long long liczba1 = 0, liczba2 = 0, pot = 1;
		for (int i = n-1; i >= 0; -- i)
		{
			liczba1 += (cp[i] - '0') * pot;
			liczba2 += (jp[i] - '0') * pot;
			pot  *= 10LL;
		}
		
		if (Wyniczek.first == -1)
		{
			Wyniczek = make_pair(abs(liczba1 - liczba2), make_pair(cp, jp));
		}
		else
		{
			Wyniczek = min(Wyniczek, make_pair(abs(liczba1 - liczba2), make_pair(cp, jp)));
		}
	}
		
	cout << Wyniczek.second.first << " " << Wyniczek.second.second << endl;
}

int main()
{
	int __test; scanf("%d", &__test); 
	for (int __i = 1; __i <= __test; ++ __i)
	{
		printf("Case #%d: ", __i);
		Solve();
	}
	return 0;
}
