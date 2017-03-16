#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef pair<long long,int> PII;

int a[110000];
PII x[110000];

int T;
int X,n;

int casno=1;
int main() {
	scanf("%d",&T);
	while(T--){

		scanf("%d%d",&X,&n);
		printf("Case #%d: ",casno++);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(X==1) printf("%d\n",n);
		else{
			int ans=n;
			x[0]=PII(X,0);
			sort(a,a+n+1);
			for(int i=1;i<=n;i++) {
				int times=0;
				long long add=0;
				long long now=x[i-1].first;
				while(now<=a[i]){
					times++;
					add += now-1;
					now += now-1;
				}
				now+=a[i];
				x[i]=PII(now,x[i-1].second+times);
				ans=min(ans,x[i].second+n-i);
			}

			printf("%d\n",ans);
		}
	}
	return 0;
}
