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

struct st
{
	int d, w, len, s;
};

bool operator < (st a, st b)
{
	return a.d < b.d;
}

int k, pos, ans, pos1, wall[10000], t, n, d, m, w, e, s, dd, dp, ds;
st event[1000000];

int get(int w, int e)
{                                                                      /*
	if (w == 300 && e == 305)
	{
		for (int i = 2 * w; i <= 2 * e; i++)
			printf("%d ", wall[i]);
		puts("");
	}                                                                */
	w *= 2;
	e *= 2;
	int a = wall[w];
	for (int i = w; i <= e; i++)
		a = min(a, wall[i]);
	return a;
}

void update(int w, int e, int s)
{
	w *= 2;
	e *= 2;
	for (int i = w; i <= e; i++)
		wall[i] = max(wall[i], s);
}
int main()

{
	#if (FILE == 1)
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	#endif
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		for (int i = 0; i < 3000; i++)
			wall[i] = 0;
		k = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d%d%d", &d, &m, &w, &e, &s, &dd, &dp, &ds);
			w += 300;
			e += 300;
			for (int j = 0; j  < m; j++)
			{
				event[k].d = d;
				event[k].w = w;
				event[k].len = e - w;
				event[k].s = s;
				s += ds;
				d += dd;
				w += dp;
				e += dp;
				k++;
			}

		}
	
		sort(event, event + k);
		pos = 0;
		ans = 0;
		while (pos < k)
		{
			pos1 = pos;
			while (pos < k && event[pos].d == event[pos + 1].d)
			{
				if (get(event[pos].w, event[pos].w + event[pos].len) >= event[pos].s)
					ans++;
				pos++;
			}
			if (pos != k)
			{
		   		if (get(event[pos].w, event[pos].w + event[pos].len) >= event[pos].s)
				{
					//printf("%d %d %d %d %d\n", event[pos].d, event[pos].w - 300, event[pos].w + event[pos].len - 300, get(event[pos].w, event[pos].w + event[pos].len), event[pos].s);
				    ans++;
				}   
					
			}
			if (pos == k)
				pos--;
			for (int i = pos1; i <= pos; i++)
				update(event[i].w, event[i].w + event[i].len, event[i].s);
	    	pos++;
		}	
		printf("Case #%d: %d\n", q + 1, k - ans);
	}
}
