#include <bits/stdc++.h>
using namespace std;
bool tab[11];
bool check()
{
	for(int i = 0; i < 10; ++i)
		if(tab[i] == false) return false;
	return true;
}
void dodaj(int x)
{
	while(x)
	{
		tab[x % 10] = true;
		x /= 10;
	}
}
int main()
{
	int T;
	int N;
	int Sum = 0;
	scanf("%d", &T);
	for(int i = 0; i < T; ++i)
	{
		Sum = 0;
		for(int i = 0; i < 10; ++i) tab[i] = false;
		
		
		scanf("%d", &N);
		printf("Case #%d: ", i+1);
		if(N == 0)
			puts("INSOMNIA");
		else
		{
			while(check() == false)
			{
				Sum += N;
				dodaj(Sum);
			}
			printf("%d\n", Sum);
		}
	}
	return 0;
	
}
