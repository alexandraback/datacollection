#include <cstdio>
#include <list>
#include <iostream>

#pragma warning(disable:4996)

using namespace std;

int t,n,tmp;


int main() {
	freopen("input.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d", &n);

		int rpt = ((2 * n) - 1)*n;
		int cnt[2501] = { 0 };
		
		for (int z = 0; z < rpt; z++) {
			scanf("%d", &tmp);
			if (cnt[tmp] == 0) {
				cnt[tmp] = 1;
			}
			else cnt[tmp] = 0;
		}
		printf("Case #%d: ",i);
		for (int z = 1; z <= 2500;z++)
		{
			if (cnt[z] == 1) printf("%d ", z);
		}
		printf("\n");
	}
	return 0;
}
