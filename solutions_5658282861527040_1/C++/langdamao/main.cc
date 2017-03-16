#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int T,a,b,k;
int main(){
	scanf("%d",&T);
	int ca=1;
	while(T--){
		scanf("%d%d%d",&a,&b,&k);
		int ret=0;
		for (int i=0;i<a;i++){
			for (int j=0;j<b;j++){
				if((i&j)<k)ret++;
			}
		}
		printf("Case #%d: %d\n",ca++,ret);
	}
	return 0;
}
