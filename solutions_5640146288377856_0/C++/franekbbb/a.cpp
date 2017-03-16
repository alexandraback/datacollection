#include<bits/stdc++.h>
using namespace std;

main(){
	int test;scanf("%d",&test);
	for(int testnum=1;testnum<=test;testnum++){
		int r,c,k;scanf("%d%d%d",&r,&c,&k);
		int wyn=0;
		for(int i=1;i<=r;i++) wyn+=c/k;
		wyn+=k;
		if(c%k==0) wyn--;
		printf("Case #%d: %d\n",testnum,wyn);
	}
}
