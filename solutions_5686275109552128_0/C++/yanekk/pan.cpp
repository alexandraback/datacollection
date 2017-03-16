#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5;

int T[N];

int main(){
	int t,i,j,n,wyn,k,ile;
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%d", &n);
		for(j=0; j<n; j++){
			scanf("%d", &T[j]);
		}
		wyn = 1e9;
		for(j=1; j<=1000; j++){
			ile = 0;
			for(k=0; k<n; k++){
				if(j == 1) ile += T[k]-1;
				if(j!=1 && j < T[k]) ile += ((T[k]+j-1)/j)-1;
			}
			//if(j<=4) printf("%d %d\n", j,ile);
			wyn = min(j+ile,wyn);
		}
		printf("Case #%d: %d\n", i+1,wyn);
	}
	return 0;
}

