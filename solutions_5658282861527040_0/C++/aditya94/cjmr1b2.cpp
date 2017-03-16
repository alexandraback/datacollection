#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
	int T,a,b,k,num,tot;
	scanf("%d",&T);
	for(int s=1;s<=T;s++){
		tot=0;
		scanf("%d%d%d",&a,&b,&k);
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				num=i & j;
				if(num<k) tot++;
			}
		}
		printf("Case #%d: %d\n",s,tot);
	}
	return 0;
}