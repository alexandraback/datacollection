#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <queue>

using namespace std;

long long int powten[17];

bool palindrome(long long int x)
{
	int digit[17];
	int size = 0;
	int i;
	long long int y = x;
	while(y > 0)
	{
		digit[size] = y % 10;
		y /= 10;
		size++;
	}
	for(i = 0; i < size/2; i++)
	{
		if(digit[i] != digit[size-1-i]) return false;
	}
	return true;
}

int taille(long long int x)
{
	long long int y = x;
	int rep = 0;
	while(y > 0)
	{
		y /= 10;
		rep++;
	}
	return rep;
}

long long int mypow(int a, int b)
{
	long long int res = 1;
	int i;
	for(i = 0; i < b; i++) res *= a;
	return res;
}


long long int palless(long long int X)
{
	int x = taille(X);
	int jusque = (x+1)/2;
	int nb, fixer;
	int i, a, b, j, c, chiff;
	long long int pal;
	
	long long int res = 0;
	
	if(x == 0) return 0;
	
	for(nb = 1; nb <= jusque; nb++)
	{
		// nb = 1 -> fixer 1
		// nb = 2 -> fixer 1
		// nb = 3 -> fixer 2
		fixer = (nb+1)/2;
		a = powten[fixer-1];
		b = powten[fixer];
		for(i = a; i < b; i++)
		{
			c = i;
			pal = 0;
			for(j = 0; j < fixer; j++)
			{
				chiff = c / powten[fixer-1-j];
				c -= chiff*powten[fixer-1-j];
				pal += powten[nb-1-j] * chiff;
				if(nb-1-j != j) pal += powten[j] * chiff;
			}
			
			if(pal*pal <= X && palindrome(pal*pal)) res++;
		}
	}
	return res;
}

int main()
{
	int i, j, T, t;
	long long int A, B, a, b;
	
	for(i = 0; i < 17; i++)
	{
		powten[i] = mypow(10, i);
	}
	
	scanf("%d", &T);
	
	for(t = 1; t <= T; t++)
	{
		printf("Case #%d: ", t);
		scanf("%lld %lld", &A, &B);
		printf("%lld\n", palless(B) - palless(A-1));
	}

	return 0;
}
