#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
main(){
	int test;scanf("%d",&test);
	for(int tn=1;tn<=test;tn++){
		int d;LL c,v;
		scanf("%lld%d%lld",&c,&d,&v);
		vector<LL> den;
		for(int i=1;i<=d;i++){
			LL a;scanf("%lld",&a);
			den.push_back(a);
		}
		den.push_back(v+10);
		sort(den.begin(),den.end());
		reverse(den.begin(),den.end());
		int wyn=0;
		LL suma=0;
		while(suma<v){
			//printf("spr %lld::",suma);
			if(den.back()<=suma+1){
				//printf("A %lld\n",den.back());
				suma+=den.back()*c;
				den.pop_back();
				continue;
			}
			//puts("B");
			wyn++;
			suma+=(suma+1)*c;
		}
		printf("Case #%d: %d\n",tn,wyn);
	}
}
