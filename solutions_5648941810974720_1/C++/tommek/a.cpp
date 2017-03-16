#include <bits/stdc++.h>
using namespace std;

const int MX = 1e6 + 5;

int dig[MX], ile[MX];
char a[MX];
int n;


void usun(string x)
{
	//cout << x << endl;
	for (auto z: x)
	{
		dig[z] --;
	}
}

void Solve()
{
	scanf("%s", a);
	n = strlen(a);
	
	for (int i = 0; i < MX; ++ i)
	{
		ile[i] = 0;
		dig[i] = 0;
	}
	
	for (int i = 0; i < n; ++ i)
	{
		dig[(int)a[i]] ++;
	}
	
	while (n)
	{
		if (dig['Z'] > 0)
		{
			usun("ZERO");
			ile[0] ++;
			continue;
		}
		if (dig['G'] > 0)
		{
			usun("EIGHT");
			ile[8] ++;
			continue;
		}
		if (dig['X'] > 0)
		{
			usun("SIX");
			ile[6] ++;
			continue;
		}
		if (dig['S'] > 0)
		{
			usun("SEVEN");
			ile[7] ++;
			continue;
		}
		if (dig['U'] > 0)
		{
			usun("FOUR");
			ile[4] ++;
			continue;
		}
		if (dig['F'] > 0)
		{
			usun("FIVE");
			ile[5] ++;
			continue;
		}
		if (dig['R'] > 0)
		{
			usun("THREE");
			ile[3] ++;
			continue;
		}
		if (dig['T'] > 0)
		{
			usun("TWO");
			ile[2] ++;
			continue;
		}
		if (dig['O'] > 0)
		{
			usun("ONE");
			ile[1] ++;
			continue;
		}
		if (dig['N'] > 0)
		{
			usun("NINE");
			ile[9] ++;
			continue;
		}
		break;
	}
	
	for (int i = 0; i < 26; ++ i){
		for (int j = 0; j < ile[i]; ++ j){
			printf("%d", i);
		}
	}
	
	puts("");
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
