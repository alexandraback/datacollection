#include<bits/stdc++.h>
using namespace std;
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int Tc , Nt = 0;
	scanf("%d",&Tc);
	while(Tc > 0){
		Nt++;
		int s , k , c;
		scanf("%d %d %d",&k,&c,&s);
		printf("Case #%d: ",Nt);
		for(int i = 1 ; i <= k ; i++)	printf("%d ",i);
		printf("\n");
		Tc--;
	}
}
