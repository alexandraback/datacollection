#include <bits/stdc++.h>
using namespace std;
#define N 2000
#define msg(x) cout<<#x<<" = "<<x<<endl;
double va[N], vb[N];
bool flag[N];
int main() {
	int T, n;
	scanf("%d", &T);
	for(int caso=1 ; caso<=T ; caso++) {
		scanf("%d", &n);
		for(int i=0 ; i<n ; i++) scanf("%lf", &va[i]);
		for(int i=0 ; i<n ; i++) scanf("%lf", &vb[i]);
		sort(va, va+n);
		sort(vb, vb+n);
		/*
		for(int i=0 ; i<n ; i++) cout<<va[i]<<" ";
		cout<<endl;
		for(int i=0 ; i<n ; i++) cout<<vb[i]<<" ";
		cout<<endl;
		*/
		memset(flag, true, sizeof(flag));
		for(int i=0 ; i<n ; i++) {
			for(int k=0 ; k<n ; k++) {
				if( vb[k] > va[i] && flag[k] ) {
					flag[k] = false;
					break;
				}
			}
		}
		int ansB = 0;
		for(int i=0 ; i<n ; i++) if( flag[i] ) ansB++;

		memset(flag, true, sizeof(flag));
		int ansA = 0;
		for(int i=0 ; i<n ; i++) {
			for(int k=0 ; k<n ; k++) {
				if( va[k] > vb[i] && flag[k] ) {
					flag[k] = false;
					ansA++;
					break;
				}
			}
		}
		printf("Case #%d: %d %d\n", caso, ansA, ansB);
	}
    return 0;
}