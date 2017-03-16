#include <iostream>
#include <cstdio>

#define ld long double
using namespace std;

int debug=0;
int m;
int val[300];
void doit() {
	scanf("%d", &m);
	for(int j=0;j<m;j++)scanf("%d",&val[j]);
	int X = 0;
	for(int j=0;j<m;j++)X+=val[j];

	for(int j=0;j<m;j++) {
		ld le = X; ld ri = X;
		for(int k=0;k<m;k++)if(k!=j)le=min(le,(ld)val[k]);

		ld lastpr = 0;
		for(int iter=0;iter<=200;iter++) {
			ld mid=(le+ri)/2;
			ld votes = 0;
			for (int k=0;k<m;k++) if (k!=j){
				ld rem = mid - val[k];
				if (rem >= 0) {
					votes += rem/X;
				}
			}
			lastpr = 1-votes;
			if (val[j] + X*(1-votes) <= mid)
				ri = mid;
			else
				le = mid;
		}
		if (debug)cerr<<le<<" "<<ri<<" "<<endl;
		printf(" %.6LF", max((ld)0,lastpr)*100);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Case #%d:", i+1);
		doit();
		printf("\n");
	}
	return 0;
}
