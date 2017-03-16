#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
	int a,b,c;
	int t;
	scanf("%d",&t);
	for(int j=1;j<=t;j++){
		scanf("%d%d%d",&a,&b,&c);
		int count=0;
		for(int i=0;i<a;i++){
			for(int j=0;j<b;j++){
				int k =i&j;
				if(k<c)
					count++;
			}
		}
		printf("Case #%d: %d\n",j,count);
	}
	return 0;
}
