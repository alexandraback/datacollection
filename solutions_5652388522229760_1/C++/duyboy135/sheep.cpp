#include<bits/stdc++.h>
using namespace std;
int mask = 0;
void process(int x){
	while(x > 0){
		mask |= 1<<(x % 10);
		x /= 10;
	}
}
main(){
	freopen("test.inp","r",stdin);
	freopen("test.out","w",stdout);
	int Tc , nT = 0;
	scanf("%d",&Tc);
	while(Tc > 0){
		nT++;
		int x;
		scanf("%d",&x);
		printf("Case #%d: ",nT);
		if(x == 0){
			printf("INSOMNIA\n");
			Tc--;
			continue;
		}
		int mul = 1;
		mask = 0;
		while(true){
			process(x * mul);
			if(mask == ( (1<<10) - 1)) break;
			mul++;
		}
		printf("%d\n",mul*x);
		Tc--;
	}
}

