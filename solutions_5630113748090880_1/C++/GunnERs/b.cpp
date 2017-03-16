#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[3000];
int n;

int main()
{
	freopen("B-large.in","r",stdin);
	freopen("large.out","w",stdout);
	
	int task; scanf("%d", &task);
	for (int cs=1; cs<=task; cs++){
		scanf("%d", &n);
		memset(a, 0, sizeof(a));
		int aa=100000, bb = -100000;
		for (int i=0; i<n*2-1; i++){
			for (int j=0; j<n; j++){
				int x;
				scanf("%d", &x);
				a[x]++;
				if (x<aa) aa = x;
				if (x>bb) bb = x;
			}
		}

		printf("Case #%d:", cs);
		for (int i=aa; i<=bb; i++)
		if (a[i]&1) printf(" %d", i);
		printf("\n");
	}	
	return 0;
}
