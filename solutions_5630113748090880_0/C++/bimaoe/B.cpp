#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;


int main (void) {
	int t;
	scanf ("%d", &t);
	for (int c = 1; c <= t; c++) {
		printf ("Case #%d: ", c);
		int n;
		scanf ("%d", &n);
		map<int, int> cnt;
		for (int i = 0; i < 2*n-1; i++) {
			for (int j = 0; j < n; j++) {
				int x;
				scanf ("%d", &x);
				cnt[x]++;
			}
		}
		map<int, int>::iterator it;
		for (it = cnt.begin(); it != cnt.end(); it++) {
			if (it->second & 1)	printf ("%d ", it->first);
		}
		printf ("\n");
	}
}