#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main (void) {
	int T,c,n,sum[200], i, x, qt, qtn;
	double y[200];
	scanf ("%d", &T);
	for (c = 1; c <= T; c++) {
		vector <pair<int,int> > s;
		scanf ("%d", &n);
		for (i = 0; i < n; i++) {
			scanf ("%d", &x);
			s.push_back(pair<int,int> (x,i));
		}
		sort (s.begin(), s.end());
		sum[0] = s[0].first;
		for (i = 1; i < n; i++) {
			sum[i] = s[i].first+sum[i-1];
		}
		printf ("Case #%d:",c);
		qt = n;
		qtn = 1;
		while (qtn) {
			if (sum[qt-1] > 0) {
				for (i = 0; i < qt; i++)
					y[s[i].second] = (sum[n-1]+sum[qt-1]-qt*s[i].first)/(double)(qt*sum[n-1]);
			} else {
				for (i = 0; i < qt; i++)
					y[s[i].second] = 1.0/qt;
			}
/*			for (i = 0; i < n; i++)
				printf (" %.5lf", 100*y[i]);
			printf ("\n");*/
			for (qtn = i = 0; i < qt; i++)
				if (y[s[i].second] < 0)	{
					y[s[i].second] = 0;
					qtn++;
				}
			qt -= qtn;
		}
		for (i = 0; i < n; i++)
			printf (" %lf", 100*y[i]);
		printf ("\n");
	}
	return 0;
}
