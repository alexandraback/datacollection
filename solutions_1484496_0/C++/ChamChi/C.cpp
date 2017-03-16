#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cfloat>
#include <sstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int a[22],n;

inline int get_sum (int set){
	int sum = 0;
	for (int i = 0; i < n; i ++)
		if (set & (1<<i)) sum += a[i];
	return sum;
}

int
main ()
{
	freopen ("Cs.in","r",stdin);
	freopen ("Cs.out","w",stdout);
	int t;
	scanf ("%d", &t);
	for (int tc = 1; tc <= t; tc ++){
		scanf ("%d", &n);
		for (int i = 0; i < n; i ++)
			scanf ("%d", &a[i]);

		printf ("Case #%d:\n", tc);
		for (int set1 = 1; set1 < 1<<n; set1 ++){
			int mask = ((1<<n)-1) ^ set1;
			int sum1 = get_sum (set1);
			for (int set2 = ((1<<n)-1) ^ set2; set2 ; set2 = (set2 - 1) & mask){
				int sum2 = get_sum (set2);
				if (sum1 == sum2){
					for (int i = 0; i < n; i ++)
						if (set1 & (1<<i)) printf ("%d ", a[i]);
					puts ("");
					for (int i = 0; i < n; i ++)
						if (set2 & (1<<i)) printf ("%d ", a[i]);
					puts ("");
					goto found;
				}
			}
		}
		if (1)
			printf ("Impossible\n");
		else
found:		;
	}
	return 0;
}