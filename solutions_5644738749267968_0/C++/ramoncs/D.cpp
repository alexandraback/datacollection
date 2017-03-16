#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int memo[1001][1001],n;
double naomi[1010],ken[1010];

int solve_small(int a1, int b1, int a2, int b2){
	if( a1==b1 )
		return (naomi[a1] > ken[a2]);
	if( naomi[b1] < ken[a2] )
		return 0;
	if( naomi[a1]>ken[b2] )
		return b1-a1+1;
	if(naomi[a1]>ken[a2])
		return solve_small(a1+1,b1,a2+1,b2)+1;
	return solve_small(a1+1,b1,a2,b2-1);
}

int main(){
	
	int war,dwar;
	bool used[1010];
	int n,t;
	scanf("%d",&t);
	for(int test=1; test<=t; test++){
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			scanf("%lf",&naomi[i]);
		for(int i=0; i<n; i++)
			scanf("%lf",&ken[i]);
		sort(naomi,naomi+n);
		sort(ken,ken+n);
		war=0;
		memset(used,false,sizeof used);
		for(int i=0; i<n; i++){
			bool ok = false;
			for(int j=0; j<n && !ok; j++){
				if(!used[j] && ken[j]>naomi[i]){
					used[j] = true;
					ok=true;
				}
			}
			if(!ok) war++;
		}
		dwar=solve_small(0,n-1,0,n-1);
		printf("Case #%d: %d %d\n",test,dwar,war);
	}
	return 0;
}