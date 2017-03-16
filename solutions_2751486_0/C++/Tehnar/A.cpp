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

char s[10000001];
int n, t, len, pos, a[10000001];
long long k, ans;

int main()
{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d\n", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%s", s);
		//puts(s);
		scanf("%d\n", &n);
		//printf("%d\n", n);
		len = strlen(s);
		ans = 0;
		pos = 0;
		k = 0;
		int x = 0;               
		if (s[0] != 'e' && s[0] != 'a' && s[0] != 'i' && s[0] != 'o' && s[0] != 'u')
					x++;
	
		pos = 0;
		for (int i = 0; i < len; i++)
		{
			if (pos - i + 1 < n && x >= n)
				x--;
			while (pos < len && x < n)
			{
		        pos++;
				if (s[pos] != 'e' && s[pos] != 'a' && s[pos] != 'i' && s[pos] != 'o' && s[pos] != 'u')
					x++;
		        else
		        	x = 0;
			}        
			if (x >= n)
			{
		        //printf("%d %d %d\n", i + 1, pos + 1, len - pos);
				ans += len - pos;
	    	}
		}
		printf("Case #%d: %I64d\n", q + 1, ans);
		
	}	
}