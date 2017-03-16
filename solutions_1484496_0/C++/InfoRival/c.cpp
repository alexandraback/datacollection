#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int c=32;
const int cc=2000500;
int a[cc];
int t,ii;
int n;
int nn;
int m[c];
void get(int i) {
	int j;
	for (j=0; j<n; ++j) if ((i>>j)&1) printf("%d ",m[j]);
	printf("\n");
}
int main() {
	scanf("%d",&t);
	int i,j,s;
	for (ii=1; ii<=t; ++ii) {
		printf("Case #%d:\n",ii);
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for (i=0; i<n; ++i) scanf("%d",&m[i]);
		nn=(1<<n);
		for (i=1; i<nn; ++i) {
			s=0;
			for (j=0; j<n; ++j) if ((i>>j)&1) s+=m[j];
			if (a[s]>0) {
				get(a[s]);
				get(i);
				break;
			} else a[s]=i;
		}
		if (i==nn) printf("Impossible\n");
	}
	return 0;
}
