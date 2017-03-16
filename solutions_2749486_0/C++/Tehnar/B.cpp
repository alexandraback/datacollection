#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>


#define FNAME "1"
#define FILE 1

#define pb push_back
#define mp make_pair

using namespace std;

template <class T> void print(const T &a, int size)
{
	for (int i = 0; i < size; i++)
		cout << *a++ << " ";
	cout << endl;
};                  

int x, y, a, b, t;


int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d%d", &x, &y);
		a = b = 0;
		printf("Case #%d: ", q + 1);
		while (1)
		{
			if (a > x)
			{
			    a--;
				printf("EW");
			}
			else if (a < x)
			{
				printf("WE");
				a++;
			}
			if (b < y)
			{
				b++;
				printf("SN");
			}
			else if (b > y)
			{
				b--;
				printf("NS");
			}
			if (x == a && y == b)
				break;
		}
		puts("");
	}
}