#include <bits/stdc++.h>

using namespace std;

int paridad[2500];

int main(){
	int t;
	scanf("%d",&t);
	int casos=1;
	while (t--){
		int n;
		int m;
		printf("Case #%d: ",casos++);
		scanf("%d",&n);
		memset(paridad,0,sizeof(paridad));
		m=n;
		n=2*n;
	
		for (int i=0;i<n-1;++i){
			int x;
			for (int j=0;j<m;++j){
				scanf("%d",&x);

				paridad[x]++;
			}

		}
		
			int cont=0;
			for (int j=1;j<=2500;++j){
				if (paridad[j]%2!=0){
					cont++;
					printf("%d%s",j,(cont==m) ? "\n" : " ");
				}
			}
		
		
	}
	return 0;
}
