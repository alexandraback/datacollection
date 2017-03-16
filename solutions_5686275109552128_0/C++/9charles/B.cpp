#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define INF 1000000000

int T, D, p[1010], qnt[1010];

int main(){
	scanf("%d", &T);
	for(int caso=1; caso<=T; caso++){
		scanf("%d", &D);
		memset(qnt, 0, sizeof(qnt));
		for(int i=0; i<D; i++){
			scanf("%d", &p[i]);
			qnt[p[i]]++;
		}
		int respmin=INF, part=0;		
		for(int i=1000; i>=1; i--){
			respmin = min(respmin, i+part);
			qnt[(i+1)/2] += qnt[i];
			qnt[i/2] += qnt[i];
			part += qnt[i];
			qnt[i]=0;
		}
		printf("Case #%d: %d\n", caso, respmin);	
	}		
	return 0;
}

