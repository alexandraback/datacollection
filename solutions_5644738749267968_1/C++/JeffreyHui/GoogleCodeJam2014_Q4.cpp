#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;
double naomi[1001],ken[1001];
int T,N,x,y,i,j,k;
int main (){
	freopen("D-large.in","r",stdin);
	freopen("GCJ14_Q_Q4_output.out","w",stdout);
	scanf("%d",&T);
	for (i=1;i<=T;i++){
		scanf("%d",&N);
		for (j=0;j<N;j++) scanf("%lf",&naomi[j]);
		for (j=0;j<N;j++) scanf("%lf",&ken[j]);
		sort(naomi,naomi+N);
		sort(ken,ken+N);
		x=0;
		y=0;
		j=0;
		k=0;
		while (j<N && k<N){
			if (naomi[j]>ken[k]) k++;
			j++;
		}
		x=k;
		j=0;
		k=0;
		while (j<N && k<N){
			if (naomi[j]<ken[k]) j++;
			k++;
		}
		y=N-j;
		printf("Case #%d: %d %d\n",i,x,y);
	}
	return 0;
}
