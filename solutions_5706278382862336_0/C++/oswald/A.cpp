#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long bigint;

int main(){
	bigint pow2[41];
	pow2[0]=1;
	for(int i=1; i<41; i++){
		pow2[i]=pow2[i-1]<<1;
	}
	// printf("%llu %llu\n", pow2[39], pow2[40]);
	int t;
	scanf("%i", &t);
	for(int tt=1; tt<=t; tt++){
		bigint p, q;
		scanf("%llu/%llu", &p, &q);
		bigint g=__gcd(p, q);
		p/=g; q/=g;
		int index=0;
		for(index=0; index<41; index++){
			if(pow2[index]==q){
				break;
			}
		}
		if(index==41){
			printf("Case #%i: impossible\n", tt);	
		}
		else{
			for(index=0; index<41; index++){
				if(p*pow2[index]>=q){
					break;
				}
			}
			printf("Case #%i: %i\n", tt, index);	
		}
		// printf("Case #%i: %i\n", tt, ans);
	}
}