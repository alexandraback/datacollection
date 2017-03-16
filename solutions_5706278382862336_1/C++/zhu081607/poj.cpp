#include <stdio.h>
#include <string.h>
#include <stdlib.h>

__int64 gcd(__int64 a,__int64 b){
    return (b>0)?gcd(b,a%b):a;
}

int is2(__int64 a){
	__int64 t = 1; 
	for(int i=0; i<41; i++){
		if(t == a)return 1;
		t <<= 1;
//		printf("%I64d ", t);
	}
	return 0;
}

int main(){
	int t, i;
	__int64 p, q, qt;
	freopen("A-large.in", "r", stdin);
	freopen("test.txt", "w", stdout);
	scanf("%d", &t);
	for(i=0; i<t; i++){
		scanf("%I64d/%I64d", &p, &q);
		qt = gcd(p,q);
		p /= qt; q /= qt;
		if(0)printf("%I64d %I64d", p, q);
		qt = q;
		printf("Case #%d: ", i+1);
		if(is2(qt)){
			int j;
			for(j=0; j<40 && p<q; j++){
				q >>= 1;				
			}
			printf("%d\n", j);
		}else{
			printf("impossible\n");
		}
	
	}
	return 0;
}
