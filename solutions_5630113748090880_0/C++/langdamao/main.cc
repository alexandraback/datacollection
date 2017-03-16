#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
int n;
bool  a[2500];
int main(){
	int T,ca=1;
	scanf("%d",&T);
	while(T--){
		int t;
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for (int i=0;i<n+n-1;i++){
			for (int j=0;j<n;j++){
				scanf("%d",&t);
				a[t]=!a[t];
			}
		}
		printf("Case #%d: ",ca++);
		for (int i=1;i<=2500;i++){
			if(a[i]) printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}
