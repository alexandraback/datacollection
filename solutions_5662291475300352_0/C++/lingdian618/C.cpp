#include <stdio.h>
#include <algorithm>
#include <iostream>
typedef long long LL;
using namespace std;
const int N = 11;
LL d[N], h[N], m[N];
int main()
{
	// freopen("C-small-1-attempt1.in", "r", stdin);
	// freopen("ou.txt", "w", stdout);
	// freopen("in.txt", "r", stdin);
	int t, kase=0;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		for(int i=0; i<n; i++){
			cin >> d[i] >> h[i] >> m[i];
			// scanf("%d%d%d", &d[i], &h[i], &m[i]);
		}
		if(n==1 && h[0]==1){
			printf("Case #%d: 0\n", ++kase);
			continue;
		}
		LL d1, d2, m1, m2;
		if(n==1){
			d1 = d[0];
			d2 = d[0];
			m1 = m[0];
			m2 = m[0] + 1;
		}
		else{
			d1 = d[0];
			d2 = d[1];
			m1 = m[0];
			m2 = m[1];
		}
		if(m1>m2){
			swap(m1, m2);
			swap(d1, d2);
		}
		if(m2*(360-d2)<m1*(720-d1))	printf("Case #%d: 0\n", ++kase);
		else	printf("Case #%d: 1\n", ++kase);
	}
	return 0;
}