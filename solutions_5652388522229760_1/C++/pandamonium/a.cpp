#include <bits/stdc++.h>
using namespace std;
int t,n,used[10];
int main(){
	scanf("%d",&t);
	for(int c=1;c<=t;c++){
		printf("Case #%d: ",c);
		scanf("%d",&n);
		if(!n){printf("INSOMNIA\n");continue;}
		memset(used,0,sizeof(used));
		int done=0,cnt=0;
		for(int x=1;;x++){
			int k2=n*x,done=0;
			while(k2){
				if(!used[k2%10]){
					used[k2%10]=1;
					cnt++;
					if(cnt==10){
						printf("%d\n",n*x);
						done=1;
						break;
					}
				}
				k2/=10;
			}
			if(done) break;
		}
	}
	return 0;
}
